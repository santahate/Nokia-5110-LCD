#ifndef __LCD5110_H
#define __LCD5110_H

#include "spi.h"
#include "gpio.h"
#include "lcd_ascii.h"

//The DC pin tells the LCD if we are sending a command or data
#define LCD_COMMAND 0 
#define LCD_DATA 1

//You may find a different size screen, but this one is 84 by 48 pixels
#define LCD_X 84
#define LCD_Y 48
//------------------------------------------------------------------------
//---------------------- IMPORTANT FOR CONNECTION: -----------------------
#define PIN_RST GPIO_PIN_0
#define PIN_CE GPIO_PIN_3
#define PIN_DC GPIO_PIN_1
//------------------------------------------------------------------------

void lcd_init();
void lcd_gotoXY(uint8_t X, uint8_t Y);
void lcd_clear();
void lcd_char(uint8_t c);
void lcd_set_inverse(uint8_t inverse);
void lcd_string(uint8_t *str);





#endif

