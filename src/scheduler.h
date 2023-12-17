#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "primitives.h"

#define MAX_NTASKS 5
#define TASK_STACK_SIZE 256

#define WORD_SIZE 4
#define CONTEXT_SIZE (32*WORD_SIZE)

struct task_context {
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
    uint32 unused0;
    uint32 unused1;
};

struct task {
    void (*task_func)();
    struct task_context context;
};



#endif
