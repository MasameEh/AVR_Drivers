/* 
 * File:   spi.h
 * Author: Mohamed sameh
 *
 * Created on September 1, 2022, 1:44 PM
 */

#ifndef SPI_H
#define	SPI_H

#include <stdint.h>

void spi_init_master();
void spi_init_slave();
uint8_t spi_transfer(uint8_t);




#endif	/* SPI_H */

