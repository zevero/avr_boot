#------------------------------------------------------------------
# Makefile for stand-alone MMC boot strap loader
#------------------------------------------------------------------
# Change these defs for the target device

MCU_TARGET    = atmega644p # Target device to be used (32K or larger)
BOOT_ADR      = 0xF000 # Boot loader start address [byte] NOT [word] as in http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega644p
F_CPU         = 16000000  # CPU clock frequency [Hz] NOT critical: it just should be higher than the actual Hz 
SD_CS_PORT    = PORTB # Data Register of the SD CS pin
SD_CS_DDR     = DDRB # Data Direction Register of the SD CS pin
SD_CS_BIT     = 4 # Bit of the SD CS pin
USE_LED       = 0 # Debug with two (defined in asmfunc.S)
USE_UART      = 0 # Debug on Serial. 0 ... deactivate or divider of http://wormfood.net/avrbaudcalc.php for baud rate!
USE_SERIAL_FLASHING    = 1 # Enable experimental serial flashing support. Currently only atmega328p is supported.
USE_FAT16     = 0 # Enable Fat16 support, disabled by default. If enabled, disable Fat32 to keep size of bootloader within limits 
USE_FAT32     = 1 # Enable Fat32 support, enabled by default to allow the use of sd cards > 2GB
#------------------------------------------------------------------

CSRC        = main.c pff/src/pff.c diskio.c
ifneq ($(strip $(USE_UART)),0)
CSRC        +=  uart/uart.c
endif
ifneq ($(strip $(USE_SERIAL_FLASHING)),0)
CSRC        +=  uart/uart.c stk500v1.c prog_flash.c
endif

TARGET      = avr_boot
ASRC        = asmfunc.S
OPTIMIZE    = -Os -mcall-prologues -ffunction-sections -fdata-sections -fwhole-file -flto -funsigned-char -fno-split-wide-types -fno-inline-small-functions -ffreestanding -fno-jump-tables
DEFS        = -DBOOT_ADR=$(BOOT_ADR) -DF_CPU=$(F_CPU) -DUSE_LED=$(USE_LED) -DUSE_UART=$(USE_UART) -DSD_CS_PORT=$(SD_CS_PORT) -DSD_CS_DDR=$(SD_CS_DDR) -DSD_CS_BIT=$(SD_CS_BIT) -DUSE_SERIAL_FLASHING=$(USE_SERIAL_FLASHING) -DUSE_FAT16=$(USE_FAT16) -DUSE_FAT32=$(USE_FAT32)
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

