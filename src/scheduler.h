#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "primitives.h"
#include "tasks.h"

task* create_task(void (*task_func)());
void schedule_next_task(task *current_task);


#endif
