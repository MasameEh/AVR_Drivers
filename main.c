/* 
 * File:   main.c
 * Author: Mohamed Sameh
 *
 * Created on February 17, 2023, 3:19 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define F_CPU 8000000UL

#include "MCAL/DIO/dio.h"

void main() {
    
    dio_set_direction(DIO_PORTA, DIO_PIN0 , DIO_DIRECTION_OUTPUT);
     dio_set_level(DIO_PORTA, DIO_PIN0 , 1);
}

