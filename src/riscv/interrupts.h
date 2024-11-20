#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../primitives.h"

#define MSTATUS_MIE (1 << 3)    // machine-mode interrupt enable
#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software

// used for handling non-software interrupts and exception
typedef struct {
    uint32 mepc;
    uint32 mstatus;
    uint32 ra;
    uint32 sp;
    uint32 a0;
    uint32 a1;
    uint32 a2;
    uint32 a3;
    uint32 a4;
    uint32 a5;
    uint32 a6;
    uint32 a7;
    uint32 t0;
    uint32 t1;
    uint32 t2;
    uint32 t3;
    uint32 t4;
    uint32 t5;
    uint32 t6;
    uint32 s0;
    uint32 s1;
    uint32 s2;
    uint32 s3;
    uint32 s4;
    uint32 s5;
    uint32 s6;
    uint32 s7;
    uint32 s8;
    uint32 s9;
    uint32 s10;
    uint32 s11;
} trapframe_t;


void _vector_table();
void register_vector_table(void *vector_table);

void enable_interrupts();
void disable_interrupts();
int get_interrupts_enabled();

void enable_timer_interrupts();
void disable_timer_interrupts();

void enable_external_interrupts();
void disable_external_interrupts();

void enable_software_interrupts();
void disable_software_interrupts();

__attribute__((always_inline)) static inline void __save_trapframe() {
    asm volatile (
        "sw sp,   -28*4(sp)   \n"
        "addi sp, sp, -31*4 \n"
        "sw ra,   2*4(sp)   \n"
        "sw a0,   4*4(sp)   \n"
        "sw a1,   5*4(sp)   \n"
        "sw a2,   6*4(sp)   \n"
        "sw a3,   7*4(sp)   \n"
        "sw a4,   8*4(sp)   \n"
        "sw a5,   9*4(sp)   \n"
        "sw a6,  10*4(sp)   \n"
        "sw a7,  11*4(sp)   \n"
        "sw t0,  12*4(sp)   \n"
        "sw t1,  13*4(sp)   \n"
        "sw t2,  14*4(sp)   \n"
        "sw t3,  15*4(sp)   \n"
        "sw t4,  16*4(sp)   \n"
        "sw t5,  17*4(sp)   \n"
        "sw t6,  18*4(sp)   \n"
        "sw s0,  19*4(sp)   \n"
        "sw s1,  20*4(sp)   \n"
        "sw s2,  21*4(sp)   \n"
        "sw s3,  22*4(sp)   \n"
        "sw s4,  23*4(sp)   \n"
        "sw s5,  24*4(sp)   \n"
        "sw s6,  25*4(sp)   \n"
        "sw s7,  26*4(sp)   \n"
        "sw s8,  27*4(sp)   \n"
        "sw s9,  28*4(sp)   \n"
        "sw s10, 29*4(sp)   \n"
        "sw s11, 30*4(sp)   \n"
        "csrr t0, mepc      \n"
        "sw t0,   0*4(sp)   \n"
        "csrr t0, mstatus   \n"
        "sw t0,   1*4(sp)"
    );
}

__attribute__((always_inline)) static inline void __restore_trapframe() {
    asm volatile (
        "lw t0,   0*4(sp) \n"
        "csrw mepc, t0    \n"
        "lw t0,   1*4(sp) \n"
        "csrw mstatus, t0 \n"
        "lw ra,   2*4(sp) \n"
        "lw a0,   4*4(sp) \n"
        "lw a1,   5*4(sp) \n"
        "lw a2,   6*4(sp) \n"
        "lw a3,   7*4(sp) \n"
        "lw a4,   8*4(sp) \n"
        "lw a5,   9*4(sp) \n"
        "lw a6,  10*4(sp) \n"
        "lw a7,  11*4(sp) \n"
        "lw t0,  12*4(sp) \n"
        "lw t1,  13*4(sp) \n"
        "lw t2,  14*4(sp) \n"
        "lw t3,  15*4(sp) \n"
        "lw t4,  16*4(sp) \n"
        "lw t5,  17*4(sp) \n"
        "lw t6,  18*4(sp) \n"
        "lw s0,  19*4(sp) \n"
        "lw s1,  20*4(sp) \n"
        "lw s2,  21*4(sp) \n"
        "lw s3,  22*4(sp) \n"
        "lw s4,  23*4(sp) \n"
        "lw s5,  24*4(sp) \n"
        "lw s6,  25*4(sp) \n"
        "lw s7,  26*4(sp) \n"
        "lw s8,  27*4(sp) \n"
        "lw s9,  28*4(sp) \n"
        "lw s10, 29*4(sp) \n"
        "lw s11, 30*4(sp) \n"
        "lw sp,   3*4(sp) \n"
    );
}


#endif
