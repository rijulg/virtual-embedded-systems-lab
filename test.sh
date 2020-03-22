#!/bin/bash
/root/opt/xPacks/@xpack-dev-tools/qemu-arm/2.8.0-8.1/.content/bin/qemu-system-gnuarmeclipse  \
--verbose --verbose \
--board STM32F4-Discovery --mcu STM32F407VG \
-d unimp,guest_errors \
--image .stm32f407vg/build/blinky.elf \
--semihosting-config enable=on,target=native \
--semihosting-cmdline test 1 2 3
# --image f407-disc-blink-tutorial/Debug/f407-disc-blink-tutorial.elf \
# --image f407-disc-blink-tutorial/build/blinky.elf \
# --image test.elf \