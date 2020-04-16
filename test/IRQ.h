#ifndef IRQ_H
#define IRQ_H

#include "SID.h"

#ifdef USE_ROGER_CORE
void irq_handler(void);
#endif

#ifdef USE_STM32duino_CORE
void irq_handler(HardwareTimer*);
#endif

inline void SID_emulator();

#endif
