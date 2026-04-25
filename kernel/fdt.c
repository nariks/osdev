/* fdt.c FDT parser implementation
 * part of osdev kernel project
 * Created 18-04-2026 */

#include "fdt.h"
#include <limits.h>

#define LOBYTE_MASK 0xFF
#define BYTES_PER_U32 4
#define BYTES_PER_U64 8

uint32_t fdt32_to_cpu(uint32_t value) {
    uint32_t nibbles[BYTES_PER_U32];
    uint32_t swapped_addr = 0;
   
    for (int i = 0; i < BYTES_PER_U32; i++) {
        nibbles[i] = (value >> (CHAR_BIT * i)) & LOBYTE_MASK;
        swapped_addr |= nibbles[i] << ((BYTES_PER_U32 - (i+1)) * CHAR_BIT);
    }

    return swapped_addr; }

uint64_t fdt64_to_cpu(uint64_t value) {
    uint64_t octets[BYTES_PER_U64];
    uint64_t swapped_addr = 0;
    
    for (int i = 0; i < BYTES_PER_U64; i++) {
        octets[i] = (value >> (CHAR_BIT * i)) & LOBYTE_MASK;
        swapped_addr |= octets[i] << ((BYTES_PER_U64 - (i+1)) * CHAR_BIT);
    }

    return swapped_addr;
}

int check_fdt_magic(const uintptr_t fdt_address) {
    fdt_header *fdt_hdr = (fdt_header *)fdt_address;
    return (fdt32_to_cpu(fdt_hdr->magic) == 0xD00DFEED);
}

