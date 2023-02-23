/*
 * Timer.c
 *
 *  Author: Mohamed Sameh
 */ 

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIBRARY/Bit_Math.h"

void timer0_normalmode_init()
{
	
	//PRESCALER -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE0);
}


void timer0_CTC_init()
{
	//select CTC mode
	SET_BIT(TCCR0,WGM01);
	//PRESCALER -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//
	//enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE0);
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