#ifndef __TIMER_H_
#define __TIMER_H_

#include <stdint.h>



typedef enum{
    TIMER0,
    TIMER1,
    TIMER2,
}timer_t;


typedef enum{
    NORMAL = 0,
    PWM,
    CTC,
    FAST_PWM
}timer_output_t;

typedef enum{
    TIMER_NO_CLKSRC,
    TIMER_PRESC_1,
    TIMER_PRESC_8,
    TIMER_PRESC_64,
    TIMER_PRESC_256,
    TIMER_PRESC_1024,
    TIMER_EXTCLK_RISING,
    TIMER_EXTCLK_FALLING,
}timer_clksrc_t;

typedef enum{
    CTC_PIN_DISCONNECTED,
    CTC_PIN_TOGGLE,
    CTC_PIN_CLR,
    CTC_PIN_SET,
}ctc_outmode_t;


typedef struct
{
    //timer_mode_t mode;
    timer_output_t output_mode;
    timer_clksrc_t  clksrc;
    uint8_t int_state;   // 0 / 1
}timer_config_t;


void timer0_init();
uint8_t timer0_get_counter();
void timer0_deinit();

#endif
