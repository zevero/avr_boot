/**********************************************************/
/* stk500v1.c                                             */
/* Copyright (c) 2010 by thomas seiler                    */ 
/* Implementation of the AVR STK500v1 protocol            */
/* Inspired by the original Arduino Bootloader code,      */
/* But heavily rewritten for smaller code size            */
/*                                                        */
/* -------------------------------------------------------*/
/*                                                        */
/* This program is free software; you can redistribute it */
/* and/or modify it under the terms of the GNU General    */
/* Public License as published by the Free Software       */
/* Foundation; either version 2 of the License, or        */
/* (at your option) any later version.                    */
/*                                                        */
/* This program is distributed in the hope that it will   */
/* be useful, but WITHOUT ANY WARRANTY; without even the  */
/* implied warranty of MERCHANTABILITY or FITNESS FOR A   */
/* PARTICULAR PURPOSE.  See the GNU General Public        */
/* License for more details.                              */
/*                                                        */
/* You should have received a copy of the GNU General     */
/* Public License along with this program; if not, write  */
/* to the Free Software Foundation, Inc.,                 */
/* 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA */
/*                                                        */
/* Licence can be viewed at                               */
/* http://www.fsf.org/licenses/gpl.txt                    */
/**********************************************************/

#include <inttypes.h>
#include "board-arduino.h"
#include "stk500v1.h"
/* define this to loose a bit compatibility, but save a few bytes */
#define MINIMALISTIC

/* BAUD_RATE must be defined in board.h */

/* for the SIGNATURE_X macros, and uart pins */
#include <avr/io.h>

/* access to the pagebuffer */
#include "prog_flash.h"

/* we need to read/write the eeprom */
#if !defined(__AVR_ATmega168__) || !defined(__AVR_ATmega328P__)
#include <avr/eeprom.h>
#endif

/* we need to read the flash */
#include <avr/pgmspace.h>


/* use the global pagebuffer as scratch pad */

/* some variables */
union length_union {
	uint16_t word;
	uint8_t  byte[2];
} length;

struct flags_struct { // changed from a packed struct to save some bytes
	uint8_t eeprom;
} flags;

/* uart stuff --------------------------------------------*/

#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega1280__)
//Select UART to use on multi-uart systems
static const uint8_t bootuart = 1;
#endif

static inline void setup_uart() {

	/* initialize UART(s) depending on CPU defined */

#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega1280__)

	if(bootuart == 1) {
		UBRR0L = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
		UBRR0H = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
		UCSR0A = 0x00;
		UCSR0C = 0x06;
		UCSR0B = _BV(TXEN0)|_BV(RXEN0);
	}
	if(bootuart == 2) {
		UBRR1L = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
		UBRR1H = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
		UCSR1A = 0x00;
		UCSR1C = 0x06;
		UCSR1B = _BV(TXEN1)|_BV(RXEN1);
	}

#ifdef __AVR_ATmega1280__
	if (bootuart == 3) {
		UBRR2L = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
		UBRR2H = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
		UCSR2A = 0x00;
		UCSR2C = 0x06;
		UCSR2B = _BV(TXEN2)|_BV(RXEN2);
	}
	if (bootuart == 4) {
		UBRR3L = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
		UBRR3H = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
		UCSR3A = 0x00;
		UCSR3C = 0x06;
		UCSR3B = _BV(TXEN3)|_BV(RXEN3);
	}

	/* Enable internal pull-up resistor on E0 (RX), in order
	 * to suppress line noise that prevents the bootloader from timing out.
	 */
	DDRE &= ~_BV(PINE0);
	PORTE |= _BV(PINE0);
#endif

#elif defined __AVR_ATmega163__
	UBRR = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
	UBRRHI = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
	UCSRA = 0x00;
	UCSRB = _BV(TXEN)|_BV(RXEN);	
#elif defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__)
#ifdef DOUBLE_SPEED
	UCSR0A = (1<<U2X0); //Double speed mode USART0
	UBRR0L = (uint8_t)(F_CPU/(BAUD_RATE*8L)-1);
	UBRR0H = (F_CPU/(BAUD_RATE*8L)-1) >> 8;
#else
	UBRR0L = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
	UBRR0H = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
#endif

	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);

	/* Enable internal pull-up resistor on pin D0 (RX), in order
	to supress line noise that prevents the bootloader from
	timing out (DAM: 20070509) */
	DDRD &= ~_BV(PIND0);
	PORTD |= _BV(PIND0);
#elif defined __AVR_ATmega8__
	/* m8 */
	UBRRH = (((F_CPU/BAUD_RATE)/16)-1)>>8; 	// set baud rate
	UBRRL = (((F_CPU/BAUD_RATE)/16)-1);
	UCSRB = (1<<RXEN)|(1<<TXEN);  // enable Rx & Tx
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);  // config USART; 8N1
#else
	/* m16,m32,m169,m8515,m8535 */
	UBRRL = (uint8_t)(F_CPU/(BAUD_RATE*16L)-1);
	UBRRH = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
	UCSRA = 0x00;
	UCSRC = 0x06;
	UCSRB = _BV(TXEN)|_BV(RXEN);
#endif
}

static void putch(char ch)
{
	/* send a byte to UART depending on CPU defined */

#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega1280__)
	if(bootuart == 1) {
		while (!(UCSR0A & _BV(UDRE0)));
		UDR0 = ch;
	}
	else if (bootuart == 2) {
		while (!(UCSR1A & _BV(UDRE1)));
		UDR1 = ch;
	}
#ifdef __AVR_ATmega1280__
	else if (bootuart == 3) {
		while (!(UCSR2A & _BV(UDRE2)));
		UDR2 = ch;
	}
	else if (bootuart == 4) {
		while (!(UCSR3A & _BV(UDRE3)));
		UDR3 = ch;
	}
#endif
#elif defined(__AVR_ATmega168__)  || defined(__AVR_ATmega328P__)
	while (!(UCSR0A & _BV(UDRE0)));
	UDR0 = ch;
#else
	/* m8,16,32,169,8515,8535,163 */
	while (!(UCSRA & _BV(UDRE)));
	UDR = ch;
#endif
}


static char getch(void)
{
	uint32_t count = 0;
	/* read a byte from UART depending on CPU defined */

#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega1280__)
	if(bootuart == 1) {
		while(!(UCSR0A & _BV(RXC0))) {
			count++;
			if (count > MAX_TIME_COUNT) {
				return 0xFF;
			}
		}
		return UDR0;
	}
	else if(bootuart == 2) {
		while(!(UCSR1A & _BV(RXC1))) {
			count++;
			if (count > MAX_TIME_COUNT) {
				return 0xFF;
			}
		}
		return UDR1;
	}
#ifdef __AVR_ATmega1280__
	else if (bootuart == 3) {
		while (!(UCSR2A & _BV(RXC2))) {
			count++;
			if (count > MAX_TIME_COUNT) {
				return 0xFF;
			}
		}
		return UDR2;
	}
	else if (bootuart == 4) {
		while (!(UCSR3A & _BV(RXC3))) {
			count++;
			if (count > MAX_TIME_COUNT) {
				return 0xFF;
			}
		}
		return UDR3;
	}
	return 0xFF;
#endif

#elif defined(__AVR_ATmega168__)  || defined(__AVR_ATmega328P__)
	while(!(UCSR0A & _BV(RXC0))){
		/* 20060803 DojoCorp:: Addon coming from the previous Bootloader*/
		/* HACKME:: here is a good place to count times*/
		count++;
		if (count > MAX_TIME_COUNT) { 
			return 0xFF;
	  	}
	}

	return UDR0;
#else
	/* m8,16,32,169,8515,8535,163 */
	while(!(UCSRA & _BV(RXC))){
		/* 20060803 DojoCorp:: Addon coming from the previous Bootloader*/               
		/* HACKME:: here is a good place to count times*/
		count++;
		if (count > MAX_TIME_COUNT) {
			return 0xFF;
	  	}
	}
	return UDR;
#endif
}


/* handle the different commands ----------------------- */

#ifndef MINIMALISTIC
static inline void handle_programmerID(void) {
	putch('A');  /* this is smaller than a string */
	putch('V');
	putch('R');
	putch(' ');
	putch('I');
	putch('S');
	putch('P');
}
#endif

/* SW_MAJOR and MINOR needs to be updated from time to time to avoid warning message from AVR Studio */
/* never allow AVR Studio to do an update !!!! */
#define HW_VER	 0x02
#define SW_MAJOR 0x01
#define SW_MINOR 0x10

static inline void handle_programmerVER(void) {
	uint8_t ch = pagebuffer[0];
	if(ch==0x80) putch(HW_VER);		// Hardware version
	else if(ch==0x81) putch(SW_MAJOR);	// Software major version
	else if(ch==0x82) putch(SW_MINOR);	// Software minor version
	else if(ch==0x98) putch(0x03);		// Unknown but seems to be required by avr studio 3.56
	else putch(0x00);				// Covers various unnecessary responses we don't care about
}

static inline void handle_addr(void) {
		address = *((uint16_t*) &pagebuffer[0]);
		address = address << 1;	        // address * 2 -> byte location
}

static inline void handle_spi() {
	if (pagebuffer[0] == 0x30) {
		if (pagebuffer[2] == 0) {
			putch(SIGNATURE_0);
		} else if (pagebuffer[2] == 1) {
			putch(SIGNATURE_1);
		} else {
			putch(SIGNATURE_2);
		} 
	} else {
			putch(0x00);
	}
}

static inline void handle_sig() {
	putch(SIGNATURE_0);
	putch(SIGNATURE_1);
	putch(SIGNATURE_2);	
}

static inline void handle_write() {
	uint8_t w;
	if (flags.eeprom) {		                //Write to EEPROM one byte at a time
		for(w=0;w<length.word;w++) {
#if defined(__AVR_ATmega168__)  || defined(__AVR_ATmega328P__)
			while(EECR & (1<<EEPE));
			EEAR = (uint16_t)(void *)address;
			EEDR = pagebuffer[w];
			EECR |= (1<<EEMPE);
			EECR |= (1<<EEPE);
#else
			eeprom_write_byte((void *)address,pagebuffer[w]);
#endif
			address++;
		}
	} else {					            //Write to FLASH one page at a time
		write_flash_page();
	}
}

static inline void handle_read() {
	uint16_t w = 0;
	for (w=0;w < length.word;w++) {		        // Can handle odd and even lengths okay
		if (flags.eeprom) {	                        // Byte access EEPROM read
#if defined(__AVR_ATmega168__)  || defined(__AVR_ATmega328P__)
			while(EECR & (1<<EEPE));
			EEAR = (uint16_t)(void *)address;
			EECR |= (1<<EERE);
			putch(EEDR);
#else
			putch(eeprom_read_byte((void *)address));
#endif
			address++;
		} else {
#if defined (__AVR_ATmega128__) || defined (__AVR_ATmega1280__)
			if (address & 0xFFFF0000) putch(pgm_read_byte_far(address));
			else putch(pgm_read_byte_near(address));
#else
			putch(pgm_read_byte_near(address));
#endif
			address++;
		}
	}
}

/* stk500v1 protocol ---------------------------------- */
/* Added: returns 0 if no uart programmer, 1 if programmer detected*/

uint8_t stk500v1() {
	uint16_t w  = 0;
	uint8_t ch = 0;
	uint8_t firstok = 0;
    
    /* Used to know if a programmer was detected, to allow stk500v1 to return something useful on exit. */
    uint8_t uart_programmer_detected = 0;

	/* open serial port */
	setup_uart();

	/* forever loop */
	for(;;) {

		/* get character from UART */
		ch = getch();

		// handle errors and quit cmd...
		if (ch == '0') firstok = 1;
		if (ch == 0xFF) return;
		if (firstok == 0 || ch == 'Q') break;

		/* commands interpreter: check for cmd that need reply */
		if (
#ifndef MINIMALISTIC
		    ch == '1' ||
		    ch == 'R' ||
		    ch == '@' ||

#endif
		    ch == 'A' ||
		    ch == 'U' ||
		    ch == 'V' ||
		    ch == 'B' ||
		    ch == 'E' ||
		    ch == 'u' ||
		    ch == 'd' ||
		    ch == 't' ||
		    ch == '0' ||
		    ch == 'P')
		{
			/* command was found, determine length... */
			uint16_t len = 0;

			if (ch == 't' || ch == 'd') {
				/* parse len */
				/* length is big endian and is in bytes */
				length.byte[1] = getch();
				length.byte[0] = getch();

				flags.eeprom = (getch() == 'E');
				len = (ch == 'd') ? length.word : 0;
			} else {
				/* constant len */
#ifndef MINIMALISTIC
				if (ch == 'B') len = 20;
				if (ch == 'E') len = 5;
#endif
				if (ch == 'V') len = 4;
				if (ch == 'U') len = 2;
				if (ch == 'A') len = 1;
			}

			// now consume the right amount of bytes
			for (w=0; w < len; w++) pagebuffer[w] = getch();

			// search Sync Token
			while (getch() != ' ');

			// send start of response
			putch(0x14);


			// handle response
#ifndef MINIMALISTIC
			if (ch == '1') handle_programmerID();
#endif
			if (ch == 'A') handle_programmerVER();
			if (ch == 'U') handle_addr();
			if (ch == 'V') handle_spi();
			if (ch == 'u') handle_sig();
			if (ch == 'd') handle_write();
			if (ch == 't') handle_read();

			// send end of response
			putch(0x10);
            
            /* Now it's certain that a programmer was detected and used */ 
            uart_programmer_detected = 1;
		}

	} /* forever loop */

	/* make avrdude happy when issuing quit command */
	putch(0x14);
	putch(0x10);
    
    return uart_programmer_detected;
}
