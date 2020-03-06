#include "lcd.h"
#include "keypad.h"
#include "uart.h"
#include "i2c.h"
int main(void)
{
    LCD_init();
    // UART_init();
    uint8 r;
    while (1)
    {
        // Memmory address (3 bits block number) + 1010

        // UART_receiveByte(&r);
        LCD_displayCharacter('r');
        _delay_ms(500);
        // UART_sendByte('s');
    }
    return 0;
}
