.section .text

// interrupt handlers implemented in traps.c
.balign 64
.globl _vector_table
.type _vector_table, @function
_vector_table:
    jal exception_handler
    jal default_handler
    jal default_handler
    jal sw_handler
    jal default_handler
    jal default_handler
    jal default_handler
    jal timer_handler
    jal default_handler
    jal default_handler
    jal default_handler
    jal ext_handler
    jal default_handler
    jal default_handler
    jal default_handler


