#!/usr/bin/python3

import sys
import os
import shutil
import subprocess
from subprocess import DEVNULL, STDOUT, PIPE
import re
import matplotlib.pyplot as plt

class VNC:
    _services = ["xvfb", "x11vnc", "novnc"]

    def start(self):
        for service in self._services:
            subprocess.check_call(['service', service, 'start'], stdout=DEVNULL, stderr=STDOUT)
    
    def stop(self):
        for service in reversed(self._services):
            subprocess.call(['service', service, 'stop'], stdout=DEVNULL, stderr=STDOUT)
            if service == "x11vnc":
                os.system('pkill x11vnc')
            elif service == 'xvfb':
                os.system('pkill Xvfb')
            elif service == 'novnc':
                os.system('pkill websockify')

    def restart(self):
        self.stop()
        self.start()

class Runner:
    BUILD_DIR = "/home/workspace/.stm32f407vg/build"

    def _simulate(self, firmware, graphics = True, captureOutput = None):
        command = [
            '/root/opt/xPacks/@xpack-dev-tools/qemu-arm/2.8.0-8.1/.content/bin/qemu-system-gnuarmeclipse',
            '--verbose',
            '--verbose',
            '--board', 'STM32F4-Discovery',
            '--mcu', 'STM32F407VG',
            '-d', 'unimp,guest_errors',
            '--semihosting-config', 'enable=on,target=native',
            '--image', firmware,
        ]
        if not graphics:
            command += ['--nographic']
        if captureOutput:
            return subprocess.run(command, stdout=PIPE, stderr=DEVNULL).stdout
        else:
            subprocess.call(command)

    def _build(self, src):
        if os.path.exists(self.BUILD_DIR):
            shutil.rmtree(self.BUILD_DIR)
        os.mkdir(self.BUILD_DIR)
        os.chdir(self.BUILD_DIR)
        os.system("cmake .. -DSOURCE_FILE=\"{}\" -GNinja".format(src))
        os.system("ninja")

    def _run_lab(self, src):
        self._build(src)
        self._simulate("{}/lab.elf".format(self.BUILD_DIR))

    def _lab3(self):
        self._build("/home/workspace/Labs/3. BitBang SPI/part2.c")
        output = self._simulate("{}/lab.elf".format(self.BUILD_DIR), False, True).decode('utf-8')
        output = output.split("Cortex-M4 r0p0 core reset.\n\n")
        if len(output) > 0:
            output = output[1].split("\n\nQEMU semihosting exit(1)\n")[0]
            data = re.findall(r'\[led:(.*)\]', output, re.MULTILINE)

            orange_on_ids = [i for i,x in enumerate(data) if x=='orange on']
            orange_off_ids = [i for i,x in enumerate(data) if x=='orange off']
            
            if len(orange_on_ids) < 1:
                print("ERROR: Slave Line never made idle")
                return
            
            if len(orange_on_ids) < 2:
                if len(orange_off_ids) < 1 or orange_on_ids[0] > orange_off_ids[0]:
                    print("ERROR: Slave Line not idle before transmission")
                    return
                else:
                    print("ERROR: Slave Line not idle after transmission")
                    return

            # Extracting signals transmitted while slave was selected
            data = data[(orange_off_ids[0]+1):orange_on_ids[1]]

            # print(data)
            signals = [{'clk': 0, 'mosi': 0}]
            next_signal = signals[-1].copy()
            time = [0]
            clk = [1.25]
            mosi = [0]
            for signal in data:
                if signal == 'green on':
                    if signals[-1]['clk'] == 0:
                        # rising edge detected
                        signals += [next_signal.copy()]
                    else:
                        # clock goes on
                        signals += [signals[-1].copy()]
                    signals[-1]['clk'] = 1
                elif signal == 'green off':
                    signals += [signals[-1].copy()]
                    signals[-1]['clk'] = 0
                elif signal == 'blue on':
                    next_signal['mosi'] = 1
                elif signal == 'blue off':
                    next_signal['mosi'] = 0
                
                if signal == 'green on' or signal == 'green off':
                    for i in range(0,10):
                        time += [time[-1]+1]
                        clk += [1.25 + signals[-1]['clk']]
                        mosi += [signals[-1]['mosi']]
            # Plot the data in reverse to mimic a scope
            clk.reverse()
            mosi.reverse()

            plt.plot(time, clk, 'green')
            plt.plot(time, mosi, 'blue')
            plt.yticks([])
            plt.xlabel("Time")
            plt.ylabel("MOSI                             SCLK")
            plt.savefig("/home/workspace/Labs/3. BitBang SPI/output.png")
        else:
            print("ERROR: Invalid simulator output")
        
    def _lab5(self, part):
        self._build("/home/workspace/Labs/5. FSM/part{}.c".format(part))
        output = self._simulate("{}/lab.elf".format(self.BUILD_DIR), False, True).decode('utf-8')
        output = output.split("Cortex-M4 r0p0 core reset.\n\n")
        if len(output) > 0:
            output = output[1].split("\n\nQEMU semihosting exit(1)\n")[0]
            data = re.findall(r'\[(led:.*|tick)\]', output, re.MULTILINE)
            time = [0]
            green = [0]
            orange = [0]
            red = [0]
            blue = [0]
            last_green = 0
            last_orange = 0
            last_red = 0
            last_blue = 0
            # print(data)
            for dat in data:
                if dat == 'tick':
                    for i in range(0,5):
                        time += [time[-1]+1]
                        green += [last_green]
                        orange += [last_orange]
                        red += [last_red]
                        blue += [last_blue]
                elif dat == 'led:green on':
                    last_green = 1
                elif dat == 'led:green off':
                    last_green = 0
                elif dat == 'led:orange on':
                    last_orange = 1
                elif dat == 'led:orange off':
                    last_orange = 0
                elif dat == 'led:red on':
                    last_red = 1
                elif dat == 'led:red off':
                    last_red = 0
                elif dat == 'led:blue on':
                    last_blue = 1
                elif dat == 'led:blue off':
                    last_blue = 0

            # Plot the data in reverse to mimic a scope
            green = [3.75 + x for x in green]
            orange = [2.50 + x for x in orange]
            red = [1.25 + x for x in red]
            blue = [x for x in blue]

            plt.plot(time, green, 'green')
            plt.plot(time, orange, 'orange')
            plt.plot(time, red, 'red')
            plt.plot(time, blue, 'blue')
            plt.yticks([])
            plt.xlabel("Time")
            plt.ylabel("LED Signals")
            plt.savefig("/home/workspace/Labs/5. FSM/part{}.png".format(part))
            
    def run(self, lab):
        if lab == "Lab_1_Part_1":
            self._simulate('/home/workspace/Labs/1. Introduction/part1.elf')
        elif lab == "Lab_1_Part_2":
            self._run_lab("/home/workspace/Labs/1. Introduction/part2.c")
        elif lab == "Lab_1_Part_3":
            self._run_lab("/home/workspace/Labs/1. Introduction/part3.c")
        elif lab == "Lab_2_Part_1":
            self._run_lab("/home/workspace/Labs/2. Interrupts/part1.c")
        elif lab == "Lab_2_Part_2":
            self._run_lab("/home/workspace/Labs/2. Interrupts/part2.c")
        elif lab == "Lab_3":
            self._lab3()
        elif lab == "Lab_4":
            self._run_lab("/home/workspace/Labs/4. SPI Based Driver/adt7320.c;/home/workspace/Labs/4. SPI Based Driver/spi.o")
        elif lab == "Lab_5_Part_1":
            self._lab5(1)
        elif lab == "Lab_5_Part_2":
            self._lab5(2)
        elif lab == "Lab_5_Part_3":
            self._lab5(3)
        else:
            print("Invalid lab selected")

if __name__ == "__main__":
    (VNC()).restart()
    (Runner()).run(sys.argv[1])