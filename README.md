avr_boot
========

SD card Bootloader for atmega processors

As easy as it can get! I spent days with this. Hopefully you wont!

- for any ATMega with SD Card
- Petit FatFs R0.03 for FAT16 && FAT32
- 4096kB Bootloader required
- CRC Check or EEprom can be easily added - look into main.c

...*BUT* I prefere to keep things simple. Instead of an elaborate versioning systems avr_boot checks on one filename and will reflash as long as it finds this filename. This is not a problem since, it happens nearly instantly and only differing bytes are flashed.
You may put the logic as well into the application (which you want to distribute) and delete or rename the firmware file.


# Usage

This is with avr-gcc and avrdude under linux with an Atmega1284p! Adaption to your case (WinAvr) will not be too complicated...

- adapt Makefile
  - MCU_TARGET: Your AtmegaXXX (maybe not relevant?)
  - BOOT_ADR: in bytes not words.
  - F_CPU:  CPU Frequency
  - USE_LED: For debugging clues
- adapt pins in asmfunc.S
- adapt pff/src/pffconfh.h
- adapt filename of firmware (now FIRMWARE.BIN) in main.c 
- make clean
- make
- set fuses: avrdude -c avrispmkII -p m1284p -U hfuse:w:0xda:m
  - find high fuse in http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega1284p 
- flash: avrdude -c avrispmkII -p m1284p -Uflash:w:./avr_boot.hex:i -Ulock:w:0x3F:m 
- get your app.cpp.hex (out of /tmp/buildxxx in case of Arduino IDE)
- make bin file: avr-objcopy -I ihex -O binary app.cpp.hex FIRMWARE.BIN
- copy the file into the root of an SD (FAT12/FAT16/FAT32)
- it might already have happen!. Flashing is nearly instantly (unless USE_LED=1)

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
