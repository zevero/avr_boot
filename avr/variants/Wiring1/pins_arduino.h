// Arduino variant file for Wiring V1.0/Wiring Mini V1.0/Wiring V1.1 ATmega1281 / Wiring V1.1 ATmega2561 boards
// Pin mapping from: http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/Wiring1/BoardInfo.txt?revision=1143
// and http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/Wiring1.1/BoardInfo.txt?revision=1232
//
// Based on the MegaCore standard variant file created by MCUdude https://github.com/MCUdude/MegaCore
//
// ARD.   AVR
// PINS   PINS
// |>      |               A0  A1  A2  A3  A4  A5  A6  A7
// |>      |               40  41  42  43  44  45  46  47          16  17  18
// |       | > AVC GND ARE PF0 PF1 PF2 PF3 PF4 PF5 PF6 PF7 GND VCC PA0 PA1 PA2
// V       V    -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
// 53 PG5*/PEN |                                                             | PA3 19
// 32    PE0   |                                                             | PA4 20
// 33    PE1   |                                                             | PA5 21
// 34    PE2   |                                                             | PA6 22
// 35    PE3   |                                                             | PA7 23
// 36    PE4   |                                                             | PG2 50
// 37    PE5   |                                                             | PC7 15
// 38    PE6   |                                                             | PC6 14
// 39    PE7   |                                                             | PC5 13
// 24    PB0   |                                                             | PC4 12
// 25    PB1   |                                                             | PC3 11
// 26    PB2   |                                                             | PC2 10
// 27    PB3   |                                                             | PC1 9
// 28    PB4   |                                                             | PC0 8
// 29    PB5   |                                                             | PG1 49
// 30    PB6   |                                                             | PG0 48
//              -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
//             PB7 PG3 PG4 RST VCC GND XT2 XT1 PD0 PD1 PD2 PD3 PD4 PD5 PD6 PD7
//             31  51  52                       0   1   2   3   4   5   6   7
//
// *ATmega1281/2561 only

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#include <avr/pgmspace.h>

#define NUM_ANALOG_INPUTS 8
#define analogInputToDigitalPin(p) (((p) < 8) ? (p) + 40 : -1)

#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define NUM_DIGITAL_PINS 54
#define digitalPinHasPWM(p) (((p) >= 28 && (p) <= 31) || ((p) >= 35 && (p) <= 37) || (p) == 53)

#define digitalPinToPCICR(p) ((((p) >= 24 && (p) <= 31) || (p) == 32) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) >= 24 && (p) <= 31) ? 0 : ((p) == 32) ? 1 : 0)
#define digitalPinToPCMSK(p) (((p) >= 24 && (p) <= 31) ? (&PCMSK0) : ((p) == 32) ? (&PCMSK1) : ((uint8_t *)0))
#define digitalPinToPCMSKbit(p) (((p) >= 24 && (p) <= 31) ? (p) - 24 : 0)
#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega64A__) || defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__)  //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define NUM_DIGITAL_PINS 53
#define digitalPinHasPWM(p) (((p) >= 28 && (p) <= 31) || ((p) >= 35 && (p) <= 37))
#endif //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)

#define digitalPinToInterrupt(p) (((p) >= 0 && (p) <= 3) ? (p) : ((p) >= 36 && (p) <= 39) ? (p) - 32 : NOT_AN_INTERRUPT)

static const uint8_t SS = 24;
static const uint8_t SCK = 25;
static const uint8_t MOSI = 26;
static const uint8_t MISO = 27;

#define LED_BUILTIN 48

static const uint8_t SDA = 1;
static const uint8_t SCL = 0;

static const uint8_t A0 = 16;
static const uint8_t A1 = 17;
static const uint8_t A2 = 18;
static const uint8_t A3 = 19;
static const uint8_t A4 = 20;
static const uint8_t A5 = 21;
static const uint8_t A6 = 22;
static const uint8_t A7 = 23;


#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
  (uint16_t) &DDRE,
  (uint16_t) &DDRF,
  (uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
  (uint16_t) &PORTE,
  (uint16_t) &PORTF,
  (uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
  NOT_A_PIN,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
  (uint16_t) &PINE,
  (uint16_t) &PINF,
  (uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
  PD, //0
  PD, //1
  PD, //2
  PD, //3
  PD, //4
  PD, //5
  PD, //6
  PD, //7

  PC, //8
  PC, //9
  PC, //10
  PC, //11
  PC, //12
  PC, //13
  PC, //14
  PC, //15

  PA, //16
  PA, //17
  PA, //18
  PA, //19
  PA, //20
  PA, //21
  PA, //22

  PB, //23
  PB, //24
  PB, //25
  PB, //26
  PB, //27
  PB, //28
  PB, //29
  PB, //30
  PB, //31

  PE, //32
  PE, //33
  PE, //34
  PE, //35
  PE, //36
  PE, //37
  PE, //38
  PE, //39

  PF, //40
  PF, //41
  PF, //42
  PF, //43
  PF, //44
  PF, //45
  PF, //46
  PF, //47

  PG, //48
  PG, //49
  PG, //50
  PG, //51
  PG, //52
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  PG, //53
#endif
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
  _BV(0), //0
  _BV(1), //1
  _BV(2), //2
  _BV(3), //3
  _BV(4), //4
  _BV(5), //5
  _BV(6), //6
  _BV(7), //7

  _BV(0), //8
  _BV(1), //9
  _BV(2), //10
  _BV(3), //11
  _BV(4), //12
  _BV(5), //13
  _BV(6), //14
  _BV(7), //15

  _BV(0), //16
  _BV(1), //17
  _BV(2), //18
  _BV(3), //19
  _BV(4), //20
  _BV(5), //21
  _BV(6), //22
  _BV(7), //23

  _BV(0), //24
  _BV(1), //25
  _BV(2), //26
  _BV(3), //27
  _BV(4), //28
  _BV(5), //29
  _BV(6), //30
  _BV(7), //31

  _BV(0), //32
  _BV(1), //33
  _BV(2), //34
  _BV(3), //35
  _BV(4), //36
  _BV(5), //37
  _BV(6), //38
  _BV(7), //39

  _BV(0), //40
  _BV(1), //41
  _BV(2), //42
  _BV(3), //43
  _BV(4), //44
  _BV(5), //45
  _BV(6), //46
  _BV(7), //47

  _BV(0), //48
  _BV(1), //49
  _BV(2), //50
  _BV(3), //51
  _BV(4), //52
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  _BV(5), //53
#endif
};

#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega64A__) || defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__)
#ifndef TIMER0
#define TIMER0 1  //https://github.com/MCUdude/MegaCore/commit/04d61e6a0c1e6fe077e895b67b6e5ec15bc5a339
#endif  //TIMER0
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  NOT_ON_TIMER, //4
  NOT_ON_TIMER, //5
  NOT_ON_TIMER, //6
  NOT_ON_TIMER, //7

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
  NOT_ON_TIMER, //19
  NOT_ON_TIMER, //20
  NOT_ON_TIMER, //21
  NOT_ON_TIMER, //22
  NOT_ON_TIMER, //23

  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
  TIMER0, //28
  TIMER1A,  //29
  TIMER1B,  //30
  TIMER1C,  //31

  NOT_ON_TIMER, //32
  NOT_ON_TIMER, //33
  NOT_ON_TIMER, //34
  TIMER3A,  //35
  TIMER3B,  //36
  TIMER3C,  //37
  NOT_ON_TIMER, //38
  NOT_ON_TIMER, //39

  NOT_ON_TIMER, //40
  NOT_ON_TIMER, //41
  NOT_ON_TIMER, //42
  NOT_ON_TIMER, //43
  NOT_ON_TIMER, //44
  NOT_ON_TIMER, //45
  NOT_ON_TIMER, //46
  NOT_ON_TIMER, //47

  NOT_ON_TIMER, //48
  NOT_ON_TIMER, //49
  NOT_ON_TIMER, //50
  NOT_ON_TIMER, //51
  NOT_ON_TIMER, //52
};

#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  NOT_ON_TIMER, //4
  NOT_ON_TIMER, //5
  NOT_ON_TIMER, //6
  NOT_ON_TIMER, //7

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
  NOT_ON_TIMER, //19
  NOT_ON_TIMER, //20
  NOT_ON_TIMER, //21
  NOT_ON_TIMER, //22
  NOT_ON_TIMER, //23

  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
  TIMER2A,  //28
  TIMER1A,  //29
  TIMER1B,  //30
  TIMER1C,  //31

  NOT_ON_TIMER, //32
  NOT_ON_TIMER, //33
  NOT_ON_TIMER, //34
  TIMER3A,  //35
  TIMER3B,  //36
  TIMER3C,  //37
  NOT_ON_TIMER, //38
  NOT_ON_TIMER, //39

  NOT_ON_TIMER, //40
  NOT_ON_TIMER, //41
  NOT_ON_TIMER, //42
  NOT_ON_TIMER, //43
  NOT_ON_TIMER, //44
  NOT_ON_TIMER, //45
  NOT_ON_TIMER, //46
  NOT_ON_TIMER, //47

  NOT_ON_TIMER, //48
  NOT_ON_TIMER, //49
  NOT_ON_TIMER, //50
  NOT_ON_TIMER, //51
  NOT_ON_TIMER, //52
  TIMER0B,  //53
};
#endif  //defined(__AVR_ATmega64__) || defined(__AVR_ATmega64A__) || defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__)

#endif  //ARDUINO_MAIN
#endif  //Pins_Arduino_h
