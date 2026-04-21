/* platform.h
 * kernel dev project
 * Date: 17-04-2026 */

#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef PLATFORM_VF2
    #define RAM_BASE    0x40000000
    #define RAM_SIZE    0x100000000
    #define KERNEL_BASE 0x40200000
    #define CLK_FREQ_HZ 24000000
    #define UART_DIV    13
#elif defined(PLATFORM_QEMU)
    #define RAM_BASE    0x80000000
    #define RAM_SIZE    0x10000000
    #define KERNEL_BASE 0x80200000
    #define CLK_FREQ_HZ 1843200
    #define UART_DIV    1
#else
    #error "No platform defined. Use PLATFORM=qemu or PLATFORM=VF2"
#endif

#define UART_BASE   0x10000000

#endif
