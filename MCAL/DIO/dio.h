/*
 * File: dio.h
 *
 * Author: Mohamed Sameh
 *
 * Description:
 * This file contains the definitions of enums and function prototypes
 * for controlling Digital Input/Output (DIO) pins and ports on a microcontroller.
 * It provides enums for ports, pins, directions, and logic levels, as well as
 * function prototypes for configuring, reading, and writing to pins/ports.
 *
 */

#ifndef DIO_H_
#define DIO_H_

/* Section : Includes */
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "../../LIBRARY/Bit_Math.h"
#include "../../LIBRARY/Platform_Types.h"
/* Section : Macro Declarations */
#define F_CPU 8000000UL
/* Section : Macro Functions Declarations */


/* Section : Data Types Declarations  */
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
} dio_t;

typedef enum{
	DIO_PIN0 = 0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
} dio_pin_t;

typedef enum
{
	DIO_DIRECTION_INPUT = 0,
	DIO_DIRECTION_OUTPUT = 1
} dio_direction_t;

typedef enum
{
	DIO_LEVEL_LOW = 0,
	DIO_LEVEL_HIGH = 1
} dio_level_t;


/* Section : Functions Declarations */

/**
 * @brief Sets the direction of a specific pin on a given port.
 * 
 * @param port      The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param pin       The target pin (DIO_PIN0, DIO_PIN1, etc.).
 * @param direction The desired direction (DIO_DIRECTION_INPUT or DIO_DIRECTION_OUTPUT).
 */
void dio_set_pin_direction(dio_t port, dio_pin_t pin, dio_direction_t direction);

/**
 * @brief Writes a specific value to a pin on a given port.
 * 
 * @param port  The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param pin   The target pin (DIO_PIN0, DIO_PIN1, etc.).
 * @param value The value to be written (DIO_LEVEL_LOW or DIO_LEVEL_HIGH).
 */
void dio_write_pin(dio_t port, dio_pin_t pin, dio_level_t value);

/**
 * @brief Sets the direction of all pins on a given port.
 * 
 * @param port      The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param direction The desired direction (DIO_DIRECTION_INPUT or DIO_DIRECTION_OUTPUT).
 */
void dio_set_port_direction(dio_t port, dio_direction_t direction);

/**
 * @brief Writes a value to all pins on a given port.
 * 
 * @param port  The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param value The value to be written to all pins.
 */
void dio_write_port(dio_t port, dio_level_t value);

/**
 * @brief Reads the value of a specific pin on a given port.
 * 
 * @param port The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param pin  The target pin (DIO_PIN0, DIO_PIN1, etc.).
 * @return dio_level_t The value read (DIO_LEVEL_LOW or DIO_LEVEL_HIGH).
 */
dio_level_t dio_get_pin(dio_t port, dio_pin_t pin);

#endif /* DIO_H_ */
