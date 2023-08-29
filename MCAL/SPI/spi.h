/* 
 * File:   spi.h
 * Author: Mohamed sameh
 *
 * Created on September 1, 2022, 1:44 PM
 */

#ifndef SPI_H
#define	SPI_H

/* -------------- Includes -------------- */
#include <avr/io.h>
#include"../../LIBRARY/Platform_Types.h"
#include"../../LIBRARY/Bit_Math.h"
/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */

/* -------------- Functions Declarations --------------*/
void spi_init_master();
void spi_init_slave();
uint8 spi_transfer(uint8 data);


#endif	/* SPI_H */

