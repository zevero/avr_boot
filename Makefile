#------------------------------------------------------------------
# Makefile for stand-alone MMC boot strap loader
#------------------------------------------------------------------
# Change these defs for the target device

MCU_TARGET    = atmega328p # Target device to be used (32K or larger)
BOOT_ADR      = 0x07000 # Boot loader start address [byte] NOT [word] as in http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega1284p
F_CPU         = 16000000  # CPU clock frequency [Hz] NOT critical: it just should be higher than the actual Hz 
CS_PIN        = 4 # Arduino pin connected to SD CS. Supported values: 4, 8, 10, 53.
VARIANT_1284P = 0 # ATmega1284P variant: 0=avr_developers/standard, 1=bobuino, 2=sleepingbeauty
USE_LED       = 0 # Debug with two (defined in asmfunc.S)
USE_UART      = 0 # Debug on Serial. 0 ... deactivate or divider of http://wormfood.net/avrbaudcalc.php for baud rate!
USE_SERIAL    = 1 # Enable experimental serial flashing support NB: Disabled if uart debugging is enabled
#------------------------------------------------------------------
ifeq ($(strip $(USE_UART)),1)
CSRC        = main.c pff/src/pff.c diskio.c uart/uart.c
USE_SERIAL  = 0
else ifeq ($(strip $(USE_SERIAL)),1)
CSRC        = main.c pff/src/pff.c diskio.c stk500v1.c prog_flash.c prog_flash.h
else
CSRC        = main.c pff/src/pff.c diskio.c
endif


TARGET      = avr_boot
ASRC        = asmfunc.S
OPTIMIZE    = -Os -mcall-prologues -ffunction-sections -fdata-sections -fwhole-file -flto -funsigned-char -fno-split-wide-types -fno-inline-small-functions -ffreestanding -fno-jump-tables
DEFS        = -DBOOT_ADR=$(BOOT_ADR) -DF_CPU=$(F_CPU) -DUSE_LED=$(USE_LED) -DUSE_UART=$(USE_UART) -DCS_PIN=$(CS_PIN) -DVARIANT_1284P=$(VARIANT_1284P) -DUSE_SERIAL=$(USE_SERIAL)
LIBS        =
DEBUG       = dwarf-2

ASFLAGS     = -Wa,-adhlns=$(<:.S=.lst),-gstabs $(DEFS)
ALL_ASFLAGS = -mmcu=$(MCU_TARGET) -I. -x assembler-with-cpp $(ASFLAGS)
CFLAGS      = -g$(DEBUG) -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) -std=c99 $(DEFS)
LDFLAGS     = -Wl,-Map,$(TARGET).map -Wl,--gc-sections -Wl,--section-start,.text=$(BOOT_ADR)
OBJ         = $(CSRC:.c=.o) $(ASRC:.S=.o)

CC          = avr-gcc
OBJCOPY     = avr-objcopy
OBJDUMP     = avr-objdump
SIZE        = avr-size


all:	clean $(TARGET).elf lst text bin size

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o $(TARGET).elf *.eps *.bak *.a *.bin
	rm -rf pff/src/*.o uart/*.o
	rm -rf *.lst *.map $(EXTRA_CLEAN_FILES)
	rm -rf $(TARGET).hex

size: $(TARGET).elf
	$(SIZE) -C --mcu=$(MCU_TARGET) $(TARGET).elf

lst:  $(TARGET).lst
%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.o : %.S
	$(CC) -c $(ALL_ASFLAGS) $< -o $@

text: $(TARGET).hex
%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -j .fuse -O ihex $< $@
# --- make bin just to check size :)
bin: $(TARGET).bin
%.bin: %.hex
	$(OBJCOPY) -I ihex -O binary $< $@

print-%  : ; @echo $* = $($*)  #test any var with make print-XXX

