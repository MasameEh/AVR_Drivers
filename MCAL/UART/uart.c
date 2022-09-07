#include <avr/io.h> 
#include "uart.h"


#define SET_BIT(reg, bit_n)   reg|= 1<<bit_n
#define CLR_BIT(reg, bit_n)   reg&= ~(1<<bit_n)
#define GET_BIT(reg, bit_n)   ((reg>>bit_n)&1)

void (*g_tx_cb)(void);

ISR(USART_TXC_vect)
{
    if(g_tx_cb)
    {
        g_tx_cb();
    }
}

void (*g_rx_cb)(void);

ISR(USART_RXC_vect)
{
    if(g_rx_cb != 0)
    {
        g_rx_cb();
    }
}

void uart_init()
{

    //enabling the transmitter, receiver
    UCSRB = (1<<RXEN) | (1<<TXEN);
    
    //data size
    CLR_BIT(UCSRB, UCSZ2);
    uint8_t ucsrc_value = 0;
    SET_BIT(ucsrc_value, UCSZ1);
    SET_BIT(ucsrc_value, UCSZ0);
    
    //Async
    CLR_BIT(ucsrc_value, UMSEL);
    
    //parity mode
    CLR_BIT(ucsrc_value, UPM0);
    CLR_BIT(ucsrc_value, UPM1);
    
    //stop bit select
    CLR_BIT(ucsrc_value,USBS);

    UCSRC = 1<<URSEL| ucsrc_value;
    
    //interrupts
    CLR_BIT(UCSRB, RXCIE);
    CLR_BIT(UCSRB, TXCIE);
    CLR_BIT(UCSRB, UDRIE);
    
    //baud rate
    UBRRL = 51;
    UBRRH = 0x00;
    
}

uint8_t uart_receive_data()
{
 return UDR;
}


void uart_send_data(uint8_t data)
{
    while( GET_BIT(UCSRA, UDRE) != 1 );
    UDR = data;
}

uint8_t uart_isdata_ready()
{
    return GET_BIT(UCSRA,RXC);
}

void uart_sendstring(char* str)
{
    uint8_t i = 0;
    while (str[i] != '\0')
    {   
        //wait for data register being empty
        //while(GET_BIT(UCSRA, UDRE) != 1);
        //UDR = str[i];
        uart_send_data(str[i]);
        i++;
    }
}

void uart_receive_string(char* str, uint8_t length,char terminate)
{
    uint8_t i = 0;
    do
    {
        while(uart_isdata_ready() != 1);

        str[i] = uart_receive_data();
        i++;
    }while (i < length && str[i-1] != terminate);
    i--;
    str[i] = 0;
}

void uart_set_tx_callback(void(*callback)(void))
{

}
void uart_set_rx_callback(void(*callback)(void));
