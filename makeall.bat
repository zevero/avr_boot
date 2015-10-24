@echo off
@echo making avr_boot bootloader files...
path=c:\make
make OS=windows ENV=arduino atmega328p_cs4
make OS=windows ENV=arduino atmega328p_cs8
make OS=windows ENV=arduino atmega328p_cs10
make OS=windows ENV=arduino atmega32u4_cs4
make OS=windows ENV=arduino atmega32u4_cs8
make OS=windows ENV=arduino atmega32u4_cs10
make OS=windows ENV=arduino atmega1284p_avrdevelopersstandard_cs4
make OS=windows ENV=arduino atmega1284p_bobuinosleepingbeauty_cs4
make OS=windows ENV=arduino atmega1284p_avrdevelopersstandard_cs8
make OS=windows ENV=arduino atmega1284p_bobuino_cs8
make OS=windows ENV=arduino atmega1284p_sleepingbeauty_cs8
make OS=windows ENV=arduino atmega1284p_avrdevelopersstandard_cs10
make OS=windows ENV=arduino atmega1284p_bobuinosleepingbeauty_cs10
REM make OS=windows ENV=arduino atmega2560_cs4
REM make OS=windows ENV=arduino atmega2560_cs8
REM make OS=windows ENV=arduino atmega2560_cs10
REM make OS=windows ENV=arduino atmega2560_cs53
@pause
