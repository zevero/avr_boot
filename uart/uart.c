/*
** This is a simple set of UART routines for debug purposes
** It's Tx only and the baud rate is fixed (see UART_init)
*/

#include "uart.h"
#define 	UCSRA 	UCSR0A
#define 	UCSRB 	UCSR0B
#define 	UCSRC 	UCSR0C
#define 	UBRRH 	UBRR0H
#define 	UBRRL 	UBRR0L
#define 	UDRE 	UDRE0
#define 	UDR 	UDR0
#define 	RXC 	RXC0

#if BOOT_ADR > 0xFFFF
  #define PGM_READ_BYTE(x) pgm_read_byte_far(x)
#else
  #define PGM_READ_BYTE(x) pgm_read_byte(x)
#endif

// Just enable the UART Tx and set baud rate for 38400 on 3.6864MHz (STK500)

void UART_init(void) {
    UCSRB = (1 << TXEN0);
    UBRRL = USE_UART; // SEE HERE: http://wormfood.net/avrbaudcalc.php
}

// The classic Tx one character routine
void UART_put(uint8_t c) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = c;
}

// classic Tx a C-string routine
// As there is no .data (in the bootloader) it only makes sense for theis to use PSTR()
void UART_puts(const char * str) {
    char c;
    do {
        c = PGM_READ_BYTE(str++);
        if (c) {
            UART_put(c);
        }
    } while (c != 0);
}

// Just outputs "\r\n"
void UART_newline(void){
    UART_put('\r');
    UART_put('\n');
}

// used in printing a 2 digit hex number, outputs one of the two nibbles
// the parameter is expected to be 0..F
void UART_putnibble(uint8_t c) {
    if (c < 10) {
        UART_put('0' + c);
    }
    else {
        UART_put('A' + c - 10);
    }
}

// print both nibbles of an 8 bit hex number
void UART_puthex(uint8_t c) {
    UART_putnibble(c >> 4);
    UART_putnibble(c & 0x0F);
}

// print both bytes of a 16 bit hex number
void UART_puthex16(uint16_t n) {
	UART_puthex(n >> 8);
	UART_puthex(n & 0xFF);
}
// print both bytes of a 32 bit hex number
void UART_puthex32(uint32_t n) {
	UART_puthex(n >> 24);
	UART_puthex(n >> 16 & 0xFF);
	UART_puthex(n >> 8 & 0xFF);
	UART_puthex(n & 0xFF);
}

// this expect the first parameter to be a string in dlash (that is PSTR())
// and then the second to be a value to print out in hex. typically used in
// the form UART_putsP(PSTR("SecPerClus = "), SecPerClus)
void UART_putsP(const char * str, uint16_t n) {
    UART_puts(str);
    UART_puthex16(n);
    UART_newline();
}

// dump the 512 bytes at the given address in the form:
// CD BF 10 E0 A0 E6 B0 E0  E4 E5 F0 E0 02 C0 05 90   Ϳ ������� � �
void UART_dumpsector(uint8_t * Buff) {
    for (uint16_t i=0; i<512; i++) {
        if ((i % 16) == 0) {
            UART_put(' ');
            for(uint16_t j=(i -16); j<=i; j++) {
                UART_put(((Buff[j]>=(uint8_t)32) && (Buff[j]<(uint8_t)127)) ? Buff[j] : '.');
            }
            UART_newline();
        }
        UART_puthex(Buff[i]);
        UART_put(' ');
    }
    UART_newline();
}
