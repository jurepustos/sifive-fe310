OUTPUT_ARCH( "riscv" )
OUTPUT_FORMAT( "elf32-littleriscv" )
ENTRY( _start )

MEMORY {
    ram (arw!xi): ORIGIN = 0x80000000, LENGTH = 16K
    rom (irx!wa): ORIGIN = 0x20010000, LENGTH = 4M
}

SECTIONS { 
    .text : { 
        *(.init .text .text.*)
    } > rom

    .rodata : { 
        . = ALIGN(16);
        *(.srodata .srodata.*) 
        . = ALIGN(16);
        *(.rodata .rodata.*)  
    } > rom

    .data : { 
        . = ALIGN(16);
        *(.sdata .sdata.*)
        . = ALIGN(16);
        *(.data .data.*) 
    } > ram AT > rom

    .bss : {
        . = ALIGN(16);
        *(.sbss .sbss.*) 
        . = ALIGN(16);
        *(.bss .bss.*)  
    } > ram AT > rom

    .stack : {
        . = 16K;
        stack_top = .;
    } > ram

    PROVIDE(end = .);
}
