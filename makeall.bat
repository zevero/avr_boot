@echo off
@echo making avr_boot bootloader files...
path=C:\Program Files (x86)\make;C:\Program Files\avr-gcc-6.1.0-x64-mingw\hardware\tools\avr\bin
make MCU_TARGET=atmega328p BOOT_ADR=0x7000 F_CPU=20000000 CS_PIN=4 USE_LED=0 USE_UART=0 TARGET=atmega328p_cs4 > buildlog.txt 2>&1
make MCU_TARGET=atmega328p BOOT_ADR=0x7000 F_CPU=20000000 CS_PIN=8 USE_LED=0 USE_UART=0 TARGET=atmega328p_cs8 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega328p BOOT_ADR=0x7000 F_CPU=20000000 CS_PIN=10 USE_LED=0 USE_UART=0 TARGET=atmega328p_cs10 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega32u4 BOOT_ADR=0x7000 F_CPU=20000000 CS_PIN=4 USE_LED=0 USE_UART=0 TARGET=atmega32u4_cs4 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega32u4 BOOT_ADR=0x7000 F_CPU=20000000 CS_PIN=8 USE_LED=0 USE_UART=0 TARGET=atmega32u4_cs8 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega32u4 BOOT_ADR=0x7000 F_CPU=20000000 CS_PIN=10 USE_LED=0 USE_UART=0 TARGET=atmega32u4_cs10 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=4 VARIANT_1284P=0 USE_LED=0 USE_UART=0 TARGET=atmega1284p_avrdevelopersstandard_cs4 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=4 VARIANT_1284P=1 USE_LED=0 USE_UART=0 TARGET=atmega1284p_bobuinosleepingbeauty_cs4 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=8 VARIANT_1284P=0 USE_LED=0 USE_UART=0 TARGET=atmega1284p_avrdevelopersstandard_cs8 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=8 VARIANT_1284P=1 USE_LED=0 USE_UART=0 TARGET=atmega1284p_bobuino_cs8 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=8 VARIANT_1284P=2 USE_LED=0 USE_UART=0 TARGET=atmega1284p_sleepingbeauty_cs8 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=10 VARIANT_1284P=0 USE_LED=0 USE_UART=0 TARGET=atmega1284p_avrdevelopersstandard_cs10 >> buildlog.txt 2>>&1
make MCU_TARGET=atmega1284p BOOT_ADR=0x1F000 F_CPU=20000000 CS_PIN=10 VARIANT_1284P=1 USE_LED=0 USE_UART=0 TARGET=atmega1284p_bobuinosleepingbeauty_cs10 >> buildlog.txt 2>>&1
REM make MCU_TARGET=atmega2560 BOOT_ADR=0x3F000 F_CPU=20000000 CS_PIN=4 USE_LED=0 USE_UART=0 TARGET=atmega2560_cs4 >> buildlog.txt 2>>&1
REM make MCU_TARGET=atmega2560 BOOT_ADR=0x3F000 F_CPU=20000000 CS_PIN=8 USE_LED=0 USE_UART=0 TARGET=atmega2560_cs8 >> buildlog.txt 2>>&1
REM make MCU_TARGET=atmega2560 BOOT_ADR=0x3F000 F_CPU=20000000 CS_PIN=10 USE_LED=0 USE_UART=0 TARGET=atmega2560_cs10 >> buildlog.txt 2>>&1
REM make MCU_TARGET=atmega2560 BOOT_ADR=0x3F000 F_CPU=20000000 CS_PIN=53 USE_LED=0 USE_UART=0 TARGET=atmega2560_cs53 >> buildlog.txt 2>>&1
make clean >> buildlog.txt 2>>&1
del *.elf >> buildlog.txt 2>>&1
@pause