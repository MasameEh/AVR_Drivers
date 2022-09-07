

#include "keypad_config.h"
#include "keypad_priv.h"
#include <stdint.h>
#define F_CPU 8000000UL
#include <avr/delay.h>


/**
 * @brief 
 * 
 */
void keypad_init()
{   
    int8_t i,r;
    //inputs raws
    porting_t raw_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
    for( i = 0; i < KEYPAD_RAW_NUM; i++)
    {
        dio_set_direction(raw_arr[i].port, raw_arr[i].pin, DIO_DIRECTION_INPUT);
    }

    //outputs columns
    porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;
    for( r = 0; r < KEYPAD_COLUMN_NUM; r++)
    {
        dio_set_direction(col_arr[r].port, col_arr[r].pin, DIO_DIRECTION_OUTPUT);
    }
}


/**
 * @brief 
 * 
 * @return uint8_t 
 */
char key_get_pressed_key()
{
    int8_t i;
    uint8_t c,r; 
    
    char keys[KEYPAD_RAW_NUM][KEYPAD_COLUMN_NUM] = KEYPAD_KEY_VALUES;

    porting_t raw_arr[KEYPAD_RAW_NUM] = KEYPAD_RAW_ARR_VALUE;
    porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COL_ARR_VALUE;

    //init columns to released state
    for( i = 0; i < KEYPAD_COLUMN_NUM; i++)
    {
        dio_set_level(col_arr[i].port, col_arr[i].pin, RELEASED_LEVEL);
    }

    //scaning
    for( c = 0; c < KEYPAD_COLUMN_NUM; c++)
    {
        dio_set_level(col_arr[c].port, col_arr[c].pin, PRESSED_LEVEL);
        for( r = 0; r < KEYPAD_RAW_NUM; r++)
        {
            //delay for simulation
            _delay_ms(3);
            if(dio_get_level(raw_arr[r].port, raw_arr[r].pin) == PRESSED_LEVEL)
            {
                //wait debounce 
                _delay_ms(5);
                //wait
                while(dio_get_level(raw_arr[r].port, raw_arr[r].pin) == PRESSED_LEVEL)
                {
                }
                //
                return keys[r][c];
            }
        }
        dio_set_level(col_arr[c].port, col_arr[c].pin, RELEASED_LEVEL);
    }

    return NO_PRESS_VAL;

}

