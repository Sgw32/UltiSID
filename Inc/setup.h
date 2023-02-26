#include <stdint.h>
#include "stm32f1xx_hal.h"
#ifndef  SETUP_H
#define  SETUP_H

#define  AUDIO_OUT       PA8                        // can't be changed, this is just reminder
#define  CS PB3
#define  RW PB4

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

int micros(void);

void delay(int i);

/*
PB6-13 DATA
PA9-15 ADDRESS
*/

#endif
