#ifndef IRQ_H
#define IRQ_H
#include <Arduino.h> 

#ifdef USE_ROGER_CORE
void irq_handler(void);
#endif

#ifdef USE_STM32duino_CORE
void irq_handler(HardwareTimer*);
#endif

inline void SID_emulator();
void reset_SID();
void selftest();
void setreg(uint8_t addr,uint8_t data);
uint8_t getPeriod();
uint8_t getMultiplier();

#endif
