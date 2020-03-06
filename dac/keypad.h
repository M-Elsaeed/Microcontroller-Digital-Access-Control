/*
 * keypad.h
 *
 *  Created on: Oct 9, 2019
 *      Author: Mohammed Ehab
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define KEYPAD_PORT_OUT PORTC
#define KEYPAD_PORT_IN PINC
#define KEYPAD_PORT_DIR DDRC

uint8 KEYPAD_getKeyPressed(void);

#endif /* KEYPAD_H_ */
