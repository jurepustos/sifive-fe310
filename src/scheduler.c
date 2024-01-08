#include "primitives.h"
#include "riscv/interrupts.h"
#include "tasks.h"
#include "riscv/csr.h"

static task tasks[MAX_NTASKS];
static uint8 task_stacks[MAX_NTASKS][TASK_STACK_SIZE];
static uint8 current_task = -1;
static uint8 ntasks = 0;

void spin() {
    while (true) {}
}

task* create_task(void (*task_func)()) {
    trapframe_t *initial_trapframe = (trapframe_t *) &task_stacks[ntasks+1] - sizeof(trapframe_t);
    initial_trapframe->ra = (uint32) &spin;
    initial_trapframe->mepc = (uint32) task_func;
    initial_trapframe->mstatus = MSTATUS_MIE;

    tasks[ntasks] = (task) {
        .task_func = task_func,
        .sp = (uint32) initial_trapframe,
        .context = {
            .ra = (uint32) &spin,
        },
    };
    ntasks++;

    return &tasks[ntasks-1];
}

void start_scheduler() {

}

void schedule_next_task() {

}

