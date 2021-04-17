#ifndef IRQ_H
#define IRQ_H

void irq_handler(void);

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
void SID_emulator();
void reset_SID();
void beep();
void selftest();
void setRW(uint32_t dataidr);
void setreg(uint8_t addr,uint8_t data);
uint8_t getPeriod();
uint8_t getMultiplier();
void InitHardware();

extern uint32_t address_lines16_p;
extern uint32_t data_lines16_p;
extern uint32_t data_buffer[255];
extern uint32_t address_buffer[255];
extern uint8_t	readIndex;
extern uint8_t	writeIndex;
extern uint8_t	bufferLength;


#endif
