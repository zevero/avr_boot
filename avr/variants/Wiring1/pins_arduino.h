// MEGACORE - ATmega64/128 pin mapping
// Created by MCUdude
// https://github.com/MCUdude/MegaCore
//
//      ARD.     AVR
//      PINS     PINS
//      |>        |                     A0   A1   A2   A3   A4   A5   A6   A7
//      |>        |                     D45  D46  D47  D48  D49  D50  D51  D52            D44  D43  D42
//      |         | >    AVC  GND  ARE  PF0  PF1  PF2  PF3  PF4  PF5  PF6  PF7  GND  VCC  PA0  PA1  PA2
//      V         V       -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
//               PEN    |                                                                              | PA3    D41
//      D0       PE0    |                                                                              | PA4    D40
//      D1       PE1    |                                                                              | PA5    D39
//      D2       PE2    |                                                                              | PA6    D38
//      D3       PE3    |                                                                              | PA7    D37
//      D4       PE4    |                                                                              | PG2    D36
//      D5       PE5    |                                                                              | PC7    D35
//      D6       PE6    |                                                                              | PC6    D34
//      D7       PE7    |                                                                              | PC5    D33
//      D8       PB0    |                                                                              | PC4    D32
//      D9       PB1    |                                                                              | PC3    D31
//      D10      PB2    |                                                                              | PC2    D30
//      D11      PB3    |                                                                              | PC1    D29
//      D12      PB4    |                                                                              | PC0    D28
//      D13      PB5    |                                                                              | PG1    D27
//      D14      PB6    |                                                                              | PG0    D26
//                        -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
//                       PB7  PG3  PG4  RST  VCC  GND  XT2  XT1  PD0  PD1  PD2  PD3  PD4  PD5  PD6  PD7
//                       D15  D16  D17                           D18  D19  D20  D21  D22  D23  D24  D25
//
//
//

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#include <avr/pgmspace.h>


#define NUM_DIGITAL_PINS 53
#define NUM_ANALOG_INPUTS 8
#define analogInputToDigitalPin(p) ((p < 8) ? (p) + 45 : -1)
#define digitalPinHasPWM(p) (((p) >= 3 && (p) <= 5) || ((p) >= 12 && (p) <= 15))
#define digitalPinToInterrupt(p) (((p) >= 4 && (p) <= 7) ? (p) : ((p) >= 18 && (p) <= 21) ? (p) - 18 : NOT_AN_INTERRUPT)

static const uint8_t SS = 8;
static const uint8_t SCK = 9;
static const uint8_t MOSI = 10;
static const uint8_t MISO = 11;

#define LED_BUILTIN 13

static const uint8_t SDA = 18;
static const uint8_t SCL = 19;

static const uint8_t A0 = 45;
static const uint8_t A1 = 46;
static const uint8_t A2 = 47;
static const uint8_t A3 = 48;
static const uint8_t A4 = 49;
static const uint8_t A5 = 50;
static const uint8_t A6 = 51;
static const uint8_t A7 = 52;



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
  PE, //0
  PE, //1
  PE, //2
  PE, //3
  PE, //4
  PE, //5
  PE, //6
  PE, //7

  PB, //8
  PB, //9
  PB, //10
  PB, //11
  PB, //12
  PB, //13
  PB, //14
  PB, //15

  PG, //16
  PG, //17

  PD, //18
  PD, //19
  PD, //20
  PD, //21
  PD, //22
  PD, //23
  PD, //24
  PD, //25

  PG, //26
  PG, //27

  PC, //28
  PC, //29
  PC, //30
  PC, //31
  PC, //32
  PC, //33
  PC, //34
  PC, //35

  PG, //36

  PA, //37
  PA, //38
  PA, //39
  PA, //40
  PA, //41
  PA, //42
  PA, //43
  PA, //44

  PF, //45
  PF, //46
  PF, //47
  PF, //48
  PF, //49
  PF, //50
  PF, //51
  PF, //52
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

  _BV(3), //16
  _BV(4), //17

  _BV(0), //18
  _BV(1), //19
  _BV(2), //20
  _BV(3), //21
  _BV(4), //22
  _BV(5), //23
  _BV(6), //24
  _BV(7), //25

  _BV(0), //26
  _BV(1), //27

  _BV(0), //28
  _BV(1), //29
  _BV(2), //30
  _BV(3), //31
  _BV(4), //32
  _BV(5), //33
  _BV(6), //34
  _BV(7), //35

  _BV(2), //36

  _BV(7), //37
  _BV(6), //38
  _BV(5), //39
  _BV(4), //40
  _BV(3), //41
  _BV(2), //42
  _BV(1), //43
  _BV(0), //44

  _BV(0), //45
  _BV(1), //46
  _BV(2), //47
  _BV(3), //48
  _BV(4), //49
  _BV(5), //50
  _BV(6), //51
  _BV(7), //52
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  TIMER3A,  //3
  TIMER3B,  //4
  TIMER3C,  //5
  NOT_ON_TIMER, //6
  NOT_ON_TIMER, //7

  NOT_ON_TIMER, //8
  NOT_ON_TIMER, //9
  NOT_ON_TIMER, //10
  NOT_ON_TIMER, //11
  TIMER0, //12
  TIMER1A,  //13
  TIMER1B,  //14
  TIMER1C,  //15

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

  NOT_ON_TIMER, //28
  NOT_ON_TIMER, //29
  NOT_ON_TIMER, //30
  NOT_ON_TIMER, //31
  NOT_ON_TIMER, //32
  NOT_ON_TIMER, //33
  NOT_ON_TIMER, //34
  NOT_ON_TIMER, //35

  NOT_ON_TIMER, //36

  NOT_ON_TIMER, //37
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

#endif  //ARDUINO_MAIN
#endif  //Pins_Arduino_h
