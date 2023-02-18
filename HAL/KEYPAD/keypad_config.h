/* 
 * File:   keypad_config.h
 * Author: Mohamed Sameh
 *
 * Created on August 20, 2022, 7:39 AM
 */

#ifndef  _KEYPAD_CONFIG_H
#define  _KEYPAD_CONFIG_H

#include "MCAL/DIO/dio.h"

#define KEYPAD_RAW_NUM    4
#define KEYPAD_COLUMN_NUM 4


// #define KEYPAD_R0_PIN     DIO_PIN6
// #define KEYPAD_R0_PORT    DIO_PORTC

// #define KEYPAD_R1_PIN     DIO_PIN7
// #define KEYPAD_R1_PORT    DIO_PORTC

// #define KEYPAD_R2_PIN     DIO_PIN6
// #define KEYPAD_R2_PORT    DIO_PORTA

// #define KEYPAD_R3_PIN     DIO_PIN7
// #define KEYPAD_R3_PORT    DIO_PORTA

#define KEYPAD_RAW_ARR_VALUE {     \
    {DIO_PORTC, DIO_PIN6},         \
    {DIO_PORTC, DIO_PIN7},         \
    {DIO_PORTA, DIO_PIN6},         \
    {DIO_PORTA, DIO_PIN7}          \
};


#define KEYPAD_COL_ARR_VALUE {     \
    {DIO_PORTC, DIO_PIN2},         \
    {DIO_PORTC, DIO_PIN3},         \
    {DIO_PORTC, DIO_PIN4},         \
    {DIO_PORTC, DIO_PIN5}          \
};

// #define KEYPAD_C0_PIN     DIO_PIN2
// #define KEYPAD_C0_PORT    DIO_PORTC

// #define KEYPAD_C1_PIN     DIO_PIN3
// #define KEYPAD_C1_PORT    DIO_PORTC

// #define KEYPAD_C2_PIN     DIO_PIN4
// #define KEYPAD_C2_PORT    DIO_PORTC

// #define KEYPAD_C3_PIN     DIO_PIN5
// #define KEYPAD_C3_PORT    DIO_PORTC

#define KEYPAD_KEY_VALUES   {   \
 {'1', '2', '3', '4'},         \
 {'5', '6', '7', '8'},         \
 {'9', 'A', 'B', 'C'},         \
 {'D', 'E', 'F', '0'}          \
}


#define RELEASED_LEVEL  DIO_LEVEL_HIGH
#define PRESSED_LEVEL   DIO_LEVEL_LOW

#define NO_PRESS_VAL    0

#endif

