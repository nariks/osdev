/* fdt.c FDT parser implementation
 * part of osdev kernel project
 * Created 18-04-2026 */


#include "fdt.h"

#define LOBYTE_MASK 0xFF
#define MAX_BYTE_32 4
#define MAX_BYTE_64 8
#define NUM_BITS 8

uint32_t fdt32_to_cpu( uint32_t addr32) {

    uint32_t byte[MAX_BYTE_32];
    uint32_t swapped_addr = 0;
    
    for (int i = 0; i < MAX_BYTE_32; i++) {
        byte[i] = (addr32 >> (NUM_BITS * i)) & LOBYTE_MASK;
        swapped_addr |= byte[i] << ((MAX_BYTE_32 - (i+1)) * NUM_BITS);
    }

    return swapped_addr;
}

uint64_t fdt64_to_cpu( uint64_t addr64) {

    uint64_t byte[MAX_BYTE_64];
    uint64_t swapped_addr = 0;
    
    for (int i = 0; i < MAX_BYTE_64; i++) {
        byte[i] = (addr64 >> (NUM_BITS * i)) & LOBYTE_MASK;
        swapped_addr |= byte[i] << ((MAX_BYTE_64 - (i+1)) * NUM_BITS);
    }

    return swapped_addr;
}

