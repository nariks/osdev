/* fdt.h - Flattened Device Tree (FDT) parser interface
 * part of osdev kernel project
 * Created 18-04-2026 */

#ifndef FDT_H
#define FDT_H

#include <stdint.h>

typedef struct fdt_header {
    uint32_t magic;
    uint32_t totalsize;
    uint32_t off_dt_struct;
    uint32_t off_dt_strings;
    uint32_t off_mem_rsvmap;
    uint32_t version;
    uint32_t last_comp_version;
    uint32_t boot_cpuid_phys;
    uint32_t size_dt_strings;
    uint32_t size_dt_struct;
} fdt_header;

/*3 struct fdt_header {
  4     uint32_t magic;
  5     uint32_t struct_offset;
  6     uint32_t memory_offset;
  7 };  
  8 
  9 fdt_header *fdt_hdr = (fdt_header *)fdt_addr;
 10 fdt_hdr.magic = fdt32_to_cpu(*fdt_addr);
 11 fdt_hdr.struct_offset = 
*/




// converts FDT's 32 bit big endian to CPU's native little endian
uint32_t fdt32_to_cpu( uint32_t addr32);

// converts FDT's 64 bit big endian to CPU's native little endian:
uint64_t fdt64_to_cpu( uint64_t addr64);

int validate_fdt(uint64_t fdt_addr);
#endif

