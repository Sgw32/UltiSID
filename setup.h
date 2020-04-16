#ifndef  SETUP_H
#define  SETUP_H

#define  AUDIO_OUT       PA8                        // can't be changed, this is just reminder
#define  CS PB3
#define  RW PB4

/*
PB6-13 DATA
PA9-15 ADDRESS
*/


// core detector
#ifdef  USE_HAL_DRIVER // Official ST cores. Support for multiple line of MPU
#define  USE_STM32duino_CORE //  Set in preferences: https://github.com/stm32duino/BoardManagerFiles/raw/master/STM32/package_stm_index.json and search stm32 in board manager. Choose stm32 cores by ST Microelectronics. Select your CPU from tools menu)
#else
#define  USE_ROGER_CORE //  Set in preferences: http://dan.drown.org/stm32duino/package_STM32duino_index.json and search stm32F1 in board manager. Choose STM32F1xx core (NOTE: Only STM32F1 works)
#endif

#endif
