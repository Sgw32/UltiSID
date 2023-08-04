# UltiSID

Open source SID 8580/6581 emulator that can be executed on Kung Fu Flash and new Kung Fu SID hardware

License - GNU General Public License v3 (derived from Bakisha STM32 SID player)

## Introduction

Project is heavily inspired by __SwinSID__ and __ArmSID__ project. And is maintained as an open-source alternative to them.
Now it is even working on a GD32F405RGT6 on 168 MHz with 8 MHz crystal, just like Kung Fu Flash - and firmware is using critical code from KFF. 
I'm looking for contributers(I can even pay for the work) who will add some assembler optimization magic into SID code. 

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
* Pavel Myasnikov
Author of KungFuSID hardware design 
* Special greetings to Protovision Games

## Future plans

STM32F103 has a very long delay between CS fall down and interrupt routine begin - about 200ns. With a 500 ns window at all. 
I plan migrating to STM32F405RCT6(still, very cheap on Aliexpress) my PCB also supports it. Also, I should optimize RW&CS routines to enhance performance.

## Limitations

* Pitch is not calibrated
* ADSR attack works somewhat slow
* Data readings are not correct at event-intensive tunes(where there are a lot of write-to-SID activities)
* No 6581/8580 switch
* No paddles(can be done though)

## Support us

Paypal is now blocked in Russia, unfortuntaly I have no residence permit in other countries, where paypal is working.
Crypto: 
0xeDc17cb23241eACe19DF3617291aa7d2d92E62DC (ETH, USDT ERC20)
Buy something here (3d models):
https://www.cgtrader.com/sgw32

## Video(and audio) 

## New video:
https://youtube.com/shorts/YMMjhMZqSjQ?feature=share

Old video:

[![UltiSID](https://img.youtube.com/vi/_ROxem-S0Jo/0.jpg)](https://www.youtube.com/watch?v=_ROxem-S0Jo)

