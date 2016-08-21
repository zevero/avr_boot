# Arduino_Goldilocks_Variant

Variant files for Goldilocks AVR ATmega1284p Boards under Arduino IDE 1.6.x.
These files suppport the Goldilocks Analogue and the 2013 Goldilocks v1.1.

The URL for adding Goldilocks to the Arduino IDE Boards Manager is maintained
at the
[Unofficial List of 3rd Party Board Support URLs](https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls)

Arduino IDE Pin assignments below.

```
//                    ATMEL ATMEGA1284P on Goldilocks
//                    Actual implementation with VQFN
//
//                               +---\/---+
//            PCINT8 (D14) PB0  1|        |40  PA0 (A0 / D24) PCINT0
//            PCINT9 (D15) PB1  2|        |39  PA1 (A1 / D25) PCINT1
//      PCINT10/INT2 (D8 ) PB2  3|        |38  PA2 (A2 / D26) PCINT2
//      PCINT11/OC0A*(D9 ) PB3  4|        |37  PA3 (A3 / D27) PCINT3
//   PCINT12/0C0B/SS*(D10) PB4  5|        |36  PA4 (A4 / D28) PCINT4
//      PCINT13/MOSI (D11) PB5  6|        |35  PA5 (A5 / D29) PCINT5
// PCINT14/OC3A/MISO*(D12) PB6  7|        |34  PA6 (A6 / D30) PCINT6
//  PCINT15/OC3B/SCK*(D13) PB7  8|        |33  PA7 (A7 / D31) PCINT7
//                         RST  9|        |32  AREF
//                         VCC 10|        |31  GND
//                         GND 11|        |30  AVCC
//                       XTAL2 12|        |29  PC7 (D23) TOSC2/PCINT23
//                       XTAL1 13|        |28  PC6 (D22) TOSC1/PCINT22
//       PCINT24/RX0 (D0 ) PD0 14|        |27  PC5 (D21) TDI/PCINT21
//       PCINT25/TX0 (D1 ) PD1 15|        |26  PC4 (D20) TDO/PCINT20
//  PCINT26/INT0/RX1 (D2 ) PD2 16|        |25  PC3 (D19) TMS/PCINT19
//  PCINT27/INT1/TX1 (D3 ) PD3 17|        |24  PC2 (D18) TCK/PCINT18
//      PCINT28/OC1B*(D4 ) PD4 18|        |23  PC1 (D17) SDA/PCINT17
//      PCINT29/OC1A*(D5 ) PD5 19|        |22  PC0 (D16) SCL/PCINT16
//      PCINT30/OC2B*(D6 ) PD6 20|        |21  PD7 (D7 )*OC2A/PCINT31
//                               +--------+
// * = PWM capable pin
// TOSCn = RTC Crystal pinout
// TCK/TMS/TDO/TDI = JTAG pinout
```
Use the Arduino "wiring" protocol to upload files.

STK500v2 boot-loader including debug monitor to analyse interrupt, I/O, RAM, FLASH contents.
Enter !!! <CR> into Arduino IDE Serial Monitor (38400 8n1) before boot-loader times out to enter the debug monitor.

```
0=Zero addr (reset Dump Addresses)
?=CPU stats 
@=EEPROM test 
B=Blink LED 
E=Dump EEPROM 
F=Dump FLASH 
H=Help 
L=List I/O Ports 
Q=Quit 
R=Dump RAM 
V=show interrupt Vectors 
Y=Port blink
```

# Licence
```
Copyright (c) 2016 Phillip Stevens.  All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
```
