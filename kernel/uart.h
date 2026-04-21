/* uart.h - UART Driver interface for 16550 
 * part of osdev kernel project
 * Created: 14-04-2026
 */

#ifndef UART_H
#define UART_H

#include <stdint.h>

/* Initialise the UART to baud rate 115200 baud, 8N1 and FIFO enabled */
void uart_init(void);

/* Transmit a character when THR empty flag is set in LSR*/
void uart_putc(char c);

/* Transmit a string */
void uart_puts(const char *s);

/* Read in a character after data ready flag is set in LSR
 * Return the char or -1 if error detected */
int uart_getc(void);

/* takes in a number and displays it in hex format*/
void uart_puthex(uint64_t num);
#endif
