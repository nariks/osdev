#include "uart.h"

void kernel_main(void) {
    
    uart_init();
    
    while(1) {
        int input = uart_getc();
        if (input == '\r' || input == '\n')
            uart_putc('\n');
        else
            uart_putc((char)input); 
    }
}

