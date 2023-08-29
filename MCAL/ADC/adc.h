/*
 * File: adc.h
 *
 * Author: Mohamed Sameh
 * 
 */


#ifndef _ADC_H_
#define _ADC_H_

/* -------------- Includes -------------- */
#include"../../LIBRARY/Platform_Types.h"
#include "adc_config.h"

/* -------------- Macro Declarations ------------- */

/* -------------- Macro Functions Declarations --------------*/

/* -------------- Data Types Declarations --------------  */
typedef enum{
    ADC_AUTORUN,
}adc_trigger_t;

/* -------------- Functions Declarations --------------*/
/**
 * @brief 
 * 
 */
void adc_init(void);

/**
 * @brief 
 * 
 * @param channel 
 */
void adc_select_channel(uint8 channel);
void adc_set_trigger(uint8 state);
void adc_select_trigger(adc_trigger_t trigger);
void adc_start_conv();
uint8 adc_is_dataready();
uint16 adc_get_data();


#endif