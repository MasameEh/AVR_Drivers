/* 
 * File:   uart.h
 * Author: Mohamed Sameh
 *
 * Created on August 29, 2022, 2:14 PM
 */

#ifndef UART_H
#define	UART_H

/* -------------- Includes -------------- */
#include <avr/io.h>
#include"../../LIBRARY/Platform_Types.h"
#include"../../LIBRARY/Bit_Math.h"
/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */

/* -------------- Functions Declarations --------------*/
void uart_init();
void uart_send_data(uint8 data);
uint8 uart_receive_data();
uint8 uart_isdata_ready();
void uart_sendstring(char* str);
void uart_receive_string(char* str, uint8 length,char terminate);
void uart_set_tx_callback(void(*callback)(void));
void uart_set_rx_callback(void(*callback)(void));


#endif






