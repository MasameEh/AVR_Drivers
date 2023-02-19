/*
 * keypad.c
 *
 *  Author: Mohamed Sameh
 */ 


#include "keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void keypad_init()
{
	int8_t i,r;
	//inputs raws
	porting_t raw_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
	for( i = 0; i < KEYPAD_RAW_NUM; i++)
	{
		dio_set_pin_direction(raw_arr[i].port, raw_arr[i].pin, DIO_DIRECTION_INPUT);
	}

	//outputs columns
	porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;
	for( r = 0; r < KEYPAD_COLUMN_NUM; r++)
	{
		dio_set_pin_direction(col_arr[r].port, col_arr[r].pin, DIO_DIRECTION_OUTPUT);
	}

}

char keypad_get_pressed_key()
{
	
	int8_t i;
	uint8_t c,r;
	
	char keys[KEYPAD_RAW_NUM][KEYPAD_COLUMN_NUM] = KEYPAD_KEY_VALUES;

	porting_t raw_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
	porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;

	//init columns to released state
	for( i = 0; i < KEYPAD_COLUMN_NUM; i++)
	{
		dio_write_pin(col_arr[i].port, col_arr[i].pin, RELEASED_LEVEL);
	}

	//scanning
	for( c = 0; c < KEYPAD_COLUMN_NUM; c++)
	{
		dio_write_pin(col_arr[c].port, col_arr[c].pin, PRESSED_LEVEL);
		for( r = 0; r < KEYPAD_RAW_NUM; r++)
		{
			//delay for simulation
			_delay_ms(2);
			if(dio_get_pin(raw_arr[r].port, raw_arr[r].pin) == PRESSED_LEVEL)
			{
				//wait debounce
				_delay_ms(2);
				//wait
				while(dio_get_pin(raw_arr[r].port, raw_arr[r].pin) == PRESSED_LEVEL)
				{
				}
				//
				return keys[r][c];
			}
		}
		dio_write_pin(col_arr[c].port, col_arr[c].pin, RELEASED_LEVEL);
	}

	return NO_PRESS_VAL;
	
}