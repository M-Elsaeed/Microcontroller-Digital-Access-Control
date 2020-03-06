#include "keypad.h"
static uint8 KEYPAD_adjustKeyValue(uint8 a_address)
{
	switch (a_address)
	{
	case 0:
		return '7';
	case 1:
		return '8';
	case 2:
		return '9';
	case 3:
		return '/';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '*';
	case 8:
		return '1';
	case 9:
		return '2';
	case 10:
		return '3';
	case 11:
		return '-';
	case 12:
		return 'o';
	case 13:
		return '0';
	case 14:
		return '=';
	case 15:
		return '+';
	default:
		return 0;
	}
}
uint8 KEYPAD_getKeyPressed(void)
{
	uint8 col, row;
	while (1)
	{
		for (col = 0; col < 3; col++)
		{
			KEYPAD_PORT_DIR = (1 << col);
			KEYPAD_PORT_OUT = ~(1 << col);
			for (row = 0; row < 3; row++)
			{
				if (BIT_IS_CLEAR(KEYPAD_PORT_IN, (row + 4)))
				{
					// for debouncing.
					while(BIT_IS_CLEAR(KEYPAD_PORT_IN, (row + 4)));
					return KEYPAD_adjustKeyValue((row * 4) + col);
				}
			}
		}
	}
}
