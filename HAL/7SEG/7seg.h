/*
 * 7seg.h
 *
 * Created: 2/17/2023 5:39:24 AM
 * Description:
 * This header file provides the interface and data structures for controlling a 7-segment display using DIO pins. 
 *  Author: Mohamed Sameh
 */ 


#ifndef SEG_H_
#define SEG_H_

/* -------------- Includes -------------- */
#include "../../MCAL/DIO/dio.h"
#include "../../LIBRARY/Platform_Types.h"
/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */
typedef enum
{
    SEG_COMMON_ANODE,
    SEG_COMMON_CATHODE   
}seg_type_t;

/* -------------- Functions Declarations --------------*/
/**
 * @brief Initializes the seven segment pins to be OUTPUT and turns the pins OFF or on (Start at 0 or 9)
 * 
 * @param portname The port name where the seven segment display is connected.
 */
void seven_seg_init(dio_level_t port_name);

/**
 * @brief Writes a specified number to the seven segment display configured as either common cathode or common anode.
 * 
 * @param port_name The port name where the seven segment display is connected.
 * @param number The number to be displayed on the seven segment display (0 to 9).
 * @param type The type of the seven segment display (common cathode or common anode).
 */
void seven_seg_write_number(dio_level_t port_name, uint8 number,seg_type_t type);


#endif /* SEG_H_ */