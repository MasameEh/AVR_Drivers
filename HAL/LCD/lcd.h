/*
 * LCD.h
 *  Author: Mohamed Sameh
 *  Description:
 *  Header file for controlling a character LCD using a 8-bit interface.
 */ 


#ifndef LCD_H_
#define LCD_H_

/* -------------- Includes -------------- */
#include "LCD_config.h"
#include "../../MCAL/DIO/dio.h"

/* -------------- Macro Declarations ------------- */
#define EIGHT_BITS                          0x38
#define CLEAR_SCREEN                        0x01
#define CURSOR_ON_DISPLAY_ON                0x0e
#define CURSOR_OFF_DISPLAY_ON               0x0c
#define CURSOR_ON_DISPLAY_ON_BLINK_ON       0x0d
#define ENTRY_MODE                          0x06
#define DISPLAY_SHIFT_RIGHT                 0x1C
#define DISPLAY_SHIFT_LEFT                  0x18
#define CGRAM_START                         0x40
#define DDRAM_START                         0x80

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */

/* -------------- Functions Declarations --------------*/

/**
 * @brief Initializes the character LCD.
 */
void LCD_init(void);

/**
 * @brief Generates a falling edge on the LCD enable (EN) pin.
 */
void LCD_send_falling_edge();

/**
 * @brief Sends a command to the character LCD.
 * 
 * @param cmd The command to be sent.
 */
void LCD_send_cmd(uint8 cmd);

/**
 * @brief Sends a character to be displayed on the character LCD.
 * 
 * @param data The character to be displayed.
 */
void LCD_send_char(uint8 data);

/**
 * @brief Sends a string to be displayed on the character LCD.
 * 
 * @param data The string to be displayed.
 */
void LCD_send_string(uint8 *data);

/**
 * @brief Clears the screen of the character LCD.
 */
void LCD_clearscreen();

/**
 * @brief Moves the cursor to the specified position on the character LCD.
 * 
 * @param x The x-axis position (0 to 15).
 * @param y The line number (0 or 1).
 */
void LCD_move_curser(uint8 x, uint8 y);



#endif /* LCD_H_ */