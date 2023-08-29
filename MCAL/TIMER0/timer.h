/*
 * timer.h
 *
 *  Author: Mohamed Sameh
 */ 


#ifndef TIMER_H_
#define TIMER_H_
/* -------------- Includes -------------- */
#include "../../LIBRARY/Bit_Math.h"
#include <avr/io.h>
#include <avr/interrupt.h>
/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */

/* -------------- Functions Declarations --------------*/
void timer0_normalmode_init();
void timer0_CTC_init();
void timer0_deinit();
void timer1_fastPWM_A(double v);
void timer1_fastPWM_B(double v);




#endif /* TIMER_H_ */