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

void setup() {
  InitHardware(); // 2_setup.ino  (start SID emulator)
  reset_SID(); // in 6_barebone_sounds.ino
}


void loop() {
  selftest();
  Serial.print(" ok ");
  Serial.print("Period:");
  Serial.println(getPeriod());
  Serial.print("Multiplier:");
  Serial.println(getMultiplier());
}
