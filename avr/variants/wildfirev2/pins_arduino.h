//
//
// Pins definitions for Wildfire 1284P
// Original file from Maniacbug's Mighty-1284 core
// This version by Victor Aprea (22nd September 2013)
//
//

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define WILDFIRE_VERSION 2
#define CORE_WILDFIRE

//                    ATMEL ATMEGA1284P on Wildfire
//                    Actual implementation with TQFP
//
//                                +---\/---+
// PCINT13/ICP3/MOSI  (D11) PB5  1|        |44  PB4 (D10)* PCINT12/OC0B/SS
// PCINT14/OC3A/MISO *(D12) PB6  2|        |43  PB3 (D 9)* PCINT11/AIN1/OC0A
//  PCINT15/OC3B/SCK *(D13) PB7  3|        |42  PB2 (D 8) PCINT10/AIN0/INT2
//                        RESET  4|        |41  PB1 (D23) PCINT9/T1/CLK0
//                          VCC  5|        |40  PB0 (D22) PCINT8/XCK0/T0
//                          GND  6|        |39  GND
//                        XTAL2  7|        |38  VCC
//                        XTAL1  8|        |37  PA0 (D14/AIN0) PCINT0/ADC0
//    PCINT24/RXD0/T3 (D 0) PD0  9|        |36  PA1 (D15/AIN1) PCINT1/ADC1
//       PCINT25/TXD0 (D 1) PD1 10|        |35  PA2 (D16/AIN2) PCINT2/ADC2
//  PCINT26/RXD1/INT0 (D 2) PD2 11|        |34  PA3 (D17/AIN3) PCINT3/ADC3
//  PCINT27/TXD1/INT1 (D 3) PD3 12|        |33  PA4 (D18/AIN4) PCINT4/ADC4
// PCINT28/XCK1/OC1B *(D 4) PD4 13|        |32  PA5 (D19/AIN5) PCINT5/ADC5
//      PCINT29/OC1A *(D 5) PD5 14|        |31  PA6 (D20/AIN6) PCINT6/ADC6
//   PCINT30/OC2B/ICP (D 6) PD6 15|        |30  PA7 (D21/AIN7) PCINT7/ADC7
//       PCINT31/OC2A (D 7) PD7 16|        |29  AREF
//                          VCC 17|        |28  GND
//                          GND 18|        |27  AVCC
//        PCINT16/SCL (D19) PC0 19|        |26  PC7 (D25) PCINT23/TOSC2
//        PCINT17/SDA (D27) PC1 20|        |25  PC6 (D24) PCINT22/TOSC1
//        PCINT17/SDA (D18) PC2 21|        |24  PC5 (D31) PCINT21/TDI
//        PCINT17/SDA (D26) PC3 22|        |23  PC4 (D30) PCINT20/TDO
//                                +--------+
//
// D 8 dedicated to CC3000 IRQ                 *** do not set to ouput ***
// D 4 dedicated to SD Card Socket Chip Select *** mutually exclusive output low ***
// D10 dedicated to CC3000 Chip Select         *** mutually exclusive output low ***
// D 7 dedicated to MAC/EEPROM Chip
// D 9 dedicated to CC3000 VBAT
//
// * = PWM capable pin
// TOSCn = RTC Crystal pinout
// TCK/TMS/TDO/TDI = JTAG pinout

/*                       
                         PCICR
   PCINT7-0:   D31-24  : bit 0   
   PCINT15-8:  D15- 8  : bit 1
   PCINT23-16: D23-16  : bit 2
   PCINT31-24: D 7- 0  : bit 3
*/

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8

#define analogInputToDigitalPin(p)  (((p) < 2) ? ((p) + 30) : (((p) < NUM_ANALOG_INPUTS) ? ((p) + 24) : -1))
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 9 || (p) == 10 || (p) == 12 || (p) == 13)

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 17;
static const uint8_t SCL = 16;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;
static const uint8_t A6 = 20;
static const uint8_t A7 = 21;

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 3 : (((p) <= 15) ? 1 : (((p) <= 23) ? 2 : 0)))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK3) : (((p) <= 15) ? (&PCMSK1) : (((p) <= 23) ? (&PCMSK2) : (&PCMSK0) )))

#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT (-1)
#endif
#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) == 8 ? 2 : NOT_AN_INTERRUPT)))

// The special case here, created by keeping the SPI interface on Arduino Uno pin numbering.
#define digitalPinToPCMSKbit(p) (((p) > 7 && (p) < 16) ? (((p) < 14 ? (p)+2 : (p)-6) % 8) : ((p) % 8))

#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
	PD, /* 0 */
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PB, /* 8 */
	PB,
	PB,
	PB,
	PB,
	PB,
	PA,
	PA,
	PA, /* 16 */
	PA,
	PA,		
	PA,	
	PA,	
	PA,	
	PB, 
	PB,	
	PC, /* 24 */
	PC,	
	PC,
	PC,	
	PC,
	PC,	
	PC,
	PC  /* 31 */
};


const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
	_BV(0), /* 0, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(2), /* 8, port B */
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7), 
	_BV(0), /* 14, port A */
	_BV(1),
	_BV(2), 
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 22, port B */
	_BV(1),
	_BV(6), /* 24, port C */
	_BV(7),
	_BV(1),
	_BV(0),
	_BV(2),
	_BV(3),
	_BV(4), 
	_BV(5),	
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
	NOT_ON_TIMER, 	/* 0  - PD0 */
	NOT_ON_TIMER, 	/* 1  - PD1 */
	NOT_ON_TIMER, 	/* 2  - PD2 */
	NOT_ON_TIMER, 	/* 3  - PD3 */
	TIMER1B,      	/* 4  - PD4 */
	TIMER1A,       	/* 5  - PD5 */
	TIMER2B,       	/* 6  - PD6 */
	TIMER2A,       	/* 7  - PD7 */

	NOT_ON_TIMER, 	/* 8  - PB2 */
	TIMER0A,     	  /* 9  - PB3 */
	TIMER0B,        /* 10 - PB4 */
	NOT_ON_TIMER, 	/* 11 - PB5 */
	TIMER3A,        /* 12 - PB6 */
	TIMER3B,        /* 13 - PB7 */
	NOT_ON_TIMER, 	/* 14 - PA0 */
	NOT_ON_TIMER, 	/* 15 - PA1 */	

	NOT_ON_TIMER, 	/* 16 - PA2 */
	NOT_ON_TIMER,   /* 17 - PA3 */
	NOT_ON_TIMER,   /* 18 - PA4 */
	NOT_ON_TIMER,   /* 19 - PA5 */
	NOT_ON_TIMER,   /* 20 - PA6 */
	NOT_ON_TIMER,   /* 21 - PA7 */
	NOT_ON_TIMER,   /* 22 - PB0 */
	NOT_ON_TIMER,   /* 23 - PB1 */
	
	NOT_ON_TIMER,   /* 24 - PC6 */
	NOT_ON_TIMER,   /* 25 - PC7 */
	NOT_ON_TIMER,   /* 26 - PC1 */
	NOT_ON_TIMER,   /* 27 - PC0 */
	NOT_ON_TIMER,   /* 28 - PC2 */
	NOT_ON_TIMER,   /* 29 - PC3 */
	NOT_ON_TIMER,   /* 30 - PC4 */
	NOT_ON_TIMER    /* 31 - PC5 */
};

#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
