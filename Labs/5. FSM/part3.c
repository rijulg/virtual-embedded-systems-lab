#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

static enum {
    EXIT
} _state = EXIT;

static enum {
    UART_IDLE
} _state_uart = UART_IDLE;

/**
 * @todo Implement
 */
static void _uart_state_machine() { }

/**
 * @todo Implement
 */
static void _state_machine() { }

int main() {
  while (_state != EXIT) { _state_machine(); }
  return 1;
}

/**
 * This is needed to make the oscilloscope like output work
 */
#include <stdio.h>
void SysTick_Handler(void) {
  HAL_IncTick();
  printf("[tick]\n");
}