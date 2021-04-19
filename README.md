# UltiSID

Open source SID 8580/6581 emulator that can be executed on Bluepill boards and STM32F103

License - GNU General Public License v3 (derived from Bakisha STM32 SID player)

## Introduction

Project is heavily inspired by __SwinSID__ and __ArmSID__ project. And is maintained as an open-source alternative to them.
Now it is even working on a STM32F103C8T6 on an overclocked freq 128 MHz with 8 MHz crystal. With some errors in behavior - some readings are missing. 
I'm looking for contributers(I can even pay for the work) who will add some assembler optimization magic into my code. 
Also I plan releasing Altium Designer PCB hardware files publicly available right after I'll sell 10 copies of UltiSIDs to public. 

Working in a time-stretched and computation-intensive environment of C64 requires hardcore optimization of code. __Project is still in a very early stage of development__

Why UltiSID? Why Ulti? I think that open-source contributions make our planet better, and since, the open-source alternative to SwinSID and ArmSID is still better than closed solutions. 
In 2021 there are still no any good SID emulators publicly available. 2021, Carl!

## Credits and special thanks:

* Tolaemon's NanoSwinSID page with open-hardware PCB available: http://www.tolaemon.com/nss/ 
My PCB is a modified version of SwinSID PCB

* ArmSID page with schematic: https://www.nobomi.cz/8bit/armsid/index_en.php
* Teensy SID emulator (huuuge, not really good): https://www.pjrc.com/c64-sid-chip-replacement/ and https://github.com/kokotisp/6581-SID-teensy
* SID BluePill emulators:
https://github.com/Bakisha/STM32-SID-PLAYER - my code is 80% based on this repository
https://github.com/dkm1978/BluePillSid - references
* Swinkels page - dead http://www.swinkels.tvtom.pl/swinsid/
Available on Archive.org - please check it, there is a SID emulation source for SwinSID atmega8515.
* Kung Fu Flash - https://github.com/KimJorgensen/KungFuFlash
I am inspired by simplicity of it and its power. 
* Special greetings to Protovision Games

## Future plans

STM32F103 has a very long delay between CS fall down and interrupt routine begin - about 200ns. With a 500 ns window at all. 
I plan migrating to STM32F405RCT6(still, very cheap on Aliexpress) my PCB also supports it. Also, I should optimize RW&CS routines to enhance performance.

## Limitations

* We have a 256b buffer for SID data, and it is processed in main cycle. Seems enough, but sometimes I hear that it is not. 
* Pitch is not calibrated
* Data readings are not correct at event-intensive tunes(where there are a lot of write-to-SID activities)
* No 6581/8580 switch
* No paddles(sorry, no reads)

## Support us

PayPal Me:
https://paypal.me/sgw32
Or buy something here (3d models):
https://www.cgtrader.com/sgw32

## Video(and audio) PoC

[![UltiSID](https://img.youtube.com/vi/_ROxem-S0Jo/0.jpg)](https://www.youtube.com/watch?v=_ROxem-S0Jo)

