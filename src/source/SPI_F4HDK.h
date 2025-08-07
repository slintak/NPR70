#ifndef __SPI_F4HDK_H__
#define __SPI_F4HDK_H__

#include "mbed.h"
#include "SPI.h"

/**
 * This class inherits from the standard SPI and adds a custom function,
 * `transfer_2`, originally written by F4HDK. The original code directly
 * modified the MbedOS files `SPI.h` and `stm_spi_api.c`, which is not ideal.
 * The new approach uses inheritance in C++ to create a custom SPI class with
 * an additional method, `transfer_2`.
 */
class SPI_F4HDK: public SPI {
public:
    using SPI::SPI;

    int transfer_2(const unsigned char *tx_buffer, int tx_length, unsigned char *rx_buffer, int rx_length);
};

#endif
