#include "spi_api.h"
#include "SPI_F4HDK.h"

#if DEVICE_SPI_ASYNCH
    #define SPI_S(obj)    (( struct spi_s *)(&(obj->spi)))
#else
    #define SPI_S(obj)    (( struct spi_s *)(obj))
#endif

int spi_master_transfer_2(spi_t *obj, const unsigned char *tx, size_t tx_length, unsigned char *rx, size_t rx_length) {
    struct spi_s *spiobj = SPI_S(obj);
    SPI_HandleTypeDef *handle = &(spiobj->handle);

	if(tx_length < rx_length) {
		tx_length = rx_length;
	}
	
    /*  Use 10ms timeout */
    uint16_t ret = HAL_SPI_TransmitReceive(handle, (uint8_t *)tx, (uint8_t *)rx, tx_length, 3); //3

    if(ret == HAL_OK) {
       return tx_length;
    } else {
       return -1;
    }
}

int SPI_F4HDK::transfer_2(const unsigned char *tx_buffer, int tx_length, unsigned char *rx_buffer, int rx_length) {
	return spi_master_transfer_2 (&_spi, tx_buffer, tx_length, rx_buffer, rx_length);
}
