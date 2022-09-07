#include "timer.h"
#include <avr/io.h>




#define SET_BIT(reg, bit_n)   reg|= 1<<bit_n;
#define CLR_BIT(reg, bit_n)   reg&= ~(1<<bit_n);

void timer0_init()
{
    //mode -> normal
    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);
    //preload value 
    TCNT0 = 0;
    //clock source
    //PRESCALER -> 1024
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    //enable interrupt
    SET_BIT(TIMSK, TOIE0);
}

void timer0_deinit()
{
    //clock source
    //PRESCALER -> NOCLOCK SOURCE
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
    //disable interrupt
    CLR_BIT(TIMSK, TOIE0);
}

uint8_t timer0_get_counter()
{
    return TCNT0;
}