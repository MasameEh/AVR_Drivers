/*
 * 7seg.c
 *
 * Created: 2/17/2023 5:38:51 AM
 *  Author: Mohamed Sameh
 * * Description:
 * This source file implements the functions for interfacing with a 7-segment display.
 */ 


#include "7seg.h"

/**
 * @brief Initializes the seven segment pins to be OUTPUT and turns the pins OFF or on (Start at 0 or 9)
 * 
 * @param portname The port name where the seven segment display is connected.
 */
void seven_seg_init(dio_level_t port_name)
{
	// Set the direction of the specified port pins to OUTPUT
	dio_set_port_direction(port_name, DIO_DIRECTION_OUTPUT);
}

/**
 * @brief Writes a specified number to the seven segment display configured as either common cathode or common anode.
 * 
 * @param port_name The port name where the seven segment display is connected.
 * @param number The number to be displayed on the seven segment display (0 to 9).
 * @param type The type of the seven segment display (common cathode or common anode).
 */
void seven_seg_write_number(dio_level_t port_name, uint8 number, seg_type_t type)
{
	
	if(type == SEG_COMMON_CATHODE)
	{
		// Array containing the 7-segment common cathode segment values for each digit
		uint8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
		// Write the corresponding segment value for the specified number to the port
		dio_write_port(port_name,arr[number]);
	}
	else if (type == SEG_COMMON_ANODE)
    {
        // Array containing the 7-segment common anode segment values for each digit
        uint8 arr1[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x6B};
        
        // Write the corresponding segment value for the specified number to the port
        dio_write_port(port_name, arr1[number]);
    }else{}
	
}