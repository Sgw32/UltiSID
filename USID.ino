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


long long int tmr = micros();


#ifdef USE_STM32duino_CORE
HardwareTimer *PWM = new HardwareTimer(TIM1); // need to set it up here, before setup{}
#endif

void setup() {
  initPorts();
  InitHardware(); // 2_setup.ino  (start SID emulator)
  reset_SID(); // in 6_barebone_sounds.ino
  selftest();
  
  Serial.print(" ok ");
  Serial.print("Period:");
  Serial.println(getPeriod());
  Serial.print("Multiplier:");
  Serial.println(getMultiplier());
  pinMode(PC13,OUTPUT);
  digitalWrite(PC13,LOW);
}

void printBinary(byte inByte)
{
  for (int b = 7; b >= 0; b--)
  {
    Serial.print(bitRead(inByte, b));
  }
}

void loop() {
  if ((micros()-tmr)>getMultiplier())
  {
    irq_handler();
    tmr = micros();
  }
  //digitalWrite(PC13,LOW);
  //delay(1000);
  /*Serial.print((getAddrLines()&0xFF00)>>8, BIN); 
  Serial.print(getAddrLines()&0xFF, BIN); 
  Serial.print("\t"); 
  
  Serial.print((getDataLines()&0xFF00)>>8, BIN); 
  Serial.println(getDataLines()&0xFF, BIN); */
  /*uint16_t addr = getAddrLines();
  uint16_t data = getDataLines();
  if (addr)
  {
    printBinary((addr&0xFF00)>>8); 
    printBinary(addr&0xFF); 
    Serial.print(" ");
    printBinary((data&0xFF00)>>8); 
    printBinary(data&0xFF); 
    Serial.println();
    //delay(10);
  }*/
  process();
  
}
