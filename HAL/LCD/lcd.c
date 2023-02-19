/*
 * LCD.c
 *
 *  Author: Mohamed Sameh
 */ 
#include "LCD.h"
#include "../../MCAL/DIO/dio.h"
#include <util/delay.h>

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

void LCD_send_falling_edge()
{
	dio_write_pin(LCD_EN_PORT, LCD_EN_PIN, DIO_LEVEL_HIGH);
	_delay_ms(3);
	dio_write_pin(LCD_EN_PORT, LCD_EN_PIN, DIO_LEVEL_LOW);
	_delay_ms(3);
}

void LCD_send_cmd(char cmd)
{
	//read/write -> always write
	//RS-> CMD:0
	dio_write_pin(LCD_RS_PORT, LCD_RS_PIN, DIO_LEVEL_LOW);
	//write value on data bus
	dio_write_port(LCD_DATA_PORT,cmd);
	LCD_send_falling_edge();
}

void LCD_send_char(char data)
{
	//RS-> DATA:1
	dio_write_pin(LCD_RS_PORT, LCD_RS_PIN, DIO_LEVEL_HIGH);
	dio_write_port(LCD_DATA_PORT,data);
	LCD_send_falling_edge();

}

void LCD_send_string(char *data)
{
	while((*data) != '\0')
	{
		LCD_send_char(*data);
		data++;	
	}
}


void LCD_clearscreen()
{
	LCD_send_cmd(CLEAR_SCREEN);
	_delay_ms(10);
}


/**
 * @brief 
 * 
 * @param x: specifies the x axis range: 0->15
 * @param y: specifies the line range: 0,1
 */
void LCD_move_curser(uint8_t x, uint8_t y)
{
	uint8_t address = x;
	if(y == 1)
	{
		address += 0x40;
	}
	LCD_send_cmd(0b10000000 | address);
}