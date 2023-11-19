.section text

.equ MSTATUS_MIE_MASK, 0x00000008 # bit 3

.align 2
.globl enable_global_interrupts
.type enable_global_interrupts, @function
enable_global_interrupts:
    # prologue
    addi sp, sp, -8
    sw ra, 4(sp)
    sw fp, 0(sp)
    addi fp, sp, 8

    # set the bit on mstatus
    li t0, MSTATUS_MIE_MASK
    csrs mstatus, t0


    # epilogue
    lw fp, 0(sp)
    lw ra, 4(sp)
    addi sp, sp, 8

    ret


.equ MIE_TIMER_MASK, 0x00000080 # bit 7
    

.align 2
.globl enable_timer_interrupts
.type enable_timer_interrupts, @function
enable_timer_interrupts:
    # prologue
    addi sp, sp, -8
    sw ra, 4(sp)
    sw fp, 0(sp)
    addi fp, sp, 8

    # set the bit on mstatus
    li t0, MIE_TIMER_MASK
    csrs mie, t0


    # epilogue
    lw fp, 0(sp)
    lw ra, 4(sp)
    addi sp, sp, 8

    ret

