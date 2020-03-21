#!/bin/bash
/root/opt/xPacks/@xpack-dev-tools/qemu-arm/2.8.0-8.1/.content/bin/qemu-system-gnuarmeclipse  \
--verbose --verbose \
--board STM32F4-Discovery --mcu STM32F407VG \
-d unimp,guest_errors \
--image test.elf \
--semihosting-config enable=on,target=native \
--semihosting-cmdline test 1 2 3