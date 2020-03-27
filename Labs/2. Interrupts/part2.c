#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/**
  * @todo Implement
  * You need to do the following to set the green led pin as output
  *   1. Enable GPIOx clock first.
  *   2. Initialize the GPIOx port with the specified pins as output
  * You can get this information either from looking at examples.
  * Try to look for examples of STM32F407xx GPIO initialisation online.
*/
static void _led_pinmode_out() {
}

/**
  * @todo Implement
  * This is similar to _led_pinmode_out
  * but you need to enable an IRQ in the NVIC as well
*/
static void _button_pinmode_interrupt() {
}

/**
  * @todo Implement
  * You need to setup the interrupt handler here and in that turn the LED on on button press
  * NOTE: button press is different from button release!
*/


static void _setup() {
  _led_pinmode_out();
  _button_pinmode_interrupt();
}

/**
 * @todo Implement
 * You need to put a delay or sleep function here this would stop the processor
 * from running this loop continuously as fast as possible
 */
static void _loop() {
}

int main() {
  _setup();
  while(1) { _loop(); }
  return 1;
}
