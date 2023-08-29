 /* 
 * File:   spi.c
 * Author: Mohamed sameh
 *
 * Created on September 1, 2022, 1:44 PM
 */

#include "spi.h"

/**
 * @brief 
 * 
 */
void spi_init_master()
{   
  
    //LSB
    SET_BIT(SPCR, DORD);
    //master select
    SET_BIT(SPCR, MSTR);   
    //clk polarity leading -> falling edge
    SET_BIT(SPCR, CPOL);
    //clk phase setup -> leading
    SET_BIT(SPCR, CPHA);
    
    //clk prescalar 
    //64
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
    
    //spi enable
    SET_BIT(SPCR, SPE);
    //interrupt
    CLR_BIT(SPCR, SPIE);

}

/**
 * @brief 
 * 
 */
void spi_init_slave()
{
    //LSB
    SET_BIT(SPCR, DORD);
    //slave select
    CLR_BIT(SPCR, MSTR);   
    //clk polarity leading -> falling edge
    SET_BIT(SPCR, CPOL);
    //clk phase setup -> leading
    SET_BIT(SPCR, CPHA);
    
    //spi enable
    SET_BIT(SPCR, SPE);
    //interrupt
    CLR_BIT(SPCR, SPIE);
}

/**
 * @brief 
 * 
 * @param data 
 * @return uint8 
 */
uint8 spi_transfer(uint8 data)
{
    SPDR = data;
    //waiting for transfer to end (busy wait)
    while(GET_BIT(SPSR,SPIF) != 1);
    return SPDR;
}

