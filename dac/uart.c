#include "uart.h"
// ENABLE I BIT
// UDR TO READ AND WRITE
// UCSRA SET UX2
// UCSRB SET RXCIE, RXEN, TXEN
// UCSRC SET URSEL, UPM1 "CHECK PE Flag in UCSRA ON RECEIVE OF ANY BIT", UCSZ1, USCZ0
void UART_init(void)
{

    SET_BIT(UCSRA, U2X); // Double baud rate mode

    SET_BIT(UCSRB, RXEN); // Enabling Receive
    SET_BIT(UCSRB, TXEN); // Transfer Transfer

    SET_BIT(UCSRC, URSEL); // Enables writing in UCSRC
    SET_BIT(UCSRC, UPM1);  // Adding Even Parity to each frame
    SET_BIT(UCSRC, UCSZ0); // For 8-bit data mode
    SET_BIT(UCSRC, UCSZ1); // For 8-bit data mode
}

void UART_sendByte(uint8 a_data)
{
    while (BIT_IS_CLEAR(UCSRA, UDRE)) // Checking if transmission buffer is clear.
        ;                           // If not, poll.
    UDR = a_data;
}

uint8 UART_receiveByte(uint8 *a_data)
{
    while (BIT_IS_CLEAR(UCSRA, RXC)) // Checking if reception buffer is clear.
        ;                            // If yes, poll.
    if (BIT_IS_SET(UCSRA, PE))
    {
        *a_data = 0xFF;
        return UART_RX_ERROR;
    }
    else
    {
        *a_data = UDR;
        return UART_RX_SUCCESS;
    }
}

void UART_sendString(const uint8 *a_Str)
{
    uint32 i = 0;
    while (a_Str[i] != '\0')
    {
        UART_sendByte(a_Str[i++]);
    }
    UART_sendByte('~');
}

void UART_receiveString(uint8 * a_Str)
{
    uint8 i = 0;
    uint8 c;
    UART_receiveByte(&c);
    while (c != '~')
    {
        a_Str[i++] = c;
        UART_receiveByte(&c);
    }
    a_Str[--i] = '\0';
}
