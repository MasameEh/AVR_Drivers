/* 
 * File:   keypad_priv.h
 * Author: DeSkToP
 *
 * Created on August 20, 2022, 7:41 AM
 */

#ifndef  _KEYPAD_PRIVATE_H
#define  _KEYPAD_PRIVATE_H

#include "../MCAL/DIO/dio.h"

typedef struct{
    dio_t port;
    dio_pin_t pin;
} porting_t;


#endif
