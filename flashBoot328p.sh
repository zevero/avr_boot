#! /bin/bash

/home/jadin/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino9/bin/avrdude -C/home/jadin/.arduino15/packages/avr_boot/hardware/avr/1.3.0/avrdude.conf -v -patmega328p -cstk500v1 -P/dev/ttyUSB0 -b19200 -e -Ulock:w:0x3F:m -Uefuse:w:0x05:m -Uhfuse:w:0xD8:m -Ulfuse:w:0xFF:m


/home/jadin/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino9/bin/avrdude -C/home/jadin/.arduino15/packages/avr_boot/hardware/avr/1.3.0/avrdude.conf -v -patmega328p -cstk500v1 -P/dev/ttyUSB0 -b19200 -Uflash:w:./avr_boot.hex:i -Ulock:w:0x0F:m 

