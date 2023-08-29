/*
 * File: adc.c
 *
 * Author: Mohamed Sameh
 * 
 */

#include "adc.h"

/**
 * @brief 
 * 
 */
void adc_init(void)
{
    //
    ADMUX &= ~(0b11<<REFS0);
    ADMUX |= ADC_REF_VALUE<<REFS0;

    ADMUX &= ~(0b1<<ADLAR);

    ADCSRA = 0;
    ADCSRA |= ADC_AUTO_TRIGGER<<ADATE;
    ADCSRA |= ADC_INT_ENABLE<<ADIE;
    ADCSRA |= ADC_PRESCALAR_SEL<<ADPS0;
 
    //enable adc
    ADCSRA |= 0b1<<ADEN;
}

/**
 * @brief 
 * 
 * @param channel 
 */
void adc_select_channel(uint8 channel)
{
    ADMUX &= ~(0b11111<<MUX0);
    ADMUX |= channel<<MUX0;
}

/**
 * @brief 
 * 
 * @param state 
 */
void adc_set_trigger(uint8 state)
{
    if(state == 0)
    {
        ADCSRA &= ~(0b1<<ADATE);
    }
    else
    {
        ADCSRA |= 0b1<<ADATE;
    }
}

/**
 * @brief 
 * 
 * @param trigger 
 */
void adc_select_trigger(adc_trigger_t trigger)
{
    SFIOR &= ~(0b111<<ADTS0);
    SFIOR |= trigger<<ADTS0;
}

/**
 * @brief 
 * 
 */
void adc_start_conv()
{
    ADCSRA |= 0b1<<ADSC;
}

/**
 * @brief 
 * 
 * @return uint8 
 */
uint8 adc_is_dataready()
{
    uint8 result = 0x01&(ADCSRA>>ADIF);  //read flag
    ADCSRA |= 0b1 <<ADIF;  //clear flag
    return result;
}
uint16 adc_get_data()
{
    uint16 adc_val;
    adc_val = ADCL;
    adc_val |= ADCH << 8;
    return adc_val;
}