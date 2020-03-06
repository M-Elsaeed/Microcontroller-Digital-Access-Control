#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define UART_RX_ERROR 0x00;
#define UART_RX_SUCCESS 0x01;

void UART_init(void);
void UART_sendByte(uint8 a_data);
uint8 UART_receiveByte(uint8 *a_data);
void UART_sendString(const uint8 *a_Str);
void UART_receiveString(uint8 * a_Str);
#endif