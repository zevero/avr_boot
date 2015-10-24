# Build environments(from https://github.com/Optiboot/optiboot/blob/master/optiboot/bootloaders/optiboot/Makefile)
# Start of some ugly makefile-isms to allow avr_boot to be built
# in several different environments.

# default
fixpath = $(1)
SH := bash

ifeq ($(ENV), arduino)
# For Arduino, we assume that we're connected to the avr_boot directory
# in Arduino/hardware/avr/bootloader, which means that the full set
# of avr-tools are "right up there" in standard places.
# (except that in 1.5.x, there's an additional level of "up")
TESTDIR := $(firstword $(wildcard ../../../tools/*))
ifeq (,$(TESTDIR))
# Arduino 1.5.x tool location compared to optiboot dir
  TOOLROOT = ../../../../tools
else
# Arduino 1.0 (and earlier) tool location
  TOOLROOT = ../../../tools
endif
GCCROOT = $(TOOLROOT)/avr/bin/

ifeq ($(OS), windows)
# On windows, SOME of the tool paths will need to have backslashes instead
# of forward slashes (because they use windows cmd.exe for execution instead
# of a unix/mingw shell?)  We also have to ensure that a consistent shell
# is used even if a unix shell is installed (ie as part of WINAVR)
fixpath = $(subst /,\,$1)
SHELL = cmd.exe
SH = sh
endif

else ifeq ($(ENV), arduinodev)
# Arduino IDE source code environment.  Use the unpacked compilers created
# by the build (you'll need to do "ant build" first.)
ifeq ($(OS), macosx)
TOOLROOT = ../../../../build/macosx/work/Arduino.app/Contents/Resources/Java/hardware/tools
endif
ifeq ($(OS), windows)
TOOLROOT = ../../../../build/windows/work/hardware/tools
endif

GCCROOT = $(TOOLROOT)/avr/bin/

else
GCCROOT =
endif

# End of build environment code.


atmega328p_cs4: TARGET = atmega328p_cs4
atmega328p_cs4: MCU_TARGET = atmega328p
atmega328p_cs4: BOOT_ADR = 0x7000
atmega328p_cs4: F_CPU = 20000000
atmega328p_cs4: USE_LED = 0
atmega328p_cs4: USE_UART = 0
atmega328p_cs4: CS_PIN = 4
atmega328p_cs4: VARIANT_1284P = 0
atmega328p_cs4: clean
atmega328p_cs4: atmega328p_cs4.elf
atmega328p_cs4: atmega328p_cs4.lst
atmega328p_cs4: atmega328p_cs4.hex

atmega328p_cs8: TARGET = atmega328p_cs8
atmega328p_cs8: MCU_TARGET = atmega328p
atmega328p_cs8: BOOT_ADR = 0x7000
atmega328p_cs8: F_CPU = 20000000
atmega328p_cs8: USE_LED = 0
atmega328p_cs8: USE_UART = 0
atmega328p_cs8: CS_PIN = 8
atmega328p_cs8: VARIANT_1284P = 0
atmega328p_cs8: clean
atmega328p_cs8: atmega328p_cs8.elf
atmega328p_cs8: atmega328p_cs8.lst
atmega328p_cs8: atmega328p_cs8.hex

atmega328p_cs10: TARGET = atmega328p_cs10
atmega328p_cs10: MCU_TARGET = atmega328p
atmega328p_cs10: BOOT_ADR = 0x7000
atmega328p_cs10: F_CPU = 20000000
atmega328p_cs10: USE_LED = 0
atmega328p_cs10: USE_UART = 0
atmega328p_cs10: CS_PIN = 10
atmega328p_cs10: VARIANT_1284P = 0
atmega328p_cs10: clean
atmega328p_cs10: atmega328p_cs10.elf
atmega328p_cs10: atmega328p_cs10.lst
atmega328p_cs10: atmega328p_cs10.hex

atmega32u4_cs4: TARGET = atmega32u4_cs4
atmega32u4_cs4: MCU_TARGET = atmega32u4
atmega32u4_cs4: BOOT_ADR = 0x7000
atmega32u4_cs4: F_CPU = 20000000
atmega32u4_cs4: USE_LED = 0
atmega32u4_cs4: USE_UART = 0
atmega32u4_cs4: CS_PIN = 4
atmega32u4_cs4: VARIANT_1284P = 0
atmega32u4_cs4: clean
atmega32u4_cs4: atmega32u4_cs4.elf
atmega32u4_cs4: atmega32u4_cs4.lst
atmega32u4_cs4: atmega32u4_cs4.hex

atmega32u4_cs8: TARGET = atmega32u4_cs8
atmega32u4_cs8: MCU_TARGET = atmega32u4
atmega32u4_cs8: BOOT_ADR = 0x7000
atmega32u4_cs8: F_CPU = 20000000
atmega32u4_cs8: USE_LED = 0
atmega32u4_cs8: USE_UART = 0
atmega32u4_cs8: CS_PIN = 8
atmega32u4_cs8: VARIANT_1284P = 0
atmega32u4_cs8: clean
atmega32u4_cs8: atmega32u4_cs8.elf
atmega32u4_cs8: atmega32u4_cs8.lst
atmega32u4_cs8: atmega32u4_cs8.hex

atmega32u4_cs10: TARGET = atmega32u4_cs10
atmega32u4_cs10: MCU_TARGET = atmega32u4
atmega32u4_cs10: BOOT_ADR = 0x7000
atmega32u4_cs10: F_CPU = 20000000
atmega32u4_cs10: USE_LED = 0
atmega32u4_cs10: USE_UART = 0
atmega32u4_cs10: CS_PIN = 10
atmega32u4_cs10: VARIANT_1284P = 0
atmega32u4_cs10: clean
atmega32u4_cs10: atmega32u4_cs10.elf
atmega32u4_cs10: atmega32u4_cs10.lst
atmega32u4_cs10: atmega32u4_cs10.hex

atmega1284p_avrdevelopersstandard_cs4: TARGET = atmega1284p_avrdevelopersstandard_cs4
atmega1284p_avrdevelopersstandard_cs4: MCU_TARGET = atmega1284p
atmega1284p_avrdevelopersstandard_cs4: BOOT_ADR = 0x1F000
atmega1284p_avrdevelopersstandard_cs4: F_CPU = 20000000
atmega1284p_avrdevelopersstandard_cs4: USE_LED = 0
atmega1284p_avrdevelopersstandard_cs4: USE_UART = 0
atmega1284p_avrdevelopersstandard_cs4: CS_PIN = 4
atmega1284p_avrdevelopersstandard_cs4: VARIANT_1284P = 0
atmega1284p_avrdevelopersstandard_cs4: clean
atmega1284p_avrdevelopersstandard_cs4: atmega1284p_avrdevelopersstandard_cs4.elf
atmega1284p_avrdevelopersstandard_cs4: atmega1284p_avrdevelopersstandard_cs4.lst
atmega1284p_avrdevelopersstandard_cs4: atmega1284p_avrdevelopersstandard_cs4.hex

atmega1284p_bobuinosleepingbeauty_cs4: TARGET = atmega1284p_bobuinosleepingbeauty_cs4
atmega1284p_bobuinosleepingbeauty_cs4: MCU_TARGET = atmega1284p
atmega1284p_bobuinosleepingbeauty_cs4: BOOT_ADR = 0x1F000
atmega1284p_bobuinosleepingbeauty_cs4: F_CPU = 20000000
atmega1284p_bobuinosleepingbeauty_cs4: USE_LED = 0
atmega1284p_bobuinosleepingbeauty_cs4: USE_UART = 0
atmega1284p_bobuinosleepingbeauty_cs4: CS_PIN = 4
atmega1284p_bobuinosleepingbeauty_cs4: VARIANT_1284P = 1
atmega1284p_bobuinosleepingbeauty_cs4: clean
atmega1284p_bobuinosleepingbeauty_cs4: atmega1284p_bobuinosleepingbeauty_cs4.elf
atmega1284p_bobuinosleepingbeauty_cs4: atmega1284p_bobuinosleepingbeauty_cs4.lst
atmega1284p_bobuinosleepingbeauty_cs4: atmega1284p_bobuinosleepingbeauty_cs4.hex

atmega1284p_avrdevelopersstandard_cs8: TARGET = atmega1284p_avrdevelopersstandard_cs8
atmega1284p_avrdevelopersstandard_cs8: MCU_TARGET = atmega1284p
atmega1284p_avrdevelopersstandard_cs8: BOOT_ADR = 0x1F000
atmega1284p_avrdevelopersstandard_cs8: F_CPU = 20000000
atmega1284p_avrdevelopersstandard_cs8: USE_LED = 0
atmega1284p_avrdevelopersstandard_cs8: USE_UART = 0
atmega1284p_avrdevelopersstandard_cs8: CS_PIN = 8
atmega1284p_avrdevelopersstandard_cs8: VARIANT_1284P = 0
atmega1284p_avrdevelopersstandard_cs8: clean
atmega1284p_avrdevelopersstandard_cs8: atmega1284p_avrdevelopersstandard_cs8.elf
atmega1284p_avrdevelopersstandard_cs8: atmega1284p_avrdevelopersstandard_cs8.lst
atmega1284p_avrdevelopersstandard_cs8: atmega1284p_avrdevelopersstandard_cs8.hex

atmega1284p_bobuino_cs8: TARGET = atmega1284p_bobuino_cs8
atmega1284p_bobuino_cs8: MCU_TARGET = atmega1284p
atmega1284p_bobuino_cs8: BOOT_ADR = 0x1F000
atmega1284p_bobuino_cs8: F_CPU = 20000000
atmega1284p_bobuino_cs8: USE_LED = 0
atmega1284p_bobuino_cs8: USE_UART = 0
atmega1284p_bobuino_cs8: CS_PIN = 8
atmega1284p_bobuino_cs8: VARIANT_1284P = 1
atmega1284p_bobuino_cs8: clean
atmega1284p_bobuino_cs8: atmega1284p_bobuino_cs4.elf
atmega1284p_bobuino_cs8: atmega1284p_bobuino_cs8.lst
atmega1284p_bobuino_cs8: atmega1284p_bobuino_cs8.hex

atmega1284p_sleepingbeauty_cs8: TARGET = atmega1284p_sleepingbeauty_cs8
atmega1284p_sleepingbeauty_cs8: MCU_TARGET = atmega1284p
atmega1284p_sleepingbeauty_cs8: BOOT_ADR = 0x1F000
atmega1284p_sleepingbeauty_cs8: F_CPU = 20000000
atmega1284p_sleepingbeauty_cs8: USE_LED = 0
atmega1284p_sleepingbeauty_cs8: USE_UART = 0
atmega1284p_sleepingbeauty_cs8: CS_PIN = 8
atmega1284p_sleepingbeauty_cs8: VARIANT_1284P = 2
atmega1284p_sleepingbeauty_cs8: clean
atmega1284p_sleepingbeauty_cs8: atmega1284p_sleepingbeauty_cs8.elf
atmega1284p_sleepingbeauty_cs8: atmega1284p_sleepingbeauty_cs8.lst
atmega1284p_sleepingbeauty_cs8: atmega1284p_sleepingbeauty_cs8.hex

atmega1284p_avrdevelopersstandard_cs10: TARGET = atmega1284p_avrdevelopersstandard_cs10
atmega1284p_avrdevelopersstandard_cs10: MCU_TARGET = atmega1284p
atmega1284p_avrdevelopersstandard_cs10: BOOT_ADR = 0x1F000
atmega1284p_avrdevelopersstandard_cs10: F_CPU = 20000000
atmega1284p_avrdevelopersstandard_cs10: USE_LED = 0
atmega1284p_avrdevelopersstandard_cs10: USE_UART = 0
atmega1284p_avrdevelopersstandard_cs10: CS_PIN = 10
atmega1284p_avrdevelopersstandard_cs10: VARIANT_1284P = 0
atmega1284p_avrdevelopersstandard_cs10: clean
atmega1284p_avrdevelopersstandard_cs10: atmega1284p_avrdevelopersstandard_cs10.elf
atmega1284p_avrdevelopersstandard_cs10: atmega1284p_avrdevelopersstandard_cs10.lst
atmega1284p_avrdevelopersstandard_cs10: atmega1284p_avrdevelopersstandard_cs10.hex

atmega1284p_bobuinosleepingbeauty_cs10: TARGET = atmega1284p_bobuinosleepingbeauty_cs10
atmega1284p_bobuinosleepingbeauty_cs10: MCU_TARGET = atmega1284p
atmega1284p_bobuinosleepingbeauty_cs10: BOOT_ADR = 0x1F000
atmega1284p_bobuinosleepingbeauty_cs10: F_CPU = 20000000
atmega1284p_bobuinosleepingbeauty_cs10: USE_LED = 0
atmega1284p_bobuinosleepingbeauty_cs10: USE_UART = 0
atmega1284p_bobuinosleepingbeauty_cs10: CS_PIN = 10
atmega1284p_bobuinosleepingbeauty_cs10: VARIANT_1284P = 1
atmega1284p_bobuinosleepingbeauty_cs10: clean
atmega1284p_bobuinosleepingbeauty_cs10: atmega1284p_bobuinosleepingbeauty_cs10.elf
atmega1284p_bobuinosleepingbeauty_cs10: atmega1284p_bobuinosleepingbeauty_cs10.lst
atmega1284p_bobuinosleepingbeauty_cs10: atmega1284p_bobuinosleepingbeauty_cs10.hex

# atmega2560_cs4: TARGET = atmega2560_cs4
# atmega2560_cs4: MCU_TARGET = atmega2560
# atmega2560_cs4: BOOT_ADR = 0x3F000
# atmega2560_cs4: F_CPU = 20000000
# atmega2560_cs4: USE_LED = 0
# atmega2560_cs4: USE_UART = 0
# atmega2560_cs4: CS_PIN = 4
# atmega2560_cs4: VARIANT_1284P = 0
# atmega2560_cs4: clean
# atmega2560_cs4: atmega2560_cs4.elf
# atmega2560_cs4: atmega2560_cs4.lst
# atmega2560_cs4: atmega2560_cs4.hex

# atmega2560_cs8: TARGET = atmega2560_cs8
# atmega2560_cs8: MCU_TARGET = atmega2560
# atmega2560_cs8: BOOT_ADR = 0x3F000
# atmega2560_cs8: F_CPU = 20000000
# atmega2560_cs8: USE_LED = 0
# atmega2560_cs8: USE_UART = 0
# atmega2560_cs8: CS_PIN = 8
# atmega2560_cs8: VARIANT_1284P = 0
# atmega2560_cs8: clean
# atmega2560_cs8: atmega2560_cs8.elf
# atmega2560_cs8: atmega2560_cs8.lst
# atmega2560_cs8: atmega2560_cs8.hex

# atmega2560_cs10: TARGET = atmega2560_cs10
# atmega2560_cs10: MCU_TARGET = atmega2560
# atmega2560_cs10: BOOT_ADR = 0x3F000
# atmega2560_cs10: F_CPU = 20000000
# atmega2560_cs10: USE_LED = 0
# atmega2560_cs10: USE_UART = 0
# atmega2560_cs10: CS_PIN = 10
# atmega2560_cs10: VARIANT_1284P = 0
# atmega2560_cs10: clean
# atmega2560_cs10: atmega2560_cs10.elf
# atmega2560_cs10: atmega2560_cs10.lst
# atmega2560_cs10: atmega2560_cs10.hex

# atmega2560_cs53: TARGET = atmega2560_cs53
# atmega2560_cs53: MCU_TARGET = atmega2560
# atmega2560_cs53: BOOT_ADR = 0x3F000
# atmega2560_cs53: F_CPU = 20000000
# atmega2560_cs53: USE_LED = 0
# atmega2560_cs53: USE_UART = 0
# atmega2560_cs53: CS_PIN = 53
# atmega2560_cs53: VARIANT_1284P = 0
# atmega2560_cs53: clean
# atmega2560_cs53: atmega2560_cs53.elf
# atmega2560_cs53: atmega2560_cs53.lst
# atmega2560_cs53: atmega2560_cs53.hex


# Generic build instructions

#ifeq ($(strip $(USE_UART)),0)
CSRC        = main.c pff/src/pff.c diskio.c
#else
#CSRC        = main.c pff/src/pff.c diskio.c uart/uart.c
#endif

ASRC        = asmfunc.S
OPTIMIZE    = -Os -mcall-prologues -ffunction-sections -fdata-sections
DEFS        = -DBOOT_ADR=$(BOOT_ADR) -DF_CPU=$(F_CPU) -DUSE_LED=$(USE_LED) -DUSE_UART=$(USE_UART) -DCS_PIN=$(CS_PIN) -DVARIANT_1284P=$(VARIANT_1284P)
LIBS        =
DEBUG       = dwarf-2

ASFLAGS     = -Wa,-adhlns=$(<:.S=.lst),-gstabs $(DEFS)
ALL_ASFLAGS = -mmcu=$(MCU_TARGET) -I. -x assembler-with-cpp $(ASFLAGS)
CFLAGS      = -g$(DEBUG) -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) -std=c99 $(DEFS)
LDFLAGS     = -Wl,-Map,$(TARGET).map -Wl,--gc-sections -Wl,--section-start,.text=$(BOOT_ADR)
OBJ         = $(CSRC:.c=.o) $(ASRC:.S=.o)

CC          = $(GCCROOT)avr-gcc
OBJCOPY     = $(GCCROOT)avr-objcopy
OBJDUMP     = $(call fixpath,$(GCCROOT)avr-objdump)
SIZE        = $(GCCROOT)avr-size


%.elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)


clean:
	rm -rf *.o $(TARGET).elf *.eps *.bak *.a *.bin
	rm -rf *.lst *.map $(EXTRA_CLEAN_FILES)
	rm -rf $(TARGET).hex

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.o : %.S
	$(CC) -c $(ALL_ASFLAGS) $< -o $@

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -j .fuse -O ihex $< $@

print-%  : ; @echo $* = $($*)  #test any var with make print-XXX
