#include "setup.h"
#include "IRQ.h"

// INFO:


// This project is purely for my own entertainment , so WITHOUT ANY WARRANTY!
// SCHEMATICS:
//
//
//    .-----------------.
//    |                 |
//    | STM32FxxxXXxx   |
//    .------------|----.
//     |G         P|
//     |N         A|
//     |D         8--R1----|------C2---------|
//     |                   |                 --
//     |                   C                 || P1
//     |                   1                 ||<--------- OUDIO OUT
//     |                   |                 --
//     .-------------------|------------------|---------- GND
//                        GND
//    R1 = 100-500 Ohm
//    C1 = 100 nF
//    C2 = 10 uF
//    P1 = 10KOhm potentiometer
//
// If <period> is 1 , AUDIO OUT can be connected to PA8 (no need for R1,C1 ). I don't think 1Mhz sample rate will be in hearing range





#ifdef USE_STM32duino_CORE
HardwareTimer *PWM = new HardwareTimer(TIM1); // need to set it up here, before setup{}
#endif


uint8_t address_lines;
uint8_t data_lines;

#define PORTC_PDIR GPIOC_PDIR
#define pinCountC 8
uint8_t portPinsC[pinCountC] = {15, 22, 23, 9, 10, 13, 11, 12}; // Port C bits D0, D1, D2, D3, D4, A5, CS, RW - These are pin numbers used on teensy

//A5 signal can be found on pin 12 of the cpu.At this point is not needed.
//All other connections go to sid chip. Please refer to 6581 sid datasheet fo details

#define PORTD_PDIR GPIOD_PDIR
#define pinCountD 8
uint8_t portPinsD[pinCountD] = {2, 14, 7, 8, 6, 20, 21, 5}; // Port D bits A0, A1, A2, A3, A4, A5, A6, A7

void ReadLines() {

// Reading address and data lines of sid chip
     address_lines = GPIOC->regs->IDR;//PORTC_PDIR ;//& B00011111 ;
     data_lines = GPIOD->regs->IDR;//PORTD_PDIR ;

      // If both RW and CS signals are LOW 
      if ((address_lines &  B11000000) < 0x01 ){
        //Check if note is for SID at $d4200
        if ((address_lines &  B00100000) < 0x01){
          setreg(address_lines &  B00011111 ,data_lines);
      // Send data to reSID. 
        //playSID.setreg(address_lines &  B00011111 ,data_lines);
       // playSID1.setreg(address_lines &  B00011111 ,data_lines);
      }
      else {
        //playSID1.setreg(address_lines &  B00011111 ,data_lines);
      }
  }
}

inline void InitHardware() { // setup pins and IRQ
  // init irq
  noInterrupts();
  //pinMode(BUTTON_1, INPUT_PULLUP);
#ifdef  USE_ROGER_CORE

  pinMode (AUDIO_OUT, PWM); //   audio output pin

  Timer1.setPeriod(getPeriod());

  Timer2.setPrescaleFactor(1);
  Timer2.setMode(TIMER_CH2, TIMER_OUTPUTCOMPARE);
  Timer2.setPeriod(getMultiplier());
  Timer2.setCompare(TIMER_CH2, 1);
  Timer2.attachInterrupt(TIMER_CH2, irq_handler);
#endif

#ifdef USE_STM32duino_CORE
  pinMode(AUDIO_OUT, OUTPUT);

  PWM->pause();
  PWM->setMode(1, TIMER_OUTPUT_COMPARE_PWM1, PA8);
  PWM->setPrescaleFactor(1);
  PWM->setOverflow( period * magic_number, TICK_FORMAT);
  PWM->resume();


  HardwareTimer *IRQtimer = new HardwareTimer(TIM2);
  IRQtimer->setMode(2, TIMER_OUTPUT_COMPARE);
  IRQtimer->setOverflow(multiplier, MICROSEC_FORMAT);
  IRQtimer->attachInterrupt(irq_handler);
  IRQtimer->resume();
#endif

  // Setting PORTC and PORTD pins as inputs
  for (int a=0; a<pinCountC; a++) {
    pinMode(portPinsC[a], INPUT);
  }
    for (int a=0; a<pinCountD; a++) {
    pinMode(portPinsD[a], INPUT);
  }
  
  // Attach an interrupt when RW goes LOW. Seems to work well.
  attachInterrupt(digitalPinToInterrupt(RW), ReadLines, FALLING );
  

  interrupts();
}

void setup() {
  InitHardware(); // 2_setup.ino  (start SID emulator)
  reset_SID(); // in 6_barebone_sounds.ino
}


void loop() {
  selftest();
  Serial.print(" ok ");
}
