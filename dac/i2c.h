#ifndef I2C_H_
#define I2C_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define MT_ST_SENT  (0x08)
#define MT_RST_SENT (0x10)
#define MT_SLA_ACK  (0x18)
#define MT_DATA_ACK (0x28)

void I2C_init(void);
void I2C_MasterTransmit(uint8 a_data, uint8 a_address)
uint8 I2C_receiveByte(uint8 *a_data, uint8 a_address)
void I2C_sendString(const uint8 *a_Str);
void I2C_receiveString(uint8 * a_Str);
#endif