/*
 * keypad.h
 *
 * Author: Mohamed Sameh
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


/* -------------- Includes -------------- */
#include "keypad_config.h"
#include "keypad_private.h"
/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */

/* -------------- Functions Declarations --------------*/
/**
 * @brief 
 * 
 */
void keypad_init();

/**
 * @brief 
 * 
 * @return char 
 */
char keypad_get_pressed_key();

#endif /* KEYPAD_H_ */