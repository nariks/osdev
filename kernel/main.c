#include <stdint.h>
#include "uart.h"

uint64_t fdt_addr;

void kernel_main(void) {
    
    uart_init();
    
    uart_puthex(fdt_addr);

    while(1) {
        int input = uart_getc();
        if (input == '\r' || input == '\n')
            uart_putc('\n');
        else
            uart_putc((char)input); 
    }
}

