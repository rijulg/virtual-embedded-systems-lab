#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/**
   * @todo Implement
   * You need to do the following to set the green led pin as output
   *  1. Enable GPIOx clock first.
   *  2. Initialize the GPIOx port with the specified pins as output
   * You can get this information either from looking at examples.
   * Try to look for examples of STM32F407xx GPIO initialisation online.
*/
static void _led_pinmode_out() {
  
}

/**
 * @todo Implement
 * Now you need to toggle the LED pin and wait 750ms after each toggle operation
 */
static void _toggleLED() {
}

int main() {
  _led_pinmode_out();
  while(1) { _toggleLED(); }
  return 1;
}
