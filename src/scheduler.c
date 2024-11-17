#include "scheduler.h"
#include "user_envcalls.h"
#include "kernel_envcalls.h"
#include "primitives.h"
#include "riscv/clint.h"
#include "riscv/csr.h"
#include "riscv/interrupts.h"
#include "riscv/tasks.h"

static task tasks[MAX_NTASKS];
static uint8 task_stacks[MAX_NTASKS][TASK_STACK_SIZE];
static uint8 current_task = 0;

void spin() {
    while (true) {
    }
}

static void finish_task() { env_terminate_task(current_task); }

void init_scheduler() {
    for (int i = 0; i < MAX_NTASKS; i++) {
        start_task(&spin);
    }
}

inline uint32 setup_task(uint32 taskid, void (*task_func)()) {
    if (taskid >= MAX_NTASKS)
        return 1;

    // set the first trapframe at the top of this task's stack
    trapframe_t* initial_trapframe =
        (trapframe_t*)&task_stacks[taskid + 1] - sizeof(trapframe_t);
    // set the registers when initially switching to this task
    initial_trapframe->ra = (uint32)&finish_task;
    initial_trapframe->mepc = (uint32)task_func;
    initial_trapframe->mstatus = MSTATUS_MIE;

    tasks[taskid].task_func = task_func;
    // stack starts at the top of the trapframe and ends at its bottom
    // it grows downwards during execution
    tasks[taskid].context.sp = (uint32)&initial_trapframe;
    tasks[taskid].context.ra = (uint32)&finish_task;

    return 0;
}

void start_task(void (*task_func)()) {
    int taskid = 0;
    while (taskid < MAX_NTASKS && tasks[taskid].task_func != &spin) {
        taskid++;
    }

    setup_task(taskid, task_func);
}

void start_scheduler() {}

uint32 kernel_terminate_task(uint32 taskid) {
    return setup_task(taskid, &spin);
}

uint32 env_terminate_task(uint32 taskid) {
    return envcall0(ENV_TERMINATE_TASK);
}
