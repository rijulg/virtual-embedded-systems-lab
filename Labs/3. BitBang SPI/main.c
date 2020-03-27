#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

static uint8_t _button_press_count;

static void _configure_leds() {
  /**
    * @todo
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
}

static void _button_pinmode_interrupt() {
  /**
    * @todo
    * This is similar to _configure_leds
    * but you need to enable an IRQ in the NVIC as well
   */
}

/**
  * @todo
  * You need to setup the interrupt handler here and in that count the number of button presses
  * NOTE: button press is different from button release!
*/

static void _transmit_spi_uint8(const uint8_t data) {
    /**
     * @todo
     * You need to do the implement the SPI protocol using the configured GPIO pins
     */
}

static void _setup() {
  _configure_leds();
  _button_pinmode_interrupt();
}

static void _loop() {
  /**
   * @todo
   * Print the current button press count using SPI bitbanging and then delay/sleep for a while
   * We call this bitbanging because we are using normal GPIO at a very high frequency to emulate a peripheral
   * Generally when a peripheral is available they have internal optimisations which are difficult to implement on GPIO
   */
}

int main() {
  _setup();
  while(1) { _loop(); }
  return 1;
}
