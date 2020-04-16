#ifndef IRQ_H
#define IRQ_H
#include <Arduino.h> 

#ifdef USE_ROGER_CORE
void irq_handler(void);
#endif

#ifdef USE_STM32duino_CORE
void irq_handler(HardwareTimer*);
#endif

#define PORTC_PDIR GPIOC_PDIR
#define pinCountC 8

//A5 signal can be found on pin 12 of the cpu.At this point is not needed.
//All other connections go to sid chip. Please refer to 6581 sid datasheet fo details

#define PORTD_PDIR GPIOD_PDIR
#define pinCountD 8

void ReadLines();

void initPorts();
void process();
uint16_t getAddrLines();
uint16_t getDataLines();
inline void SID_emulator();
void reset_SID();
void selftest();
void setreg(uint8_t addr,uint8_t data);
uint8_t getPeriod();
uint8_t getMultiplier();
void InitHardware();

#endif
