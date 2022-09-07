#include <avr/io.h> 
#include "spi.h"
#include "bit_math.h"




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

uint8_t spi_transfer(uint8_t data)
{
    SPDR = data;
    //waiting for transfer to end (busy wait)
    while(GET_BIT(SPSR,SPIF) != 1);
    return SPDR;
}

