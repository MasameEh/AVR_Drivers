/* 
 * File:   uart.h
 * Author: DeSkToP
 *
 * Created on August 29, 2022, 2:14 PM
 */

#ifndef UART_H
#define	UART_H

#include <stdint.h>


void uart_init();
void uart_send_data(uint8_t data);
uint8_t uart_receive_data();
uint8_t uart_isdata_ready();
void uart_sendstring(char* str);
void uart_receive_string(char* str, uint8_t length,char terminate);
void uart_set_tx_callback(void(*callback)(void));
void uart_set_rx_callback(void(*callback)(void));



#endif






