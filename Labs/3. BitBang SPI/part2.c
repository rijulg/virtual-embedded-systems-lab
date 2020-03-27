#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/**
  * @todo Implement
  * You need to configure 3 LEDs as output with the following requirements:
  *   1. LED ORANGE   :: SPI Slave Select (SS)
  *   2. LED GREEN    :: SPI Clock        (SCLK)
  *   3. LED BLUE     :: SPI Data         (MOSI)
  * You need to do the following to set the led pin as output
  *   1. Enable GPIOx clock first.
  *   2. Initialize the GPIOx port with the specified pins as output
  * You can get this information either from looking at examples.
  * Try to look for examples of STM32F407xx GPIO initialisation online.
*/
static void _setup_spi() {
}

/**
 * @todo Implement
 * You need to implement a half-duplex SPI Master using the configured GPIO pins.
 *  - No input needs to be read using MISO
 *  - SS must be made IDLE before and after the Slave has been selected for data to be transmitted correctly
 *  - Bit changes (MOSI) should be accompanied with SCLK toggle
 */
static void _transmit_spi_uint8(const uint8_t data) {
}

int main() {
  _setup_spi();
  _transmit_spi_uint8(0x55);
  return 1;
}
