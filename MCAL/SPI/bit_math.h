#ifndef _BIT_MATH_H_
#define	_BIT_MATH_H_


#define SET_BIT(reg, bit_n)   reg|= 1<<bit_n
#define CLR_BIT(reg, bit_n)   reg&= ~(1<<bit_n)
#define GET_BIT(reg, bit_n)   ((reg>>bit_n)&1)

#endif