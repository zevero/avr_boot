/**********************************************************/
/* board-arduino.h                                        */
/* Copyright (c) 2010 by thomas seiler                    */
/* -------------------------------------------------------*/
/*                                                        */
/* This program is free software; you can redistribute it */
/* and/or modify it under the terms of the GNU General    */
/* Public License as published by the Free Software       */
/* Foundation; either version 2 of the License, or        */
/* (at your option) any later version.                    */
/*                                                        */
/* This program is distributed in the hope that it will   */
/* be useful, but WITHOUT ANY WARRANTY; without even the  */
/* implied warranty of MERCHANTABILITY or FITNESS FOR A   */
/* PARTICULAR PURPOSE.  See the GNU General Public        */
/* License for more details.                              */
/*                                                        */
/* You should have received a copy of the GNU General     */
/* Public License along with this program; if not, write  */
/* to the Free Software Foundation, Inc.,                 */
/* 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA */
/*                                                        */
/* Licence can be viewed at                               */
/* http://www.fsf.org/licenses/gpl.txt                    */
/**********************************************************/


#ifndef _board_h_
#define _board_h_

/* define BAUD_RATE
 * This is the baud rate for the serial port.
 * The original Makefile seemed to use 19200 by default, and
 * 57600 if the target was a atmega328p or atmega1280
 */
#if   defined(__AVR_ATmega328P__) || defined(__AVR_ATmega1280__)
 #define BAUD_RATE 57600
 #if F_CPU <= 8000000L
  #define DOUBLE_SPEED
 #endif
#else
 #define BAUD_RATE 19200
#endif


/* define MAX_TIME_COUNT
 * This is the maximum amount of time that the bootloader waits for
 * serial activity before launching the main_app.
 * The original Makefile seemed to use  F_CPU>>4 in all cases, except for
 * ng and lillypad, where F_CPU>>1 was used. (which is longer!)
 * I think using F_CPU>>4 for all board is ok for this generic arduino header.
 */
#define MAX_TIME_COUNT F_CPU>>4

/* LED
 * This will be used to blink a LED during flashing
 *
 */

#define LED_PORT
#define LED_PIN

#endif
