/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2013 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows 
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include "mk20dn64.h"
#include <inttypes.h>

// uncomment to enable 9 bit formats
//#define SERIAL_9BIT_SUPPORT


#define SERIAL_7E1 0x02
#define SERIAL_7O1 0x03
#define SERIAL_8N1 0x00
#define SERIAL_8N2 0x04
#define SERIAL_8E1 0x06
#define SERIAL_8O1 0x07
#define SERIAL_7E1_RXINV 0x12
#define SERIAL_7O1_RXINV 0x13
#define SERIAL_8N1_RXINV 0x10
#define SERIAL_8N2_RXINV 0x14
#define SERIAL_8E1_RXINV 0x16
#define SERIAL_8O1_RXINV 0x17
#define SERIAL_7E1_TXINV 0x22
#define SERIAL_7O1_TXINV 0x23
#define SERIAL_8N1_TXINV 0x20
#define SERIAL_8N2_TXINV 0x24
#define SERIAL_8E1_TXINV 0x26
#define SERIAL_8O1_TXINV 0x27
#define SERIAL_7E1_RXINV_TXINV 0x32
#define SERIAL_7O1_RXINV_TXINV 0x33
#define SERIAL_8N1_RXINV_TXINV 0x30
#define SERIAL_8N2_RXINV_TXINV 0x34
#define SERIAL_8E1_RXINV_TXINV 0x36
#define SERIAL_8O1_RXINV_TXINV 0x37
#ifdef SERIAL_9BIT_SUPPORT
#define SERIAL_9N1 0x84
#define SERIAL_9E1 0x8E
#define SERIAL_9O1 0x8F
#define SERIAL_9N1_RXINV 0x94
#define SERIAL_9E1_RXINV 0x9E
#define SERIAL_9O1_RXINV 0x9F
#define SERIAL_9N1_TXINV 0xA4
#define SERIAL_9E1_TXINV 0xAE
#define SERIAL_9O1_TXINV 0xAF
#define SERIAL_9N1_RXINV_TXINV 0xB4
#define SERIAL_9E1_RXINV_TXINV 0xBE
#define SERIAL_9O1_RXINV_TXINV 0xBF
#endif
// bit0: parity, 0=even, 1=odd
// bit1: parity, 0=disable, 1=enable
// bit2: mode, 1=9bit, 0=8bit
// bit3: mode10: 1=10bit, 0=8bit
// bit4: rxinv, 0=normal, 1=inverted
// bit5: txinv, 0=normal, 1=inverted
// bit6: unused
// bit7: actual data goes into 9th bit


#define BAUD2DIV(baud)  (((F_CPU * 2) + ((baud) >> 1)) / (baud))
#define BAUD2DIV3(baud) (((F_BUS * 2) + ((baud) >> 1)) / (baud))

// C language implementation
//
#ifdef __cplusplus
extern "C" {
#endif
void serial_begin(uint32_t divisor);
void serial_format(uint32_t format);
void serial_end(void);
void serial_set_transmit_pin(uint8_t pin);
void serial_putchar(uint32_t c);
void serial_write(const void *buf, unsigned int count);
void serial_flush(void);
int serial_available(void);
int serial_getchar(void);
int serial_peek(void);
void serial_clear(void);
void serial_print(const char *p);
void serial_phex(uint32_t n);
void serial_phex16(uint32_t n);
void serial_phex32(uint32_t n);

void serial2_begin(uint32_t divisor);
void serial2_format(uint32_t format);
void serial2_end(void);
void serial2_set_transmit_pin(uint8_t pin);
void serial2_putchar(uint32_t c);
void serial2_write(const void *buf, unsigned int count);
void serial2_flush(void);
int serial2_available(void);
int serial2_getchar(void);
int serial2_peek(void);
void serial2_clear(void);
void serial2_print(const char *p);

#ifdef __cplusplus
}
#endif


#endif

