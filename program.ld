OUTPUT_ARCH( "riscv" )
OUTPUT_FORMAT( "elf32-littleriscv" )
ENTRY( _start )

MEMORY {
    ram (arw!xi): ORIGIN = 0x80000000, LENGTH = 0x4000
    rom (irw!wa): ORIGIN = 0x20010000, LENGTH = 0x6a120
}

SECTIONS { 
    .text : { *(.init) *(.text) } > rom
    .rodata : { *(.rodata) } > rom

    .data : { *(.data) } > ram
    .sdata : { *(.sdata) } > ram
    .debug : { *(.debug) } > ram
    .stack : {
        . += 0x1000;
        stack_top = .;
    } > ram

    _end = .;
}
