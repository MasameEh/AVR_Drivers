/* 
 * File:   keypad.h
 * Author: Mohamed Sameh
 *
 * Created on August 20, 2022, 7:38 AM
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include <stdint.h>

void keypad_init();
uint8_t key_get_pressed_key();

#endif /* KEYPAD_KEYPAD_H_ */

