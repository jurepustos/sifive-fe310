#include "primitives.h"
#include "interrupts.h"
#include "tasks.h"
#include "riscv.h"

static task tasks[MAX_NTASKS];
static uint8 task_stacks[MAX_NTASKS][TASK_STACK_SIZE];
static uint8 current_task = -1;
static uint8 ntasks = 0;

void spin() {
    while (true) {}
}

task* create_task(void (*task_func)()) {
    tasks[ntasks] = {
        .task_func = task_func,
        .context = {
            .ra = &spin,
            .sp = &task_stacks[ntasks]
        },
        .trapframe = {
            .ra = &spin,
            .sp = &task_stasks[ntasks]
            .mepc = task_func,
            .mstatus = MSTATUS_MIE
        }
    };
    ntasks++;
}

void schedule_next_task() {

}

