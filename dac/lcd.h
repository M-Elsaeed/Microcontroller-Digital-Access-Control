/*
 * lcd.h
 *
 *  Created on: Oct 9, 2019
 *      Author: Mohammed Ehab
 */

#ifndef LCD_H_
#define LCD_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define DATA_BITS_MODE 8

#define RS PB2
#define RW PB1
#define E  PB0
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_PORT_DIR DDRB

#define LCD_DATA_PORT PORTA
#define LCD_DATA_PORT_DIR DDRA


#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_ON 0x0E
#define DSIPLAY_ON_CURSOR_OFF 0x0C
#define SET_CURSOR_LOCATION 0x80

void LCD_init(void);
void LCD_sendCommand(uint8 a_command);
void LCD_displayCharacter(uint8 a_data);
void LCD_displayString(const uint8 *a_Str);
void LCD_goToRowColumn(uint8 a_row,uint8 a_col);
void LCD_displayStringRowColumn(uint8 a_row,uint8 a_col,const uint8 *a_Str);
void LCD_clearScreen(void);
void LCD_IntegerToString(int a_data);

#endif /* LCD_H_ */
