#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "primitives.h"
#include "riscv/tasks.h"

#define MAX_NTASKS 5
#define WORD_SIZE 4
#define TASK_STACK_SIZE (256*WORD_SIZE)


typedef struct {
    uint32 sp;
    task_context context;
    void (*task_func)();
} task;


void start_task(void (*task_func)());
void start_scheduler();
void next_task();


#endif
