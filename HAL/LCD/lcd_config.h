#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H


#include "../mcal/dio/dio.h"


/****************
 *  USER CONFIG
 ****************/
#define LCD_DATA_PORT DIO_PORTD
#define LCD_RS_PORT   DIO_PORTC
#define LCD_RS_PIN    DIO_PIN0
#define LCD_EN_PORT   DIO_PORTC
#define LCD_EN_PIN    DIO_PIN1


#endif