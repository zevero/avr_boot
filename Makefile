#------------------------------------------------------------------
# Makefile for stand-alone MMC boot strap loader
#------------------------------------------------------------------
# Change these defs for the target device

MCU_TARGET    = atmega1284p # Target device to be used (32K or larger)
BOOT_ADR      = 0x1F000 # Boot loader start address [byte] NOT [word] as in http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega1284p
F_CPU         = 16000000  # CPU clock frequency [Hz] NOT critical: it just should be higher than the actual Hz 
SD_CS_PORT    = PORTB # Data Register of the SD CS pin
SD_CS_DDR     = DDRB # Data Direction Register of the SD CS pin
SD_CS_BIT     = 4 # Bit of the SD CS pin
USE_LED       = 0 # Debug with two (defined in asmfunc.S)
USE_UART      = 0 # Debug on Serial. 0 ... deactivate or divider of http://wormfood.net/avrbaudcalc.php for baud rate!
#------------------------------------------------------------------
ifeq ($(strip $(USE_UART)),0)
CSRC        = main.c pff/src/pff.c diskio.c
else
CSRC        = main.c pff/src/pff.c diskio.c uart/uart.c
endif

TARGET      = avr_boot
ASRC        = asmfunc.S
OPTIMIZE    = -Os -mcall-prologues -ffunction-sections -fdata-sections
DEFS        = -DBOOT_ADR=$(BOOT_ADR) -DF_CPU=$(F_CPU) -DUSE_LED=$(USE_LED) -DUSE_UART=$(USE_UART) -DSD_CS_PORT=$(SD_CS_PORT) -DSD_CS_DDR=$(SD_CS_DDR) -DSD_CS_BIT=$(SD_CS_BIT)
LIBS        =
DEBUG       = dwarf-2

ASFLAGS     = -Wa,-adhlns=$(<:.S=.lst),-gstabs $(DEFS)
ALL_ASFLAGS = -mmcu=$(MCU_TARGET) -I. -x assembler-with-cpp $(ASFLAGS)
CFLAGS      = -g$(DEBUG) -Wall $(OPTIMIZE) $(ADDED_CFLAGS) -mmcu=$(MCU_TARGET) -std=c99 $(DEFS)
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

