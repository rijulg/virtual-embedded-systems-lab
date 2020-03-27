#!/usr/bin/python3

import sys
import os
import shutil
from subprocess import DEVNULL, STDOUT, check_call, CalledProcessError

class VNC:
    _services = ["xvfb", "x11vnc", "novnc"]

    def _already_running(self, service):
        running = False
        pidPath = "/var/run/{}.pid".format(service)
        if os.path.isfile(pidPath):
            with open(pidPath, 'r') as pidFile:
                try:
                    check_call(['ps -p', pidFile.read()], stdout=DEVNULL, stderr=STDOUT, shell=True)
                except CalledProcessError as err:
                    running = err.returncode == 0
        return running

    def start(self):
        for service in self._services:
            if not self._already_running(service):
                check_call(['service', service, 'start'], stdout=DEVNULL, stderr=STDOUT)
    
    def stop(self):
        for service in reversed(self._services):
            check_call(['service', service, 'stop'], stdout=DEVNULL, stderr=STDOUT)

class Runner:
    BUILD_DIR = "/home/workspace/.stm32f407vg/build"

    def _simulate(self, firmware):
        check_call([
            '/root/opt/xPacks/@xpack-dev-tools/qemu-arm/2.8.0-8.1/.content/bin/qemu-system-gnuarmeclipse',
            '--verbose',
            '--verbose',
            '--board', 'STM32F4-Discovery',
            '--mcu', 'STM32F407VG',
            '-d', 'unimp,guest_errors',
            '--semihosting-config', 'enable=on,target=native',
            '--image', firmware,
        ])

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
            print("To be implemented")
        elif lab == "Lab_4":
            print("To be implemented")
        elif lab == "Lab_5":
            print("To be implemented")
        else:
            print("Invalid lab selected")

if __name__ == "__main__":
    (VNC()).start()
    (Runner()).run(sys.argv[1])