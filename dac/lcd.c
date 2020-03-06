#include "lcd.h"
void LCD_init(void)
{
	SET_BIT(LCD_CTRL_PORT_DIR, RS);
	SET_BIT(LCD_CTRL_PORT_DIR, RW);
	SET_BIT(LCD_CTRL_PORT_DIR, E);
	LCD_DATA_PORT_DIR = 0xFF;
	_delay_ms(100);
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
	LCD_sendCommand(DSIPLAY_ON_CURSOR_OFF);
	LCD_sendCommand(CLEAR_COMMAND);
}
void LCD_sendCommand(uint8 a_command)
{
	CLEAR_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
	LCD_DATA_PORT = a_command;
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
}
void LCD_displayCharacter(uint8 a_data)
{
	SET_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
	LCD_DATA_PORT = a_data;
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
}
void LCD_displayString(const uint8 *a_Str)
{
	int i = 0;
	while (a_Str[i] != '\0')
	{
		LCD_displayCharacter(a_Str[i]);
		i++;
	}
}
void LCD_goToRowColumn(uint8 a_row, uint8 a_col)
{
	uint8 address;
	switch (a_row)
	{
	case 0:
		address = a_col;
		break;
	case 1:
		address = (0x40) + a_col;
		break;
	default:
		address = a_col;
		break;
	}
	LCD_sendCommand(address | SET_CURSOR_LOCATION);
}
void LCD_displayStringRowColumn(uint8 a_row, uint8 a_col, const uint8 *a_Str)
{
	LCD_goToRowColumn(a_row, a_col);
	LCD_displayString(a_Str);
}
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND);
}
void LCD_IntegerToString(int a_data)
{
//	char buff[16];			/* String to hold the ascii result */
//	itoa(a_data, buff, 10); /* 10 for decimal */
//	LCD_displayString(buff);
}
