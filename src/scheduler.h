#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "primitives.h"
#include "riscv/tasks.h"

#define MAX_NTASKS 5
#define WORD_SIZE 4
#define TASK_STACK_SIZE (256 * WORD_SIZE)

typedef struct {
    task_context context;
    void (*task_func)();
} task;

uint32 start_task(void (*task_func)());
uint32 terminate_task(uint32 taskid);
void start_scheduler();

#endif
