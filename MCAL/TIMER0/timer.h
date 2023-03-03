/*
 * timer.h
 *
 *  Author: Mohamed Sameh
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../LIBRARY/Bit_Math.h"

void timer0_normalmode_init();
void timer0_CTC_init();
void timer0_deinit();
void timer1_fastPWM_A(double v);
void timer1_fastPWM_B(double v);




#endif /* TIMER_H_ */