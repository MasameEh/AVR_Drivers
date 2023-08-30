/*
 * keypad.c
 *
 * Author: Mohamed Sameh
 * Description: This file contains the implementation of functions to interface with a keypad.
 * 
 */ 


#include "keypad.h"


/**
 * @brief Initializes the keypad by configuring its rows and columns as output and input pins, respectively.
 * 
 */
void keypad_init()
{
	int8_t i,r;
	//inputs raws
	porting_t raw_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
	for(i = 0; i < KEYPAD_RAW_NUM; i++)
	{
		dio_set_pin_direction(raw_arr[i].port, raw_arr[i].pin, DIO_DIRECTION_INPUT);
		dio_write_pin(raw_arr[i].port, raw_arr[i].pin, DIO_LEVEL_HIGH);
	}

	//outputs columns
	porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;
	for(r = 0; r < KEYPAD_COLUMN_NUM; r++)
	{
		dio_set_pin_direction(col_arr[r].port, col_arr[r].pin, DIO_DIRECTION_OUTPUT);
	}

}

/**
 * @brief Reads the value of the pressed key on the keypad.
 * 
 * This function scans the keypad matrix to detect a pressed key, waits for debounce, and returns the corresponding key value.
 * 
 * @return uint8 The value of the pressed key, or `NO_PRESS_VAL` if no key is pressed.
 */
uint8 keypad_get_pressed_key()
{
	
	uint8 i = 0,c = 0,r = 0;
	
	char returnval = NO_PRESS_VAL; 
	char keys[KEYPAD_RAW_NUM][KEYPAD_COLUMN_NUM] = KEYPAD_KEY_VALUES;

	porting_t raw_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
	porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;

	// Init columns to released state
	for(i = 0; i < KEYPAD_COLUMN_NUM; i++)
	{
		dio_write_pin(col_arr[i].port, col_arr[i].pin, RELEASED_LEVEL);
	}

	// Scanning
	for(c = 0; c < KEYPAD_COLUMN_NUM; c++)
	{
		dio_write_pin(col_arr[c].port, col_arr[c].pin, PRESSED_LEVEL);
		for(r = 0; r < KEYPAD_RAW_NUM; r++)
		{
			if(dio_get_pin(raw_arr[r].port, raw_arr[r].pin) == PRESSED_LEVEL)
			{
				// Wait debounce
				_delay_ms(2);
				// Wait for key release
				while(dio_get_pin(raw_arr[r].port, raw_arr[r].pin) == PRESSED_LEVEL)
				{
				}
				// Return the pressed key value
				returnval = keys[r][c];
				break;
			}
		}
		dio_write_pin(col_arr[c].port, col_arr[c].pin, RELEASED_LEVEL);
	}

	return returnval;
	
}