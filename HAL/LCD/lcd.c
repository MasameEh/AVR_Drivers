/*
 * LCD.c
 * Author: Mohamed Sameh
 * Description:
 * Source file for controlling a character LCD using a 8-bit interface.
  */ 
#include "LCD.h"

/**
 * @brief Initializes the character LCD.
 */
void LCD_init(void){
	
	_delay_ms(30);
	dio_set_pin_direction(LCD_EN_PORT, LCD_EN_PIN, DIO_DIRECTION_OUTPUT);
	dio_set_pin_direction(LCD_RS_PORT, LCD_RS_PIN, DIO_DIRECTION_OUTPUT);
	dio_set_port_direction(LCD_DATA_PORT, DIO_DIRECTION_OUTPUT);
	
	//lcd init
	//function set (8 bits mode)
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_OFF_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLEAR_SCREEN);
	_delay_ms(5);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
}

/**
 * @brief Generates a falling edge on the LCD enable (EN) pin.
 */
void LCD_send_falling_edge()
{
	dio_write_pin(LCD_EN_PORT, LCD_EN_PIN, DIO_LEVEL_HIGH);
	_delay_ms(3);
	dio_write_pin(LCD_EN_PORT, LCD_EN_PIN, DIO_LEVEL_LOW);
	_delay_ms(3);
}

/**
 * @brief Sends a command to the character LCD.
 * 
 * @param cmd The command to be sent.
 */
void LCD_send_cmd(uint8 cmd)
{
	//read/write -> always write
	//RS-> CMD:0
	dio_write_pin(LCD_RS_PORT, LCD_RS_PIN, DIO_LEVEL_LOW);
	//write value on data bus
	dio_write_port(LCD_DATA_PORT,cmd);
	LCD_send_falling_edge();
}

/**
 * @brief Sends a character to be displayed on the character LCD.
 * 
 * @param data The character to be displayed.
 */
void LCD_send_char(uint8 data)
{
	//RS-> DATA:1
	dio_write_pin(LCD_RS_PORT, LCD_RS_PIN, DIO_LEVEL_HIGH);
	dio_write_port(LCD_DATA_PORT,data);
	LCD_send_falling_edge();

}

/**
 * @brief Sends a string to be displayed on the character LCD.
 * 
 * @param data The string to be displayed.
 */
void LCD_send_string(uint8 *data)
{
	while((*data) != '\0')
	{
		LCD_send_char(*data);
		data++;	
	}
}

/**
 * @brief Clears the screen of the character LCD.
 */
void LCD_clearscreen()
{
	LCD_send_cmd(CLEAR_SCREEN);
	_delay_ms(10);
}


/**
 * @brief Moves the cursor to the specified position on the character LCD.
 * 
 * @param x The x-axis position (0 to 15).
 * @param y The line number (0 or 1).
 */
void LCD_move_curser(uint8 x, uint8 y)
{
	uint8 address = x;
	if(y == 1)
	{
		address += 0x40;
	}
	LCD_send_cmd(0b10000000 | address);
}