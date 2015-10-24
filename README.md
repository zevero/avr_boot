avr_boot
========

SD card Bootloader for atmega processors

As easy as it can get! I spent days with this. Hopefully you wont!

- for any ATMega with 4096kb Bootloader
- uses Petit FatFs R0.03 for FAT12, FAT16, FAT32
- looks for FIRMWARE.BIN and flashes it nearly instantly
- without any interference to your application
- no CRC Check and no version bytes in EEPROM (see KISS)

# Compile and Flash avr_boot bootloader (only once)

This is with avr-gcc and avrdude under linux with an Atmega1284p and avrIsp mkII! Adaption to your case (WinAvr, another Atmega, another flash-tool) will not be complicated...

- adapt Makefile
  - MCU_TARGET: Your AtmegaXXX
  - BOOT_ADR: in bytes not words!
  - F_CPU:  CPU Frequency
  - USE_LED: For debugging 0...deactivate or 1...active
  - USE_UART: For debugging 0...deactivate or divider (UBRR) for baudate see http://wormfood.net/avrbaudcalc.php
- if using USE_LED adapt LED-pins in asmfunc.S
- if you want to add FAT12 adapt pff/src/pffconfh.h (default ist FAT16 + FAT32)
- if you prefer another filename instead of FIRMWARE.BIN adapt main.c 
- make (you may need to do "sudo apt-get install avr-libc gcc-avr")
- set fuses: avrdude -c avrispmkII -p m1284p -U hfuse:w:0xda:m
  - find high fuse in http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega1284p
- flash: avrdude -c avrispmkII -p m1284p -Uflash:w:./avr_boot.hex:i -Ulock:w:0x3F:m 

# Compile and put your sketch on SD Card 

- in Arduino IDE go to File > Preferences and check "Show verbose output during compiliation"
- compile sketch and find the location of your /tmp/buildxxx/sketch.cpp.hex
- make bin file: avr-objcopy -I ihex -O binary sketch.cpp.hex FIRMWARE.BIN
- copy the file into the root of an SD (FAT12/FAT16/FAT32)
- put it into the SD slot of your Atmega
- reset it
- it might already have happend!

# Bootloader size
 - 3700 bytes
 - 4010 bytes debugging with USE_LED
 - ? bytes debugging with USE_UART (does not compile any more - please help)

# Serial support - Help wanted
it should not be so difficult to fit a normal serial bootloader (with automatic baudrate detection?) into the remaining 500 bytes ... help is appreciated!

# KISS
If you wish you *can* add CRC Check or versioning with EEPROM *but* I prefere to keep things simple. avr_boot will reflash your FIRMWARE.BIN as long as it is present.
Is this a problem? No! It happens nearly instantly and only differing bytes are flashed really.
You may consider putting your logic into your application and perform a CRC Check after the fact to inform the user and delete or rename FIRMWARE.BIN

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
