#ifndef USER_ENVCALLS_H
#define USER_ENVCALLS_H

#include "envcalls.h"
#include "primitives.h"
#include "scheduler.h"

uint32 envcall0(uint32 id);
uint32 envcall1(uint32 id, uint32 arg1);
uint32 envcall2(uint32 id, uint32 arg1, uint32 arg2);
uint32 envcall3(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3);
uint32 envcall4(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3, uint32 arg4);
uint32 envcall5(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3, uint32 arg4,
                uint32 arg5);
uint32 envcall6(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3, uint32 arg4,
                uint32 arg5, uint32 arg6);

uint32 env_write_console(uint32 interface, char* buf, uint32 count);
uint32 env_read_console(uint32 interface, char* buf, uint32 count);
uint32 env_set_green_led(uint32 enable);
uint32 env_set_red_led(uint32 enable);
uint32 env_set_blue_led(uint32 enable);
uint32 env_set_gpio_pin(uint32 pin, uint32 enable);
uint32 env_terminate_task(uint32 taskid);

#endif
