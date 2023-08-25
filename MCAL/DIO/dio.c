/*
 * File: dio.c
 *
 * Author: Mohamed Sameh
 *
 * Description:
 * This file contains the implementation of functions for controlling
 * Digital Input/Output (DIO) pins and ports on a microcontroller.
 * It provides functions to set pin direction, write to pins/ports,
 * read pin states, and manage GPIO configurations.
 *
 */

#include "dio.h"

/**
 * @brief Sets the direction of a specific pin on a given port.
 * 
 * @param port      The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param pin       The target pin (DIO_PIN0, DIO_PIN1, etc.).
 * @param direction The desired direction (DIO_DIRECTION_INPUT or DIO_DIRECTION_OUTPUT).
 */
void dio_set_pin_direction(dio_t port, dio_pin_t pin, dio_direction_t direction)
{
	volatile uint8_t *ddr_register = NULL;

    switch (port)
    {
    case DIO_PORTA:
        ddr_register = &DDRA;
        break;
    case DIO_PORTB:
        ddr_register = &DDRB;
        break;
    case DIO_PORTC:
        ddr_register = &DDRC;
        break;
    case DIO_PORTD:
        ddr_register = &DDRD;
        break;
    default:
        // Handle error
        break;
    }

    if (direction == DIO_DIRECTION_INPUT)
    {
        CLR_BIT(*ddr_register, pin);
    }
    else if (direction == DIO_DIRECTION_OUTPUT)
    {
		CLR_BIT(*ddr_register, pin);
        SET_BIT(*ddr_register, pin);
    }
    else
    {}
}

/**
 * @brief Writes a specific value to a pin on a given port.
 * 
 * @param port  The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param pin   The target pin (DIO_PIN0, DIO_PIN1, etc.).
 * @param value The value to be written (DIO_LEVEL_LOW or DIO_LEVEL_HIGH).
 */
void dio_write_pin(dio_t port, dio_pin_t pin, dio_level_t value)
{	
	if (value == DIO_LEVEL_LOW)
	{
		switch (port)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, pin);   // clear bit
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, pin);   // clear bit
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC, pin);   // clear bit
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD, pin);   // clear bit
			break;
		default:
			//report error
			break;
		}
	}
	else
	{
		switch (port)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			SET_BIT(PORTA, pin);   
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, pin);  
			SET_BIT(PORTB, pin);   
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC, pin);  
			SET_BIT(PORTC, pin);   
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD, pin);  
			SET_BIT(PORTD, pin);   
			break;
		default:
			//report error
			break;
		}
	}
	
}

/**
 * @brief Reads the value of a specific pin on a given port.
 * 
 * @param port The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param pin  The target pin (DIO_PIN0, DIO_PIN1, etc.).
 * @return dio_level_t The value read (DIO_LEVEL_LOW or DIO_LEVEL_HIGH).
 */
dio_level_t dio_get_pin(dio_t port, dio_pin_t pin)
{
	switch (port)
	{
		case DIO_PORTA:
			return (dio_level_t)((PINA >> pin) & 0x01);
		case DIO_PORTB:
			return (dio_level_t)((PINB >> pin) & 0x01);
		case DIO_PORTC:
			return (dio_level_t)((PINC >> pin) & 0x01);
		case DIO_PORTD:
			return (dio_level_t)((PIND >> pin) & 0x01);
		default:
			return DIO_LEVEL_LOW;  // Or return a default value of your choice
	}
}

/**
 * @brief Sets the direction of all pins on a given port.
 * 
 * @param port      The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param direction The desired direction (DIO_DIRECTION_INPUT or DIO_DIRECTION_OUTPUT).
 */
void dio_set_port_direction(dio_t port, dio_direction_t direction)
{
	if(direction == DIO_DIRECTION_INPUT)
	{
		switch (port)
		{
		case DIO_PORTA:
			DDRA = 0;   
			break;
		case DIO_PORTB:
			DDRB = 0;   
			break;
		case DIO_PORTC:
			DDRC = 0;   
			break;
		case DIO_PORTD:
			DDRD = 0;   
			break;
		default:
			//report error
			break;
		}
	}
	else
	{
		switch (port)
			{
			case DIO_PORTA:
				DDRA = 0xff;   
				break;
			case DIO_PORTB:
				DDRB = 0xff;   
				break;
			case DIO_PORTC:
				DDRC = 0xff;   
				break;
			case DIO_PORTD:
				DDRD = 0xff;   
				break;
			default:
				//report error
				break;
			}
	}
}

/**
 * @brief Writes a value to all pins on a given port.
 * 
 * @param port  The target port (DIO_PORTA, DIO_PORTB, etc.).
 * @param value The value to be written to all pins.
 */
void dio_write_port(dio_t port, dio_level_t value)
{
	switch (port)
	{
	case DIO_PORTA:
		PORTA = value;
		break;
	case DIO_PORTB:
		PORTB = value;
		break;
	case DIO_PORTC:
		PORTC = value;
		break;
	case DIO_PORTD:
		PORTD = value;
		break;
	default:
		// report error
		break;
	}
}