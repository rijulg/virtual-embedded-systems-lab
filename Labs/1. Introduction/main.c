#include "stm32f4xx_conf.h"
#include <stdlib.h>

void setup() {
    /* Set STM32 to 168 MHz. */
	// rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
	
	// /* Enable GPIOD clock. */
	// rcc_periph_clock_enable(RCC_GPIOD);

	// /* Set GPIO12 (in GPIO port D) to 'output push-pull'. */
	// gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT,
	// 		GPIO_PUPD_NONE, GPIO12 | GPIO13 | GPIO14 | GPIO15);
}

void loop() {
	int i;
    // gpio_toggle(GPIOD, GPIO12);

    /* Blink randamly. */
    int loop = (rand() % 10) * 1000000;
    for (i = 0; i < loop; i++) {		/* Wait a bit. */
        __asm__("nop");
    }
}


int main(void)
{
    setup();
    while(1) { loop(); }
    return 1;
}