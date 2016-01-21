#include "lcd5110.h" 


void lcd_write(uint8_t data_or_command, uint8_t data)
{
	HAL_GPIO_WritePin(GPIOA, PIN_DC, data_or_command);
	
	HAL_GPIO_WritePin(GPIOA, PIN_CE, 0);
	HAL_SPI_Transmit(&hspi1, &data, sizeof(data), 1000);	
	HAL_GPIO_WritePin(GPIOA, PIN_CE, 0);
}

void lcd_init() 
{
	HAL_GPIO_WritePin(GPIOA, PIN_RST, 0);
	HAL_GPIO_WritePin(GPIOA, PIN_RST, 1);
	
	lcd_write(LCD_COMMAND, 0x21); 
	lcd_write(LCD_COMMAND, 0xBF); 
	lcd_write(LCD_COMMAND, 0x04); 
	lcd_write(LCD_COMMAND, 0x13); 	
	
	lcd_write(LCD_COMMAND, 0x20); 
	lcd_write(LCD_COMMAND, 0x0C); 
}

void lcd_gotoXY(uint8_t X, uint8_t Y)
{
		lcd_write(LCD_COMMAND, 0x80|X);
		lcd_write(LCD_COMMAND, 0x40|Y);
}

void lcd_clear()
{
	for (int index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
		{
			lcd_write(LCD_DATA, 0x00);
		}
		lcd_gotoXY(0,0);
}

void lcd_set_inverse(uint8_t inverse)
{
	lcd_write(LCD_COMMAND, inverse?0x0D:0x0C);
}

void lcd_char(uint8_t c)
{
	lcd_write(LCD_DATA, 0x00);
	for (int index = 0 ; index < 5 ; index++)
	{
   lcd_write(LCD_DATA, ASCII[c - 0x20][index]);
	} //0x20 is the ASCII character for Space (' '). The font table starts with this character
	lcd_write(LCD_DATA, 0x00); 
	
}

void lcd_string(uint8_t *str)
{
	uint8_t i=0;
	while(str[i])
	{
		lcd_char(str[i]);
		i++;
	}
}



