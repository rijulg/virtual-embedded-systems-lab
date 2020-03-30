#include "spi.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_TEMP_READS 5

/**
 * @todo Implement
 * Read the ID from the device using SPI and verify that they are correct
 */
static void _read_ids() {
    verify_manufacturer_id(0);
    verify_revision_id(0);
}

/**
 * @todo Implement
 * Configure the device to the following specification:
 *  * 13 bit resolution
 *  * 1 shot operation
 *  * Interrupt mode
 *  * Active low INT and CT pins
 *  * Fault queue size = 4
 */
static void _config_device() { }

/**
 * @todo Implement
 * Read the temperature from the device, convert it using 9-bit format
 * and verify that it is correct.
 * 
 * Note: We have to use 9-bit format here because the emulator does not
 * have a working FPU (Floating point unit)
 */
static void _read_temp() {
    int16_t expected_temp = 0;
    verify_temp(expected_temp);
}

int main() {
    _read_ids();
    _config_device();
    for (int i = 0; i < MAX_TEMP_READS; i++) {
        _read_temp();
    }
    return 1;
}