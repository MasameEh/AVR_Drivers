/*
 * Timer.c
 *
 *  Author: Mohamed Sameh
 */ 

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>


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
	//PRESCALER -> NOCLOCK SOURCE
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
	//disable interrupt
	CLR_BIT(TIMSK, TOIE0);
}

void timer1_fastPWM_A(double v)
{
	//set OC1A as output pin 
	SET_BIT(DDRD,5);
	//select fastPWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//
	OCR1A = v*1000;
	ICR1 = 20000; 
	//select timer clock, no prescaling
	SET_BIT(TCCR1B,CS10);
	//clear OC1A on compare match, set OC1A at BOTTOM
	SET_BIT(TCCR1A,COM1A1);
}

void timer1_fastPWM_B(double v)
{
	//set OC1B as output pin
	SET_BIT(DDRD,4);
	//select fastPWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//
	OCR1A = v*1000;
	ICR1 = 20000;
	//select timer clock, no prescaling
	SET_BIT(TCCR1B,CS10);
	//clear OC1B on compare match, set OC1b at BOTTOM
	SET_BIT(TCCR1A,COM1B1);
}