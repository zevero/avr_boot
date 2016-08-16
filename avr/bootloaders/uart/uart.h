#include <avr/io.h>
#include <avr/pgmspace.h>

/*
** This is a simple set of UART routines for debug purposes
** It's Tx only and the baud rate is fixed (see UART_init)
*/

// Just enable the UART Tx and set baud rate for 38400 on 3.6864MHz (STK500)
void UART_init(void);
// The classic Tx one character routine
void UART_put(uint8_t c);
// classic Tx a C-string routine (string in PROGMEM)
void UART_puts(const char * str);
// this expect the first parameter to be a string in dlash (that is PSTR())
// and then the second to be a value to print out in hex. typically used in
// the form UART_putsP(PSTR("SecPerClus = "), SecPerClus)
void UART_putsP(const char * str, uint16_t n);
// Just outputs "\r\n"
void UART_newline(void);
// used in printing a 2 digit hex number, outputs one of the two nibbles
// the parameter is expected to be 0..F
void UART_putnibble(uint8_t c);
// print both nibbles of an 8 bit hex number
void UART_puthex(uint8_t c);
// print both bytes of a 16 bit hex number
void UART_puthex16(uint16_t n);
// print both bytes of a 32 bit hex number
void UART_puthex32(uint32_t n);
// dump the 512 bytes at the given address in the form:
// CD BF 10 E0 A0 E6 B0 E0  E4 E5 F0 E0 02 C0 05 90   Ϳ ������� � �
void UART_dumpsector(uint8_t * Buff);
