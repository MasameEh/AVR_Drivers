/*
 * File: exter_int.c
 *
 * Author: Mohamed Sameh
 * 
 */

#include "exter_int.h"

/**
 * @brief 
 * 
 * @param int_num 
 * @param status 
 * @param event 
 */
void exterint_set_status(exterint_t int_num, uint8 status, exterint_event_t event)
{
    switch (int_num)
    {
    case EXTERINT_INT0:
        //disable interrupt 
        GICR &= ~(0b1<<INT0);
        //select the event
        MCUCR &= ~(11<<ISC00);
        MCUCR |= event << ISC00;
        //clear flag
        GIFR |= 0b1<<INTF0;
        //enable interrupt
        GICR |= (0x01&status) << INT0;
        break;
        
    case EXTERINT_INT1:
        GICR &= ~(0b1<<INT1);
        //select the event
        MCUCR &= ~(11<<ISC10);
        MCUCR |= event << ISC10;
        //enable interrupt
        GIFR |= 0b1<<INTF1;
        GICR |= (0x01&status) << INT1;
        /* code */
        break;
    case EXTERINT_INT2:
        GICR &= ~(0b1<<INT2);
        MCUCSR &= ~(0b1<<ISC2);
        MCUCSR |= (event&0b01)<<ISC2;
        GIFR |= 0b1<<INTF2;
        GICR |= (0x01&status) << INT2;
        break;
    
    default:
        break;
    }
}