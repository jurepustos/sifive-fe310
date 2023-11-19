.section .init
.align 2
.globl _start
_start:
    la sp, stack_top
    call main
spin:
    j spin



