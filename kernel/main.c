#include <stdint.h>
#include "uart.h"
#include "fdt.h"

uint64_t fdt_addr;

void kernel_main(void) {
    
    uart_init();

    if (validate_fdt(fdt_addr))
        uart_puts("\nValid FDT\n\n");
    else {
        uart_puts("Invalid FDT\n");
        while (1) {}                    // hang state on invalid fdt_addr
    }

    fdt_header *fd = (fdt_header *)fdt_addr;
    uint32_t struct_offset = fdt32_to_cpu(fd->off_dt_struct);
    uint32_t str_offset = fdt32_to_cpu(fd->off_dt_strings);
    uint32_t str_end = fdt32_to_cpu(fd->size_dt_strings);
    uint32_t struct_end = fdt32_to_cpu(fd->size_dt_struct);
    uint32_t *st_addr = (uint32_t *)(fdt_addr + struct_offset);
    uint8_t *str = (uint8_t *)(fdt_addr + str_offset ) ;
    
    uart_puts("Struct Offset -\t");
    uart_puthex32(struct_offset);
    uart_putc('\n');
    uart_puts("String Offset -\t");
    uart_puthex32(str_offset);
    uart_putc('\n');
    
    uart_puts("Struct size -\t");
    uart_puthex32(struct_end);
    uart_putc('\n');
    uart_puts("String size -\t");
    uart_puthex32(str_end);
    uart_putc('\n');

    uart_puts("----STRINGS----\n");
    
    while (str <=  (uint8_t *)(fdt_addr + str_offset + str_end)) {
        while(*str != '\0') {
            uart_putc(*str);
            str++;
        }
        str++;
        uart_putc('\n');
    }
    uart_putc('\n');

    /*for (uint32_t i = 0; i<= 16; i++) {
        uart_puthex64((uint64_t)(st_addr + i));
        uart_putc('-');
        uart_puthex32(fdt32_to_cpu(*(st_addr + i)));
        uart_putc('\n');
    }

    while(1) {
        int input = uart_getc();
        if (input == '\r' || input == '\n')
            uart_putc('\n');
        else
            uart_putc((char)input); 
    }*/
}

