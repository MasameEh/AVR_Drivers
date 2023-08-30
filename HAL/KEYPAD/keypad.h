/*
 * keypad.h
 * Author: Mohamed Sameh
 * Description: This header file provides the interface and data structures for interfacing with a keypad.
 * 
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


/* -------------- Includes -------------- */
#include "../../MCAL/DIO/dio.h"
#include "keypad_config.h"
/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */
typedef struct{
	dio_t port;
	dio_pin_t pin;
} porting_t;
/* -------------- Functions Declarations --------------*/

/**
 * @brief Initializes the keypad by configuring its rows and columns as output and input pins, respectively.
 * 
 */
void keypad_init();

/**
 * @brief Reads the value of the pressed key on the keypad.
 * 
 * This function scans the keypad matrix to detect a pressed key, waits for debounce, and returns the corresponding key value.
 * 
 * @return uint8 The value of the pressed key, or `NO_PRESS_VAL` if no key is pressed.
 */
uint8 keypad_get_pressed_key();

#endif /* KEYPAD_H_ */