#ifndef IRQ_H
#define IRQ_H

void irq_handler(void);

#define PORTC_PDIR GPIOC_PDIR
#define pinCountC 8

//A5 signal can be found on pin 12 of the cpu.At this point is not needed.
//All other connections go to sid chip. Please refer to 6581 sid datasheet fo details

#define PORTD_PDIR GPIOD_PDIR
#define pinCountD 8

void ReadLines(void);

void initPorts(void);
void process(void);
uint16_t getAddrLines(void);
uint16_t getDataLines(void);
void SID_emulator(void);
void reset_SID(void);
void beep(void);
void selftest(void);
void setRW(uint32_t dataidr);
void setreg(uint8_t addr,uint8_t data);
uint8_t getPeriod(void);
uint8_t getMultiplier(void);
void InitHardware(void);


#endif
