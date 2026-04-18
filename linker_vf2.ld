OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
    ram (rwx) : ORIGIN = 0x40200000, LENGTH = 0xFFE00000
}

SECTIONS
{
    .text :
    {
        *(.text.entry)
        *(.text .text.*)
    } > ram

    .rodata :
    {
        *(.rodata .rodata.*)
    } > ram

    .data :
    {
        *(.data .data.*)
    } > ram

    .bss :
    {
        _bss_start = .;
        *(.bss .bss.*)
        *(COMMON)
        _bss_end = .;
    } > ram

    . = ALIGN(16);
    . = . + 0x10000;
    _stack_top = .;
}


