#include <stdint.h>
#include "uart.h"
#include "fdt.h"

uint64_t fdt_addr;

void kernel_main(void) {
    
    uart_init();
    
    if (validate_fdt(fdt_addr))
        uart_puts("Valid FDT\n");

    uint32_t *magic_field = (uint32_t *)fdt_addr;
    uint32_t *struct_offset = (uint32_t *)fdt_addr + 0x2;
    
    uart_puthex(fdt32_to_cpu(*magic_field));
    uart_putc('\n');
    uart_puthex(fdt32_to_cpu(*struct_offset));

    /*for (uint32_t i = 0; i<= 16; i++) {
        uart_puthex(fdt32_to_cpu(*(magic_field + i)));
        uart_putc('\n');
    }*/

    *struct_offset = fdt32_to_cpu(*struct_offset);
    uint32_t *fdt_start_node = (uint32_t *)fdt_addr + (*struct_offset / 4);

    uart_putc('\n');
    uart_puthex(fdt32_to_cpu(*fdt_start_node));

    while(1) {
        int input = uart_getc();
        if (input == '\r' || input == '\n')
            uart_putc('\n');
        else
            uart_putc((char)input); 
    }
}

