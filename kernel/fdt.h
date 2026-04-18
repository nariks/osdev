/* fdt.h - Flattened Device Tree (FDT) parser interface
 * part of osdev kernel project
 * Created 18-04-2026 */

#ifndef FDT_H
#define FDT_H

#include <stdint.h>

// converts FDT's 32 bit big endian to CPU's native little endian
uint32_t fdt32_to_cpu( uint32_t addr32);

// converts FDT's 64 bit big endian to CPU's native little endian:
uint64_t fdt64_to_cpu( uint64_t addr64);
#endif

