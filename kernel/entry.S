.section .text.entry
.global _start

_start:
    la sp, _stack_top           #setup stack pointer

    la t0, _bss_start           #to = start of bss
    la t1, _bss_end             #t1 = end of bss

loop:
    sd zero, 0(t0)              #zero 8 bytes at curr addr.
    addi t0, t0, 8              #inc curr addr by 8
    blt t0, t1, loop            #loop if t0 < t1    

    call kernel_main            #jump to C kernel

hang:
    j hang                      #halt if kernel_main returns
