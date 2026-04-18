/* uart.c - UART Driver implementation for 16550 
 * part of osdev kernel project
 * Created: 14-04-2026
 */

#include "uart.h"
#include "platform.h"

/*register offsets from base */
#define THR 0               // Transmit Holding Register, (wr, DLAB = 0)
#define RBR 0               // Receiver Buffer Register, (rd, DLAB = 0)
#define DLL 0               // Divisor Latch Low, (rd/wr, DLAB = 1)
#define IER 1               // Interrupt Enable Register, (r/w, DLAB = 0)
#define DLM 1               // Divisor Latch High, (r/w, DLAB = 1)
#define FCR 2               // FIFO Control Register (wr)
#define LCR 3               // Line Control Register
#define LSR 5               // Line Status Register

/* LSR bit masks */
#define LSR_TX_EMPTY   0x20
#define LSR_RX_READY    0x01
#define LSR_RX_ERRORS   0x0E

static volatile char *uart = (volatile char *) UART_BASE;

void uart_init(void) {
    
    uart[LCR] = 0x83;       //set DLAB = 1 and 8N1
    uart[DLL] = UART_BASE & 0xFF;      //set baud rate low byte DLL = 1
    uart[DLM] = (UART_BASE >> 8) & 0xFF;       //set baud rate high byte DLM = 0
    uart[LCR] = 0x03;       //set DLAB = 0
    uart[IER] = 0x00;       //disable all interrupts
    uart[FCR] = 0x07;       //enable and clearing both FIFO
}

void uart_putc(char c) {
    while ((uart[LSR] & LSR_TX_EMPTY) == 0) {} //wait for THR Empty
    uart[THR] = c;
}

void uart_puts(const char * s) {
    while (*s != '\0') {
        uart_putc(*s);
        s++;
    }
}

int uart_getc(void) {
    unsigned char lsr_status;
    
    while (((lsr_status = uart[LSR]) & 0x01) == 0) {} //wait till RBR ready

    if ((lsr_status & LSR_RX_ERRORS) == 0)
       return uart[RBR];
    else
       return -1; 
}
