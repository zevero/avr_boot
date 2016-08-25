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

#define WILDFIRE_VERSION 3
#define CORE_WILDFIRE

// ATMEL ATmega32/A, ATmega324/P/A/PA, ATmega644/P/A/PA, ATmega1284/P on Wildfire
//                    Actual implementation with TQFP
//
//                                  +---\/---+
//   PCINT13/ICP3/MOSI  (D11) PB5  1|        |44  PB4 (D 9)** PCINT12/OC0B/SS
// PCINT14/OC3A/MISO ***(D12) PB6  2|        |43  PB3 (D 4)* PCINT11/AIN1/OC0A
//  PCINT15/OC3B/SCK ***(D13) PB7  3|        |42  PB2 (D22) PCINT10/AIN0/INT2
//                          RESET  4|        |41  PB1 (D23) PCINT9/T1/CLK0
//                            VCC  5|        |40  PB0 (D21) PCINT8/XCK0/T0
//                            GND  6|        |39  GND
//                          XTAL2  7|        |38  VCC
//                          XTAL1  8|        |37  PA0 (D24/AIN0) PCINT0/ADC0
//      PCINT24/RXD0/T3 (D 0) PD0  9|        |36  PA1 (D25/AIN1) PCINT1/ADC1
//         PCINT25/TXD0 (D 1) PD1 10|        |35  PA2 (D26/AIN2) PCINT2/ADC2
//    PCINT26/RXD1/INT0 (D 2) PD2 11|        |34  PA3 (D27/AIN3) PCINT3/ADC3
//    PCINT27/TXD1/INT1 (D 3) PD3 12|        |33  PA4 (D28/AIN4) PCINT4/ADC4
//   PCINT28/XCK1/OC1B *(D 8) PD4 13|        |32  PA5 (D29/AIN5) PCINT5/ADC5
//        PCINT29/OC1A *(D 5) PD5 14|        |31  PA6 (D30/AIN6) PCINT6/ADC6
//   PCINT30/OC2B/ICP **(D 6) PD6 15|        |30  PA7 (D31/AIN7) PCINT7/ADC7
//         PCINT31/OC2A (D10) PD7 16|        |29  AREF
//                            VCC 17|        |28  GND
//                            GND 18|        |27  AVCC
//          PCINT16/SCL (D20) PC0 19|        |26  PC7 (D18) PCINT23/TOSC2
//          PCINT17/SDA (D19) PC1 20|        |25  PC6 (D17) PCINT22/TOSC1
//          PCINT17/SDA (D15) PC2 21|        |24  PC5 (D16) PCINT21/TDI
//          PCINT17/SDA (D 7) PC3 22|        |23  PC4 (D14) PCINT20/TDO
//                                  +--------+
//
// D 2 dedicated to RFM69 IRQ                  *** do not set to output ***
// D22 dedicated to CC3000 IRQ                 *** do not set to ouput ***
// D 6 connected to LED (buffered) 
// D14 connected to tinyWDT pet interface 
// D 7 dedicated to RFM69 Chip Select          *** mutually exclusive output low ***
// D15 dedicated to External Flash Chip Select *** mutually exclusive output low ***
// D16 dedicated to SD Card Socket Chip Select *** mutually exclusive output low ***
// D21 dedicated to CC3000 Chip Select         *** mutually exclusive output low ***
// D17 dedicated to RTC crystal
// D18 dedicated to RTC crystal
// D23 dedicated to CC3000 VBAT
//
// * = PWM capable pin
// ** = PWM on ATmega324/P/A/PA, ATmega644/P/A/PA, ATmega1284/P only
// *** = PWM on ATmega1284/P only
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

#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 24 : -1)

#if defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
#define digitalPinHasPWM(p)         (((p) > 3) && ((p) < 14) && ((p) != 7) && ((p) != 11))
#elif defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__)
#define digitalPinHasPWM(p)         (((p) > 3) && ((p) < 12) && ((p) != 7) && ((p) != 11))
#elif defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)
#define digitalPinHasPWM(p)         (((p) == 4) || ((p) == 5) || ((p) == 8))
#endif

static const uint8_t SS   = 9;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 19;
static const uint8_t SCL = 20;
static const uint8_t LED_BUILTIN = 6;

static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;
static const uint8_t A4 = 28;
static const uint8_t A5 = 29;
static const uint8_t A6 = 30;
static const uint8_t A7 = 31;

#if defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) ((p) > 23 ? 0 : (((p) > 13 && (p) < 21) || ((p) == 7) ? 2 : (((p) > 10) || ((p) == 9) || ((p) == 4) ? 1 : 3)))
#define digitalPinToPCMSK(p)    ((p) < 32 ? ((p) > 23 ? (&PCMSK0) : (((p) > 13 && (p) < 21) || ((p) == 7) ? (&PCMSK2) : (((p) > 10) || ((p) == 9) || ((p) == 4) ? (&PCMSK1) : (&PCMSK3)))) : ((uint8_t *)0))
#define digitalPinToPCMSKbit(p) (pgm_read_byte(digital_pin_to_PCMSK_bit_PGM + p))
#endif

#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT (-1)
#endif
#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) == 22 ? 2 : NOT_AN_INTERRUPT)))

#ifndef ARDUINO_MAIN
extern const uint8_t PROGMEM digital_pin_to_PCMSK_bit_PGM[];
#endif

#ifdef ARDUINO_MAIN
#define PA 1
#define PB 2
#define PC 3
#define PD 4

#if defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
// this was just too complicated to express as a formula, and we have plenty of flash memory 
const uint8_t PROGMEM digital_pin_to_PCMSK_bit_PGM[] = {
  0,
  1,
  2,
  3,
  3,
  5,
  6,
  3,
  4,
  4,
  7,
  5,
  6,
  7,
  4,
  2,
  5,
  6,
  7,
  1,
  0,
  0,
  2,
  1,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7
};
#endif	//defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)

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
  PD, 
  PD,
  PD,
  PD,
  PB,
  PD,
  PD,
  PC,
  
  PD, 
  PB,
  PD,
  PB,
  PB,
  PB,
  PC,
  PC,
  
  PC,  
  PC,
  PC,
  PC,
  PC,
  PB,
  PB,
  PB,
  
  PA, 
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PA
};


const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
  _BV(0), // PD
  _BV(1), // PD
  _BV(2), // PD
  _BV(3), // PD
  _BV(3), // PB
  _BV(5), // PD
  _BV(6), // PD
  _BV(3), // PC
  _BV(4), // PD
  _BV(4), // PB
  _BV(7), // PD
  _BV(5), // PB
  _BV(6), // PB
  _BV(7), // PB
  _BV(4), // PC
  _BV(2), // PC
  _BV(5), // PC
  _BV(6), // PC
  _BV(7), // PC
  _BV(1), // PC
  _BV(0), // PC
  _BV(0), // PB
  _BV(2), // PB
  _BV(1), // PB
  _BV(0), // PA
  _BV(1), // PA
  _BV(2), // PA
  _BV(3), // PA
  _BV(4), // PA
  _BV(5), // PA
  _BV(6), // PA
  _BV(7)  // PA
};

#if defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)
#ifndef TIMER0
#define TIMER0 1
#endif	//TIMER0
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, // PD0
  NOT_ON_TIMER, // PD1
  NOT_ON_TIMER, // PD2
  NOT_ON_TIMER, // PD3
  TIMER0,       // PB3
  TIMER1A,      // PD5
  NOT_ON_TIMER, // PD6
  NOT_ON_TIMER, // PC3

  TIMER1B,      // PD4
  NOT_ON_TIMER, // PB4
  TIMER2,       // PD7
  NOT_ON_TIMER, // PB5
  NOT_ON_TIMER, // PB6
  NOT_ON_TIMER, // PB7
  NOT_ON_TIMER, // PC4
  NOT_ON_TIMER, // PC2

  NOT_ON_TIMER, // PC5
  NOT_ON_TIMER, // PC6
  NOT_ON_TIMER, // PC7
  NOT_ON_TIMER, // PC1
  NOT_ON_TIMER, // PC0
  NOT_ON_TIMER, // PB0
  NOT_ON_TIMER, // PB2
  NOT_ON_TIMER, // PB1

  NOT_ON_TIMER, // PA0
  NOT_ON_TIMER, // PA1
  NOT_ON_TIMER, // PA2
  NOT_ON_TIMER, // PA3
  NOT_ON_TIMER, // PA4
  NOT_ON_TIMER, // PA5
  NOT_ON_TIMER, // PA6
  NOT_ON_TIMER, // PA7
};

#elif defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, // PD0
  NOT_ON_TIMER, // PD1
  NOT_ON_TIMER, // PD2
  NOT_ON_TIMER, // PD3
  TIMER0A,      // PB3
  TIMER1A,      // PD5
  TIMER2B,      // PD6
  NOT_ON_TIMER, // PC3

  TIMER1B,      // PD4
  TIMER0B,      // PB4
  TIMER2A,      // PD7
  NOT_ON_TIMER, // PB5
  NOT_ON_TIMER, // PB6
  NOT_ON_TIMER, // PB7
  NOT_ON_TIMER, // PC4
  NOT_ON_TIMER, // PC2

  NOT_ON_TIMER, // PC5
  NOT_ON_TIMER, // PC6
  NOT_ON_TIMER, // PC7
  NOT_ON_TIMER, // PC1
  NOT_ON_TIMER, // PC0
  NOT_ON_TIMER, // PB0
  NOT_ON_TIMER, // PB2
  NOT_ON_TIMER, // PB1

  NOT_ON_TIMER, // PA0
  NOT_ON_TIMER, // PA1
  NOT_ON_TIMER, // PA2
  NOT_ON_TIMER, // PA3
  NOT_ON_TIMER, // PA4
  NOT_ON_TIMER, // PA5
  NOT_ON_TIMER, // PA6
  NOT_ON_TIMER, // PA7
};

#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, // PD0
  NOT_ON_TIMER, // PD1
  NOT_ON_TIMER, // PD2
  NOT_ON_TIMER, // PD3
  TIMER0A,      // PB3
  TIMER1A,      // PD5
  TIMER2B,      // PD6
  NOT_ON_TIMER, // PC3

  TIMER1B,      // PD4
  TIMER0B,      // PB4
  TIMER2A,      // PD7
  NOT_ON_TIMER, // PB5
  TIMER3A,      // PB6
  TIMER3B,      // PB7
  NOT_ON_TIMER, // PC4
  NOT_ON_TIMER, // PC2

  NOT_ON_TIMER, // PC5
  NOT_ON_TIMER, // PC6
  NOT_ON_TIMER, // PC7
  NOT_ON_TIMER, // PC1
  NOT_ON_TIMER, // PC0
  NOT_ON_TIMER, // PB0
  NOT_ON_TIMER, // PB2
  NOT_ON_TIMER, // PB1

  NOT_ON_TIMER, // PA0
  NOT_ON_TIMER, // PA1
  NOT_ON_TIMER, // PA2
  NOT_ON_TIMER, // PA3
  NOT_ON_TIMER, // PA4
  NOT_ON_TIMER, // PA5
  NOT_ON_TIMER, // PA6
  NOT_ON_TIMER, // PA7
};
#endif  //defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)

#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
