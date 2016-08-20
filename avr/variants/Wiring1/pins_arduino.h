// MEGACORE - ATmega64/128 pin mapping
// Created by MCUdude
// https://github.com/MCUdude/MegaCore
//
// 	ARD.  	 AVR
// 	PINS  	 PINS
//  	|>        |  		       	A0   A1   A2   A3   A4   A5   A6   A7 
//  	|>	  |		        D45  D46  D47  D48  D49  D50  D51  D52		  D44  D43  D42
//  	|	  | >	 AVC  GND  ARE  PF0  PF1  PF2  PF3  PF4  PF5  PF6  PF7  GND  VCC  PA0  PA1  PA2
//  	V	  V	  -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
//		 PEN	|									       | PA3	D41
//	D0	 PE0	|									       | PA4	D40
//	D1	 PE1	|									       | PA5	D39
//	D2	 PE2	|									       | PA6	D38
//	D3	 PE3	|									       | PA7	D37
//	D4	 PE4	|									       | PG2	D36
//	D5	 PE5	|									       | PC7	D35
//	D6	 PE6	|									       | PC6	D34
//	D7	 PE7	|									       | PC5	D33
//	D8	 PB0	|									       | PC4	D32
//	D9	 PB1	|									       | PC3	D31
//	D10	 PB2	|									       | PC2	D30
//	D11	 PB3	|									       | PC1	D29
//	D12	 PB4	|									       | PC0	D28
//	D13	 PB5	|									       | PG1	D27 
//	D14	 PB6	|									       | PG0	D26 
//		  	  -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
//		 	 PB7  PG3  PG4  RST  VCC  GND  XT2  XT1  PD0  PD1  PD2  PD3  PD4  PD5  PD6  PD7
//			 D15  D16  D17  			 D18  D19  D20  D21  D22  D23  D24  D25
//
//
//

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#include <avr/pgmspace.h>


#define NUM_DIGITAL_PINS            53
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p) ((p < 8) ? (p) + 45 : -1)
#define digitalPinHasPWM(p)        (((p) >= 3 && (p) <= 5) || ((p) >= 12 && (p) <= 15))
#define digitalPinToInterrupt(p)   (((p) >= 4 && (p) <= 7) ? (p) : ((p) >= 18 && (p) <= 21) ? (p) - 18 : NOT_AN_INTERRUPT)

static const uint8_t SS   = 8;
static const uint8_t SCK  = 9;
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
	PE, // PE0 ** D0 ** RX0	
	PE, // PE1 ** D1 ** TX0	
	PE, // PE2 ** D2
	PE, // PE3 ** D3 ** PWM
	PE, // PE4 ** D4 ** PWM	
	PE, // PE5 ** D5 ** PWM
	PE, // PE6 ** D6 
	PE, // PE7 ** D7
	
	PB, // PB0 ** D8 ** SS	
	PB, // PB1 ** D9 ** SCK
	PB, // PB2 ** D10 ** MOSI	
	PB, // PB3 ** D11 ** MISO	
	PB, // PB4 ** D12 ** PWM
	PB, // PB5 ** D13 ** PWM
	PB, // PB6 ** D14 ** PWM	
	PB, // PB7 ** D15 ** PWM	
	
	PG, // PG3 ** D16
	PG, // PG4 ** D17
	
	PD, // PD0 ** D18 ** SCL	
	PD, // PD1 ** D19 ** SDA	
	PD, // PD2 ** D20 ** RX1
	PD, // PD3 ** D21 ** TX1	
	PD, // PD4 ** D22 
	PD, // PD5 ** D23	
	PD, // PD6 ** D24
	PD, // PD7 ** D25
	
	PG, // PG0 ** D26
	PG, // PG1 ** D27
	
	PC, // PC0 ** D28
	PC, // PC1 ** D29
	PC, // PC2 ** D30
	PC, // PC3 ** D31	
	PC, // PC4 ** D32	
	PC, // PC5 ** D33
	PC, // PC6 ** D34
	PC, // PC7 ** D35
	
	PG, // PG2 ** D36
	
	PA, // PA7 ** D37	
	PA, // PA6 ** D38
	PA, // PA5 ** D39	
	PA, // PA4 ** D40
	PA, // PA3 ** D41
	PA, // PA2 ** D42
	PA, // PA1 ** D43
	PA, // PA0 ** D44
	
	PF, // PF0 ** D45 ** A0	
	PF, // PF1 ** D46 ** A1	
	PF, // PF2 ** D47 ** A2	
	PF, // PF3 ** D48 ** A3	
	PF, // PF4 ** D49 ** A4	
	PF, // PF5 ** D50 ** A5	
	PF, // PF6 ** D51 ** A6	
	PF, // PF7 ** D52 ** A7	
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), // PE0 ** D0 ** RX0	
	_BV(1), // PE1 ** D1 ** TX0	
	_BV(2), // PE2 ** D2
	_BV(3), // PE3 ** D3 ** PWM
	_BV(4), // PE4 ** D4 ** PWM	
	_BV(5), // PE5 ** D5 ** PWM
	_BV(6), // PE6 ** D6 
	_BV(7), // PE7 ** D7
	
	_BV(0), // PB0 ** D8 ** SS	
	_BV(1), // PB1 ** D9 ** SCK
	_BV(2), // PB2 ** D10 ** MOSI	
	_BV(3), // PB3 ** D11 ** MISO	
	_BV(4), // PB4 ** D12 ** PWM
	_BV(5), // PB5 ** D13 ** PWM
	_BV(6), // PB6 ** D14 ** PWM	
	_BV(7), // PB7 ** D15 ** PWM	
	
	_BV(3), // PG3 ** D16
	_BV(4), // PG4 ** D17
	
	_BV(0), // PD0 ** D18 ** SCL	
	_BV(1), // PD1 ** D19 ** SDA	
	_BV(2), // PD2 ** D20 ** RX1
	_BV(3), // PD3 ** D21 ** TX1	
	_BV(4), // PD4 ** D22 
	_BV(5), // PD5 ** D23	
	_BV(6), // PD6 ** D24
	_BV(7), // PD7 ** D25
	
	_BV(0), // PG0 ** D26
	_BV(1), // PG1 ** D27
	
	_BV(0), // PC0 ** D28
	_BV(1), // PC1 ** D29
	_BV(2), // PC2 ** D30
	_BV(3), // PC3 ** D31	
	_BV(4), // PC4 ** D32	
	_BV(5), // PC5 ** D33
	_BV(6), // PC6 ** D34
	_BV(7), // PC7 ** D35
	
	_BV(2), // PG2 ** D36
	
	_BV(7), // PA7 ** D37	
	_BV(6), // PA6 ** D38
	_BV(5), // PA5 ** D39	
	_BV(4), // PA4 ** D40
	_BV(3), // PA3 ** D41
	_BV(2), // PA2 ** D42
	_BV(1), // PA1 ** D43
	_BV(0), // PA0 ** D44
	
	_BV(0), // PF0 ** D45 ** A0	
	_BV(1), // PF1 ** D46 ** A1	
	_BV(2), // PF2 ** D47 ** A2	
	_BV(3), // PF3 ** D48 ** A3	
	_BV(4), // PF4 ** D49 ** A4	
	_BV(5), // PF5 ** D50 ** A5	
	_BV(6), // PF6 ** D51 ** A6	
	_BV(7), // PF7 ** D52 ** A7	
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, // PE0 ** D0 ** RX0	
	NOT_ON_TIMER, // PE1 ** D1 ** TX0	
	NOT_ON_TIMER, // PE2 ** D2
	TIMER3A, 	  // PE3 ** D3 ** PWM
	TIMER3B, 	  // PE4 ** D4 ** PWM	
	TIMER3C, 	  // PE5 ** D5 ** PWM
	NOT_ON_TIMER, // PE6 ** D6 
	NOT_ON_TIMER, // PE7 ** D7
	
	NOT_ON_TIMER, // PB0 ** D8 ** SS	
	NOT_ON_TIMER, // PB1 ** D9 ** SCK
	NOT_ON_TIMER, // PB2 ** D10 ** MOSI	
	NOT_ON_TIMER, // PB3 ** D11 ** MISO	
	TIMER0, 	  // PB4 ** D12 ** PWM
	TIMER1A, 	  // PB5 ** D13 ** PWM
	TIMER1B, 	  // PB6 ** D14 ** PWM	
	TIMER1C, 	  // PB7 ** D15 ** PWM	
	
	NOT_ON_TIMER, // PG3 ** D16
	NOT_ON_TIMER, // PG4 ** D17
	
	NOT_ON_TIMER, // PD0 ** D18 ** SCL	
	NOT_ON_TIMER, // PD1 ** D19 ** SDA	
	NOT_ON_TIMER, // PD2 ** D20 ** RX1
	NOT_ON_TIMER, // PD3 ** D21 ** TX1	
	NOT_ON_TIMER, // PD4 ** D22 
	NOT_ON_TIMER, // PD5 ** D23	
	NOT_ON_TIMER, // PD6 ** D24
	NOT_ON_TIMER, // PD7 ** D25
	
	NOT_ON_TIMER, // PG0 ** D26
	NOT_ON_TIMER, // PG1 ** D27
	
	NOT_ON_TIMER, // PC0 ** D28
	NOT_ON_TIMER, // PC1 ** D29
	NOT_ON_TIMER, // PC2 ** D30
	NOT_ON_TIMER, // PC3 ** D31	
	NOT_ON_TIMER, // PC4 ** D32	
	NOT_ON_TIMER, // PC5 ** D33
	NOT_ON_TIMER, // PC6 ** D34
	NOT_ON_TIMER, // PC7 ** D35
	
	NOT_ON_TIMER, // PG2 ** D36
	
	NOT_ON_TIMER, // PA7 ** D37	
	NOT_ON_TIMER, // PA6 ** D38
	NOT_ON_TIMER, // PA5 ** D39	
	NOT_ON_TIMER, // PA4 ** D40
	NOT_ON_TIMER, // PA3 ** D41
	NOT_ON_TIMER, // PA2 ** D42
	NOT_ON_TIMER, // PA1 ** D43
	NOT_ON_TIMER, // PA0 ** D44
	
	NOT_ON_TIMER, // PF0 ** D45 ** A0	
	NOT_ON_TIMER, // PF1 ** D46 ** A1	
	NOT_ON_TIMER, // PF2 ** D47 ** A2	
	NOT_ON_TIMER, // PF3 ** D48 ** A3	
	NOT_ON_TIMER, // PF4 ** D49 ** A4	
	NOT_ON_TIMER, // PF5 ** D50 ** A5	
	NOT_ON_TIMER, // PF6 ** D51 ** A6	
	NOT_ON_TIMER, // PF7 ** D52 ** A7	
};

#endif
#endif
