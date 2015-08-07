avr_boot
========

SD card Bootloader for atmega processors

based on the bootloader example from petitfilesystem (http://elm-chan.org/fsw/ff/00index_p.html)
modified by Wilfried Klaas for the MCSDepthLogger Hardware Logger.
- desired platform ATMega328P with attached SD Card standard connection (MOSI, MISO...)
- names of firmware files will be OSMFWxxx.BIN, will be programmed, if xxx > EEPROM-Version number. 
  If no EEPROM Version number is present 12 is the magic number.
  if not, file will be ignored. The next version must be within 10 version numbers. 
  (Files will be testet from EEPROM Version + 10 down to EEPROM Version + 1)
  if nothing is found at last a file name OSMFIRMW.BIN will be testet and programmed, if present.
- In the firmware setup routine the actual version is written into the EEPROM.
- a small java program helps to convert the hex file to a bin file.


Folder pff contains the unmodified library from http://elm-chan.org/fsw/ff/00index_p.html
Only diskio.c was adapted and put in the root dir.
Some Settings in pffconf.h were made.

make clean
make

//set fuses for 4096kb
avrdude -c avrispmkII -p m1284p -U hfuse:w:0xda:m 
//flash file (without lock)
avrdude -c avrispmkII -p m1284p -Uflash:w:./avr_boot.hex:i -Ulock:w:0x3F:m 
