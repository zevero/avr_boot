/*
  Arduino variant file for Wiring S
  Pin mapping based on: http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/WiringS/BoardInfo.txt?revision=1138

  Based on the avr_developers variant file by David A. Mellis: http://avr-developers.com/corefiles/index.html

  Part of Arduino / Wiring Lite
  Copyright (c) 2005 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// Atmel ATmega1284/P, 644/P/A/PA, 324/P/A/PA, 32/A
//
//                       +---\/---+
//            (16) PB0  1|        |40 PA0 (A0/24)
//            (17) PB1  2|        |39 PA1 (A1/25)
//       INT2 (18) PB2  3|        |38 PA2 (A2/26)
//        PWM (19) PB3  4|        |37 PA3 (A3/27)
//    PWM* SS (20) PB4  5|        |36 PA4 (A4/28)
//       MOSI (21) PB5  6|        |35 PA5 (A5/29)
// PWM** MISO (22) PB6  7|        |34 PA6 (A6/30)
//  PWM** SCK (23) PB7  8|        |33 PA7 (A7/31)
//                 RST  9|        |32 AREF
//                 VCC 10|        |31 GND
//                 GND 11|        |30 AVCC
//               XTAL2 12|        |29 PC7 (15)
//               XTAL1 13|        |28 PC6 (14)
//         RX0 (0) PD0 14|        |27 PC5 (13) TDI
//         TX0 (1) PD1 15|        |26 PC4 (12) TDO
//    INT0 RX1 (2) PD2 16|        |25 PC3 (11) TMS
//    INT1 TX1 (3) PD3 17|        |24 PC2 (10) TCK
//         PWM (4) PD4 18|        |23 PC1 (9)  SDA
//         PWM (5) PD5 19|        |22 PC0 (8)  SCL
//        PWM* (6) PD6 20|        |21 PD7 (7)  PWM
//                       +--------+
//
// *ATmega324/P/A/PA, ATmega644/P/A/PA, ATmega1284/P only
// **ATmega1284/P only


#define NUM_DIGITAL_PINS 32
#define NUM_ANALOG_INPUTS 8
#define analogInputToDigitalPin(p) ((p) < NUM_ANALOG_INPUTS ? 24 + (p) : -1)
#define digitalPinToAnalogPin(p) ((p) >= 24 && (p) <= 31 ? (p) - 24 : -1)
#define analogPinToChannel(p) ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 24 ? 24 + (p) : -1)

#if defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
#define digitalPinHasPWM(p) ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 19 || (p) == 20 || (p) == 22 || (p) == 23)
#elif defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__)
#define digitalPinHasPWM(p) ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 19 || (p) == 20)
#elif defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)
#define digitalPinHasPWM(p) ((p) == 4 || (p) == 5 || (p) == 7 || (p) == 19)
#endif

static const uint8_t SS = 20;
static const uint8_t MOSI = 21;
static const uint8_t MISO = 22;
static const uint8_t SCK = 23;

static const uint8_t SDA = 9;
static const uint8_t SCL = 8;

#define LED_BUILTIN 15;

static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;
static const uint8_t A4 = 28;
static const uint8_t A5 = 29;
static const uint8_t A6 = 30;
static const uint8_t A7 = 31;

#if defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
#define digitalPinToPCICR(p) ((p) >= 0 && (p) < NUM_DIGITAL_PINS ? &PCICR : (uint8_t *)0)
#define digitalPinToPCICRbit(p) ((p) <= 7 ? 3 : (p) <= 15 ? 2 : (p) <= 23 ? 1 : 0)
#define digitalPinToPCMSK(p) ((p) <= 7 ? &PCMSK3 : (p) <= 15 ? &PCMSK2 : (p) <= 23 ? &PCMSK1 : &PCMSK0)
#define digitalPinToPCMSKbit(p) ((p) % 8)
#endif

// return associated INTx number for associated/valid pins,
// otherwise NOT_AN_INTERRUPT
#define digitalPinToInterrupt(p) \
	(\
	(p) == 2 ? 0 : \
	(p) == 3 ? 1 : \
	(p) == 18 ? 2 : \
	NOT_AN_INTERRUPT)


#define PA 1
#define PB 2
#define PC 3
#define PD 4

// specify port for each Arduino pin 0-31
#define PORT_D0 PD
#define PORT_D1 PD
#define PORT_D2 PD
#define PORT_D3 PD
#define PORT_D4 PD
#define PORT_D5 PD
#define PORT_D6 PD
#define PORT_D7 PD
#define PORT_D8 PC
#define PORT_D9 PC
#define PORT_D10 PC
#define PORT_D11 PC
#define PORT_D12 PC
#define PORT_D13 PC
#define PORT_D14 PC
#define PORT_D15 PC
#define PORT_D16 PB
#define PORT_D17 PB
#define PORT_D18 PB
#define PORT_D19 PB
#define PORT_D20 PB
#define PORT_D21 PB
#define PORT_D22 PB
#define PORT_D23 PB
#define PORT_D24 PA
#define PORT_D25 PA
#define PORT_D26 PA
#define PORT_D27 PA
#define PORT_D28 PA
#define PORT_D29 PA
#define PORT_D30 PA
#define PORT_D31 PA

// specify port bit for each Arduino pin 0-31
#define BIT_D0 0
#define BIT_D1 1
#define BIT_D2 2
#define BIT_D3 3
#define BIT_D4 4
#define BIT_D5 5
#define BIT_D6 6
#define BIT_D7 7
#define BIT_D8 0
#define BIT_D9 1
#define BIT_D10 2
#define BIT_D11 3
#define BIT_D12 4
#define BIT_D13 5
#define BIT_D14 6
#define BIT_D15 7
#define BIT_D16 0
#define BIT_D17 1
#define BIT_D18 2
#define BIT_D19 3
#define BIT_D20 4
#define BIT_D21 5
#define BIT_D22 6
#define BIT_D23 7
#define BIT_D24 0
#define BIT_D25 1
#define BIT_D26 2
#define BIT_D27 3
#define BIT_D28 4
#define BIT_D29 5
#define BIT_D30 6
#define BIT_D31 7

// macro equivalents of PROGMEM arrays port_to_mode_PGM[] etc. below
#define PORT_TO_MODE(x) (x == 1 ? &DDRA : (x == 2 ? &DDRB : (x == 3 ? &DDRC : (x == 4 ? &DDRD : NOT_A_PORT))))
#define PORT_TO_OUTPUT(x) (x == 1 ? &PORTA : (x == 2 ? &PORTB : (x == 3 ? &PORTC : (x == 4 ? &PORTD : NOT_A_PORT))))
#define PORT_TO_INPUT(x) (x == 1 ? &PINA : (x == 2 ? &PINB : (x == 3 ? &PINC : (x == 4 ? &PIND : NOT_A_PORT))))

#ifdef ARDUINO_MAIN
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

const uint8_t PROGMEM digital_pin_to_port_PGM[NUM_DIGITAL_PINS] =
{
  PORT_D0,
  PORT_D1,
  PORT_D2,
  PORT_D3,
  PORT_D4,
  PORT_D5,
  PORT_D6,
  PORT_D7,
  PORT_D8,
  PORT_D9,
  PORT_D10,
  PORT_D11,
  PORT_D12,
  PORT_D13,
  PORT_D14,
  PORT_D15,
  PORT_D16,
  PORT_D17,
  PORT_D18,
  PORT_D19,
  PORT_D20,
  PORT_D21,
  PORT_D22,
  PORT_D23,
  PORT_D24,
  PORT_D25,
  PORT_D26,
  PORT_D27,
  PORT_D28,
  PORT_D29,
  PORT_D30,
  PORT_D31
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[NUM_DIGITAL_PINS] =
{
  _BV(BIT_D0),
  _BV(BIT_D1),
  _BV(BIT_D2),
  _BV(BIT_D3),
  _BV(BIT_D4),
  _BV(BIT_D5),
  _BV(BIT_D6),
  _BV(BIT_D7),
  _BV(BIT_D8),
  _BV(BIT_D9),
  _BV(BIT_D10),
  _BV(BIT_D11),
  _BV(BIT_D12),
  _BV(BIT_D13),
  _BV(BIT_D14),
  _BV(BIT_D15),
  _BV(BIT_D16),
  _BV(BIT_D17),
  _BV(BIT_D18),
  _BV(BIT_D19),
  _BV(BIT_D20),
  _BV(BIT_D21),
  _BV(BIT_D22),
  _BV(BIT_D23),
  _BV(BIT_D24),
  _BV(BIT_D25),
  _BV(BIT_D26),
  _BV(BIT_D27),
  _BV(BIT_D28),
  _BV(BIT_D29),
  _BV(BIT_D30),
  _BV(BIT_D31)
};

#if defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)
#ifndef TIMER0
#define TIMER0 1
#endif  //TIMER0
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  TIMER1B,  //4
  TIMER1A,  //5
  NOT_ON_TIMER, //6
  TIMER2, //7
  NOT_ON_TIMER, //8
  NOT_ON_TIMER, //9
  NOT_ON_TIMER, //10
  NOT_ON_TIMER, //11
  NOT_ON_TIMER, //12
  NOT_ON_TIMER, //13
  NOT_ON_TIMER, //14
  NOT_ON_TIMER, //15
  NOT_ON_TIMER, //16
  NOT_ON_TIMER, //17
  NOT_ON_TIMER, //18
  TIMER0, //19
  NOT_ON_TIMER, //20
  NOT_ON_TIMER, //22
  NOT_ON_TIMER, //23
  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
  NOT_ON_TIMER, //28
  NOT_ON_TIMER, //29
  NOT_ON_TIMER, //30
  NOT_ON_TIMER  //31
};

#elif defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644PA__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  TIMER1B,  //4
  TIMER1A,  //5
  TIMER2B,  //6
  TIMER2A,  //7
  NOT_ON_TIMER, //8
  NOT_ON_TIMER, //9
  NOT_ON_TIMER, //10
  NOT_ON_TIMER, //11
  NOT_ON_TIMER, //12
  NOT_ON_TIMER, //13
  NOT_ON_TIMER, //14
  NOT_ON_TIMER, //15
  NOT_ON_TIMER, //16
  NOT_ON_TIMER, //17
  NOT_ON_TIMER, //18
  TIMER0A,  //19
  TIMER0B,  //20
  NOT_ON_TIMER, //21
  NOT_ON_TIMER, //22
  NOT_ON_TIMER, //23
  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
  NOT_ON_TIMER, //28
  NOT_ON_TIMER, //29
  NOT_ON_TIMER, //30
  NOT_ON_TIMER  //31
};

#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  TIMER1B,  //4
  TIMER1A,  //5
  TIMER2B,  //6
  TIMER2A,  //7
  NOT_ON_TIMER, //8
  NOT_ON_TIMER, //9
  NOT_ON_TIMER, //10
  NOT_ON_TIMER, //11
  NOT_ON_TIMER, //12
  NOT_ON_TIMER, //13
  NOT_ON_TIMER, //14
  NOT_ON_TIMER, //15
  NOT_ON_TIMER, //16
  NOT_ON_TIMER, //17
  NOT_ON_TIMER, //18
  TIMER0A,  //19
  TIMER0B,  //20
  NOT_ON_TIMER, //21
  TIMER3A, //22
  TIMER3B, //23
  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
  NOT_ON_TIMER, //28
  NOT_ON_TIMER, //29
  NOT_ON_TIMER, //30
  NOT_ON_TIMER  //31
};
#endif  //defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)

#endif  //ARDUINO_MAIN
#endif  //Pins_Arduino_h
