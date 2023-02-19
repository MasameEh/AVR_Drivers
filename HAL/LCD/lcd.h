/*
 * LCD.h
 *
 *  Author: Mohamed Sameh
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "LCD_config.h"
#include <stdint.h>
#define EIGHT_BITS 0x38
#define CLEAR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define CURSOR_OFF_DISPLAY_ON 0x0c
#define CURSOR_ON_DISPLAY_ON_BLINK_ON 0x0d
#define ENTRY_MODE 0x06


void LCD_init(void);
void LCD_send_cmd(char cmd);
void LCD_send_falling_edge();
void LCD_send_char(char data);
void LCD_send_string(char *data);
void LCD_clearscreen();
void LCD_move_curser(uint8_t x, uint8_t y);






#endif /* LCD_H_ */