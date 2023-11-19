OUTPUT_ARCH( "riscv" )
OUTPUT_FORMAT( "elf32-littleriscv" )
ENTRY( _start )

MEMORY {
    itim (airwx): ORIGIN = 0x8000000, LENGTH = 0x2000
    ram (arw!xi): ORIGIN = 0x80000000, LENGTH = 0x4000
    /* LENGTH = 0x1FF0000 for all memory */
    rom (irw!wa): ORIGIN = 0x20010000, LENGTH = 0x6a120
}

SECTIONS { 
    . = 0x20010000;
    .text : { *(.init) *(.text) }
    .rodata : { *(.rodata) }

    . = 0x80000000;
    .data : { *(.data) }
    .sdata : { *(.sdata) }
    .debug : { *(.debug) }

    . += 0x1000;
    stack_top = .;
    _end = .;
}
