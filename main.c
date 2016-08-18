/*-------------------------------------------------------------------------/
/  Stand-alone MMC boot loader  R0.01
/--------------------------------------------------------------------------/
/
/  Copyright (C) 2010, ChaN, all right reserved.
/
/ * This software is a free software and there is NO WARRANTY.
/ * No restriction on use. You can use, modify and redistribute it for
/   personal, non-profit or commercial products UNDER YOUR RESPONSIBILITY.
/ * Redistributions of source code must retain the above copyright notice.
/
/--------------------------------------------------------------------------/
/ Dec 6, 2010  R0.01  First release
/--------------------------------------------------------------------------/
/ This is a stand-alone MMC/SD boot loader for megaAVRs. It requires a 4KB
/ boot section for code, four GPIO pins for MMC/SD as shown in sch.jpg and
/ nothing else. To port the boot loader into your project, follow the
/ instruction sdescribed below.
/
/ 1. Setup the hardware. Attach a memory card socket to the any GPIO port
/    where you like. Select boot size at least 4KB for the boot loader with
/    BOOTSZ fuses and enable boot loader with BOOTRST fuse.
/
/ 2. Setup the software. Change the four port definitions in the asmfunc.S.
/    Change MCU_TARGET, BOOT_ADR and MCU_FREQ in the Makefile. The BOOT_ADR
/    is a BYTE address of boot section in the flash. Build the boot loader
/    and write it to the device with a programmer.
/
/ 3. Build the application program and output it in binary form instead of
/    hex format. Rename the file "app.bin" and put it into the memory card.
/
/ 4. Insert the card and turn the target power on. When the boot loader found
/    the application file, the file is written into the flash memory prior to
/    start the application program. On-board LED lights (if exist) during
/    the flash programming operation.
/
/-------------------------------------------------------------------------*/

const char filename[13] ="FIRMWARE.BIN\0"; 	// EDIT FILENAME HERE
#include <avr/wdt.h> //Watchdog
// The following code is recommended in http://avr-libc.nongnu.org/user-manual/group__avr__watchdog.html but is disabled for now because avr_boot doesn't currently do anything with mcusr_mirror so for now we will only reset MCUSR and disable WDT.
//uint8_t mcusr_mirror __attribute__ ((section (".noinit")));void get_mcusr(void) __attribute__((naked)) __attribute__((section(".init3")));void get_mcusr(void){mcusr_mirror = MCUSR;MCUSR = 0;wdt_disable();}
void disable_watchdog(void) __attribute__((naked)) __attribute__((section(".init3")));
void disable_watchdog(void)
{
#if defined(MCUCSR)
	MCUCSR = ~(_BV(WDRF));	//Some MCUs require the watchdog reset flag to be cleared before WDT can be disabled. & operation is skipped to spare few bytes as bits in MCUSR can only be cleared.
#else
	MCUSR = ~(_BV(WDRF));	//Some MCUs require the watchdog reset flag to be cleared before WDT can be disabled. & operation is skipped to spare few bytes as bits in MCUSR can only be cleared.
#endif
	wdt_disable();	//immediately disable watchdog in case it was running in the application to avoid perpetual reset loop
}
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <string.h>
#include "pff/src/pff.h"


#if BOOT_ADR > 0xFFFF
  #define PGM_READ_BYTE(x) pgm_read_byte_far(x)
#else
  #define PGM_READ_BYTE(x) pgm_read_byte(x)
#endif

#if USE_UART
  #include "uart/uart.h"
#endif

#if USE_LED
void init_leds();
void led_power_on();
void led_power_off();
void led_power_toggle();
void led_write_on();
void led_write_off();
void led_write_toggle();
#endif
void flash_erase (DWORD);		/* Erase a flash page (asmfunc.S) */
void flash_write (DWORD, const BYTE*);	/* Program a flash page (asmfunc.S) */


FATFS Fatfs;					// Petit-FatFs work area 
BYTE Buff[SPM_PAGESIZE];	        	// Page data buffer 



static uint8_t pagecmp(const DWORD fa, uint8_t buff[SPM_PAGESIZE])
{
	UINT i;
	uint8_t b_flash,b_buff;
	for (i = 0; i < SPM_PAGESIZE; i++) {
                b_flash = PGM_READ_BYTE(fa+i);
                b_buff = buff[i];
		if ( b_flash != b_buff) {
			#if USE_UART  //output first difference
			  UART_puthex32(fa);UART_puts(PSTR(":"));
			  UART_puthex(b_flash);UART_puts(PSTR(" "));
			  UART_puthex(b_buff); UART_newline();
			#endif
			return 1;
		}
	}
	#if USE_UART  //output first difference
		UART_puthex32(fa);UART_puts(PSTR(":"));
		UART_puts(PSTR("="));UART_newline();
	#endif
	return 0;
}

void doFlash() {
	DWORD fa;	/* Flash address */
	UINT br;	/* Bytes read */
        #if USE_LED
	  uint8_t i;
          for(i=0;i<50;i++) { led_write_toggle();_delay_ms(100);} //Start Programming: Flash WRITE Wildly for 5 secs
        #endif


	for (fa = 0; fa < BOOT_ADR; fa += SPM_PAGESIZE) {	/* Update all application pages */

		memset(Buff, 0xFF, SPM_PAGESIZE);		/* Clear buffer */
		pf_read(Buff, SPM_PAGESIZE, &br);		/* Load a page data */
							
		if (pagecmp(fa, Buff)) {		/* Only flash if page is changed */
			#if USE_LED
			  led_write_off();
			  led_power_on();
			#endif
			flash_erase(fa);		/* Erase a page */
			flash_write(fa, Buff);		/* Write it if the data is available */	
			
		} else {

		#if USE_LED
		  led_power_off();
		  led_write_on();
		#endif
		}
	}
}

void checkFile() {
        uint8_t fresult;

	fresult = pf_mount(&Fatfs);	/* Initialize file system */

	if (fresult != FR_OK) { /* File System could not be mounted */
	  #if USE_UART
		UART_puts(PSTR("File not mounted"));
		UART_newline();
	  #endif
		
          #if USE_LED
	    uint8_t i;
            led_write_on();
            for(i=0;i<2*fresult;i++) { led_power_toggle();_delay_ms(500);}//Give error number while Write led is on
            led_write_off();
          #endif
          return;
	}
/*
	
    WORD flashver = eeprom_read_word((const uint16_t *)E2END - 1);
	if (flashver > 999) {
		flashver = 0;
	}
	BYTE y, tmp;
	WORD x;
	BYTE found = 0;
	
	for (x = flashver+10; x > flashver; x--) {
		y = x / 100;
		filename[5] = y + 0x30;
		tmp = x % 100;

		y = tmp / 10;
		filename[6] = y + 0x30;
		tmp = x % 10;

		filename[7] = tmp + 0x30;

		if (pf_open(filename) == FR_OK) { // File opens normally	
			found = 1;
			doProgram();
		}
		led_power_toggle();
	}
        
	if (found == 0) {*/

        fresult = pf_open(filename);

	if (fresult != FR_OK) { /* File could not be opened */
		
	  #if USE_UART
		UART_puts(PSTR("File not open"));
		UART_newline();
	  #endif
          #if USE_LED
	    uint8_t i;
            led_power_on();
            for(i=0;i<2*fresult;i++) { led_write_toggle();_delay_ms(500);}//Give error number while Power led is on
            led_power_off();
          #endif
          return;
	}

        doFlash();

	#if USE_LED
          led_write_off();
          led_power_off();
          _delay_ms(2000);
	  uint8_t i;
          for(i=0;i<40;i++) { led_power_toggle();_delay_ms(50);}//SUCCESS FLASH WILDLY for 2 secs
        #endif

}






int main (void)
{
	#if USE_LED
          init_leds();
          uint8_t i=0;
        #endif

	#if USE_UART
	  UART_init();
	  UART_puts(PSTR("AVR_BOOT"));
          UART_newline();
	#endif
	while (1) {
                #if USE_LED
                  led_power_on();_delay_ms(200);led_power_off();  //Test Power Led
                  led_write_on();_delay_ms(200);led_write_off();  //Test Write Led
		#endif

                checkFile();

		if (pgm_read_word(0) != 0xFFFF) ((void(*)(void))0)();	  //EXIT BOOTLOADER
    
		#if USE_UART
			UART_puts(PSTR("retry"));
			UART_newline();
		#endif
                #if USE_LED
                  for(i=0;i<10;i++) { led_power_toggle();_delay_ms(200);} //SOMETHING WENT WRONG: Flash Power LED
		#endif
	       _delay_ms(5000);              // Retry
	}
}
