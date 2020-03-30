#ifndef INTERFACE_SPI
#define INTERFACE_SPI

#include <stdint.h>

uint8_t spi_read_uint8();
void spi_write_uint8(uint8_t data);
uint16_t spi_read_uint16();

// Non standard functions required for the lab
void verify_manufacturer_id(uint8_t id);
void verify_revision_id(uint8_t id);
void verify_temp(int16_t temp);

#endif
