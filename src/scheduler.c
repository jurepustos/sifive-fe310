#include "primitives.h"
#include "scheduler.h"
#include "riscv/interrupts.h"
#include "riscv/tasks.h"
#include "riscv/csr.h"
#include "riscv/clint.h"

static task tasks[MAX_NTASKS];
static uint8 task_stacks[MAX_NTASKS][TASK_STACK_SIZE];
static uint8 current_task = -1;
static uint8 ntasks = 0;

void spin() {
    while (true) {}
}

void start_task(void (*task_func)()) {
    // trapframe is located at the top of this task's stack
    trapframe_t *initial_trapframe = (trapframe_t *) &task_stacks[ntasks+1] - sizeof(trapframe_t);
    // set the registers correctly when initially
    // switching to this task
    initial_trapframe->ra = (uint32) &next_task;
    initial_trapframe->mepc = (uint32) task_func;
    initial_trapframe->mstatus = MSTATUS_MIE;

    tasks[ntasks] = (task) {
        .task_func = task_func,
        // stack starts at the bottom of the trapframe
        .sp = (uint32) initial_trapframe,
        .context = {
            // immediately schedule the next task upon this task's completion
            .ra = (uint32) &next_task,
        },
    };
    ntasks++;
}

void start_scheduler() {

}

void next_task() {

}

