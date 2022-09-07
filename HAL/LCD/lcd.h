/*
 * lcd.h
 *
 *      Author: ASHRAF
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include <stdint.h>

void lcd_init(void);
void lcd_send_cmd(uint8_t command);
void lcd_send_data(char data); 
void lcd_set_curser(uint8_t x, uint8_t y);
void lcd_send_str(char str[]);
void lcd_set_specialcharc(uint8_t arr[], uint8_t block_num);
void lcd_send_specialcharc(uint8_t block_num, uint8_t x, uint8_t y);


#endif /* LCD_LCD_H_ */
