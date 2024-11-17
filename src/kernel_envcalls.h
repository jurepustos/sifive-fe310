#ifndef KERNEL_ENVCALLS_H
#define KERNEL_ENVCALLS_H

#include "envcalls.h"
#include "primitives.h"

uint32 handle_envcall(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3,
                      uint32 arg4, uint32 arg5, uint32 arg6);

uint32 kernel_write_console(uint32 interface, char* buf, uint32 count);
uint32 kernel_read_console(uint32 interface, char* buf, uint32 count);
uint32 kernel_set_green_led(uint32 enable);
uint32 kernel_set_red_led(uint32 enable);
uint32 kernel_set_blue_led(uint32 enable);
uint32 kernel_set_gpio_pin(uint32 pin, uint32 enable);
uint32 kernel_terminate_task(uint32 taskid);

#endif
