#include "usid.h"

void setup() {

	InitHardware(); // 2_setup.ino  (start SID emulator)
    reset_SID(); // in 6_barebone_sounds.ino
}

void delay(int i)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(i);
}

