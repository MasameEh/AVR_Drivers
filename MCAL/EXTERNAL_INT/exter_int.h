/*
 * File: exter_int.c
 *
 * Author: Mohamed Sameh
 * 
 */

#ifndef EXTER_INT_H_
#define EXTER_INT_H_
/* -------------- Includes -------------- */
#include"../../LIBRARY/Platform_Types.h"

/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */
typedef enum{
    EXTERINT_INT0,
    EXTERINT_INT1,
    EXTERINT_INT2
} exterint_t;

typedef enum{
    EXTERINT_RISING_EDGE = 0b11,
    EXTERINT_FALLING_EDGE = 0b10,
    EXTERINT_BOTH_EDGES= 0b01,
    EXTERINT_LOW_LEVEL = 0
}exterint_event_t;

/* -------------- Functions Declarations --------------*/
void exterint_set_status(exterint_t int_num, uint8 status, exterint_event_t event);

#endif