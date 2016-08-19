// MOSI, MISO, and SCK pin definitions for all standard ATmega microcontrollers
#ifndef SPI_PINS_H
#define SPI_PINS_H

#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega64A__) || defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__) || \
defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || \
defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__) || \
defined(__AVR_ATmega165__) || defined(__AVR_ATmega165A__) || defined(__AVR_ATmega165P__) || defined(__AVR_ATmega165PA__) || defined(__AVR_ATmega325__) ||defined(__AVR_ATmega325A__) || defined(__AVR_ATmega325P__) || defined(__AVR_ATmega325PA__) || defined(__AVR_ATmega645__) || defined(__AVR_ATmega645A__) || defined(__AVR_ATmega645P__) || \
defined(__AVR_ATmega3250__) || defined(__AVR_ATmega3250A__) || defined(__AVR_ATmega3250P__) || defined(__AVR_ATmega3250PA__) || defined(__AVR_ATmega6450__) || defined(__AVR_ATmega6450A__) || defined(__AVR_ATmega6450P__) || \
defined(__AVR_ATmega169__) || defined(__AVR_ATmega169A__) || defined(__AVR_ATmega169P__) || defined(__AVR_ATmega169PA__) || defined(__AVR_ATmega329__) || defined(__AVR_ATmega329A__) || defined(__AVR_ATmega329P__) || defined(__AVR_ATmega329PA__) || defined(__AVR_ATmega3290__) || defined(__AVR_ATmega3290A__) || defined(__AVR_ATmega3290P__)  || defined(__AVR_ATmega3290PA__) || defined(__AVR_ATmega649__) || defined(__AVR_ATmega649A__) || defined(__AVR_ATmega649P__) || defined(__AVR_ATmega6490__) || defined(__AVR_ATmega6490A__) || defined(__AVR_ATmega6490P__) || \
defined(__AVR_ATmega8U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32U6__) || \
defined(__AVR_AT90CAN32__ ) || defined(__AVR_AT90CAN64__ ) || defined(__AVR_AT90CAN128__ ) || \
defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB647__) || defined(__AVR_AT90USB1286__) || defined(__AVR_AT90USB1287__)
#define	DDR_DI	_SFR_IO_ADDR(DDRB), 2	//MMC DI MOSI pin (DDR, PORT)
#define	PORT_DI	_SFR_IO_ADDR(PORTB), 2

#define	PIN_DO	_SFR_IO_ADDR(PINB), 3	//MMC DO MISO pin (PIN, PORT)
#define	PORT_DO	_SFR_IO_ADDR(PORTB), 3

#define	DDR_CK	_SFR_IO_ADDR(DDRB), 1	//MMC SCK pin (DDR, PORT)
#define	PORT_CK	_SFR_IO_ADDR(PORTB), 1


#elif defined(__AVR_ATmega8__) || defined(__AVR_ATmega8A__) || defined(__AVR_ATmega48__) || defined(__AVR_ATmega48A__) || defined(__AVR_ATmega48P__) || defined(__AVR_ATmega48PA__) || defined(__AVR_ATmega48PB__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega88A__) || defined(__AVR_ATmega88P__) || defined(__AVR_ATmega88PA__) || defined(__AVR_ATmega88PB__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168A__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega168PA__) || defined(__AVR_ATmega168PB__) ||defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328PB__)
#define	DDR_DI	_SFR_IO_ADDR(DDRB), 3
#define	PORT_DI	_SFR_IO_ADDR(PORTB), 3

#define	PIN_DO	_SFR_IO_ADDR(PINB), 4
#define	PORT_DO	_SFR_IO_ADDR(PORTB), 4

#define	DDR_CK	_SFR_IO_ADDR(DDRB), 5
#define	PORT_CK	_SFR_IO_ADDR(PORTB), 5


#elif defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__) || defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__) || \
defined(__AVR_ATmega161__) || defined(__AVR_ATmega162__) || defined(__AVR_ATmega163__) || \
defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega164PA__) || defined(__AVR_ATmega323__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324P__)  || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega324PB__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || \
defined(__AVR_ATmega8515__) || defined(__AVR_ATmega8535__)
#define	DDR_DI	_SFR_IO_ADDR(DDRB), 5
#define	PORT_DI	_SFR_IO_ADDR(PORTB), 5

#define	PIN_DO	_SFR_IO_ADDR(PINB), 6
#define	PORT_DO	_SFR_IO_ADDR(PORTB), 6

#define	DDR_CK	_SFR_IO_ADDR(DDRB), 7
#define	PORT_CK	_SFR_IO_ADDR(PORTB), 7


#elif defined(__AVR_ATmega16M1__) ||  defined(__AVR_ATmega32M1__) || defined(__AVR_ATmega64M1__) || defined(__AVR_ATmega32C1__) || defined(__AVR_ATmega64C1__) || \
defined(__AVR_AT90PWM1__) || defined(__AVR_AT90PWM2__) || defined(__AVR_AT90PWM2B__) || defined(__AVR_AT90PWM3__) || defined(__AVR_AT90PWM3B__) || defined(__AVR_AT90PWM216__) || defined(__AVR_AT90PWM316__)
#define	DDR_DI	_SFR_IO_ADDR(DDRB), 1
#define	PORT_DI	_SFR_IO_ADDR(PORTB), 1

#define	PIN_DO	_SFR_IO_ADDR(PINB), 0
#define	PORT_DO	_SFR_IO_ADDR(PORTB), 0

#define	DDR_CK	_SFR_IO_ADDR(DDRB), 7
#define	PORT_CK	_SFR_IO_ADDR(PORTB), 7


#elif defined(__AVR_AT90PWM81__) || defined(__AVR_AT90PWM161__)
#define	DDR_DI	_SFR_IO_ADDR(DDRB), 4
#define	PORT_DI	_SFR_IO_ADDR(PORTB), 4

#define	PIN_DO	_SFR_IO_ADDR(PINB), 6
#define	PORT_DO	_SFR_IO_ADDR(PORTB), 6

#define	DDR_CK	_SFR_IO_ADDR(DDRB), 5
#define	PORT_CK	_SFR_IO_ADDR(PORTB), 5


#else
#error SPI pins not defined for your processor. You must modify spi_pins.h
#endif

#endif	//SPI_PINS_H
