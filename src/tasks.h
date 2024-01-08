#ifndef TASKS_H
#define TASKS_H

#include "primitives.h"
#include "riscv/interrupts.h"
#include "riscv/csr.h"

#define MAX_NTASKS 5
#define WORD_SIZE 4
#define TASK_STACK_SIZE (256*WORD_SIZE)


// used for kernel calls/software interrupts
typedef struct {
    uint32 ra;
    uint32 sp;
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
} task_context;

typedef struct {
    uint32 sp;
    task_context context;
    void (*task_func)();
} task;


__attribute__((always_inline)) static inline void save_context(task_context *context) {
    asm volatile (
        "sw ra,   0*4(%0) \n"
        "sw sp,   1*4(%0) \n"
        "sw s0,   2*4(%0) \n"
        "sw s1,   3*4(%0) \n"
        "sw s2,   4*4(%0) \n"
        "sw s3,   5*4(%0) \n"
        "sw s4,   6*4(%0) \n"
        "sw s5,   7*4(%0) \n"
        "sw s6,   8*4(%0) \n"
        "sw s7,   9*4(%0) \n"
        "sw s8,  10*4(%0) \n"
        "sw s9,  11*4(%0) \n"
        "sw s10, 12*4(%0) \n"
        "sw s11, 13*4(%0) \n"
        :: "r" (context)
    );
}

__attribute__((always_inline)) static inline void restore_context(task_context *context) {
    asm volatile (
        "lw ra,   0*4(%0) \n"
        "lw sp,   1*4(%0) \n"
        "lw s0,   2*4(%0) \n"
        "lw s1,   3*4(%0) \n"
        "lw s2,   4*4(%0) \n"
        "lw s3,   5*4(%0) \n"
        "lw s4,   6*4(%0) \n"
        "lw s5,   7*4(%0) \n"
        "lw s6,   8*4(%0) \n"
        "lw s7,   9*4(%0) \n"
        "lw s8,  10*4(%0) \n"
        "lw s9,  11*4(%0) \n"
        "lw s10, 12*4(%0) \n"
        "lw s11, 13*4(%0) \n"
        :: "r" (context)
    );
}


#endif
