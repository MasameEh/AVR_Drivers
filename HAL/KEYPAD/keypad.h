/*
 * keypad.h
 *
 *  Author: Mohamed Sameh
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "keypad_config.h"
#include "keypad_private.h"

void keypad_init();
char keypad_get_pressed_key();

#endif /* KEYPAD_H_ */