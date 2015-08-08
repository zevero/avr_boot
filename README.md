avr_boot
========

SD card Bootloader for atmega processors

As easy as it can get! I spent days with this. Hopefully you wont!

- for any ATMega with 4096kb Bootloader
- uses Petit FatFs R0.03 for FAT16 && FAT32
- looks for FIRMWARE.BIN and flashes it nearly instantly
- without any interference to your application
- simple check before starting your application or retry every 5 seconds
- no CRC Check and no version bytes in EEPROM (see More...)

# Usage

This is with avr-gcc and avrdude under linux with an Atmega1284p! Adaption to your case (WinAvr) will not be too complicated...

- adapt Makefile
  - MCU_TARGET: Your AtmegaXXX
  - BOOT_ADR: in bytes not words!
  - F_CPU:  CPU Frequency
  - USE_LED: For debugging 0...deactivate or 1...active
  - USE_UART: For debugging 0...deactivate or divider for baudate see http://wormfood.net/avrbaudcalc.php
- adapt pins in asmfunc.S
- adapt pff/src/pffconfh.h
- adapt filename of firmware (now FIRMWARE.BIN) in main.c 
- make
- set fuses: avrdude -c avrispmkII -p m1284p -U hfuse:w:0xda:m
  - find high fuse in http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega1284p
- flash: avrdude -c avrispmkII -p m1284p -Uflash:w:./avr_boot.hex:i -Ulock:w:0x3F:m 
- get your app.cpp.hex (out of /tmp/buildxxx in case of Arduino IDE)
- make bin file: avr-objcopy -I ihex -O binary app.cpp.hex FIRMWARE.BIN
- copy the file into the root of an SD (FAT12/FAT16/FAT32)
- put it into the SD slot of your Atmega
- reset it
- it might already have happend!

# Bootloader size
 - 3540 bytes
 - 3852 bytes debugging with USE_LED
 - 3934 bytes debugging with USE_UART
 - 4240 bytes debugging with USE_LED and USE_UART (does not fit in 4096)

# More ...
 ... if you wish you *can* add CRC Check or versioning with EEPROM *but* I prefere to keep things simple. avr_boot will reflash your FIRMWARE.BIN as long as it is present.
Is this a problem? No! It happens nearly instantly and only differing bytes are flashed really.
You may consider putting your logic into your application and perform a CRC Check after the fact to inform the user and deleting or renaming FIRMWARE.BIN

# Thanks to
- http://elm-chan.org/fsw/ff/00index_p.html
- Wilfried Klaas for the MCSDepthLogger https://github.com/willie68/OpenSeaMapLogger
- https://github.com/mharizanov/avr_boot
- https://github.com/osbock/avr_boot
- and others???

# Alternatives

- https://spaces.atmel.com/gf/project/sdbootloader/
- https://github.com/thseiler/embedded/tree/master/avr/2boots
- http://www.mikrocontroller.net/articles/MMC/SD_Bootloader_f%C3%BCr_AT_Mega

... call me stupid, but I passed several days debugging those - without success ...
