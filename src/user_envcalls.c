#include "user_envcalls.h"
#include "envcalls.h"

uint32 envcall0(uint32 id) {
    uint32 retval;
    asm("sw a7, %0 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(id));
    return retval;
}

uint32 envcall1(uint32 id, uint32 arg1) {
    uint32 retval;
    asm("sw a0, %0 \n"
        "sw a7, %1 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(arg1), "r"(id));
    return retval;
}

uint32 envcall2(uint32 id, uint32 arg1, uint32 arg2) {
    uint32 retval;
    asm("sw a0, %0 \n"
        "sw a1, %1 \n"
        "sw a7, %2 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(arg1), "r"(arg2), "r"(id));
    return retval;
}

uint32 envcall3(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3) {
    uint32 retval;
    asm("sw a0, %0 \n"
        "sw a1, %1 \n"
        "sw a2, %2 \n"
        "sw a7, %3 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(arg1), "r"(arg2), "r"(arg3), "r"(id));
    return retval;
}

uint32 envcall4(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3, uint32 arg4) {
    uint32 retval;
    asm("sw a0, %0 \n"
        "sw a1, %1 \n"
        "sw a2, %2 \n"
        "sw a3, %3 \n"
        "sw a7, %4 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4), "r"(id));
    return retval;
}

uint32 envcall5(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3, uint32 arg4,
                uint32 arg5) {
    uint32 retval;
    asm("sw a0, %0 \n"
        "sw a1, %1 \n"
        "sw a2, %2 \n"
        "sw a3, %3 \n"
        "sw a4, %4 \n"
        "sw a7, %5 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4), "r"(arg5), "r"(id));
    return retval;
}

uint32 envcall6(uint32 id, uint32 arg1, uint32 arg2, uint32 arg3, uint32 arg4,
                uint32 arg5, uint32 arg6) {
    uint32 retval;
    asm("sw a0, %0 \n"
        "sw a1, %1 \n"
        "sw a2, %2 \n"
        "sw a3, %3 \n"
        "sw a4, %4 \n"
        "sw a5, %5 \n"
        "sw a7, %6 \n"
        "ecall \n"
        "lw a0, %0 \n"
        : "=r"(retval)
        : "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4), "r"(arg5), "r"(arg6),
          "r"(id));
    return retval;
}

uint32 env_write_console(uint32 interface, char* buf, uint32 count) {
    return envcall3(ENV_WRITE_CONSOLE, interface, (uint32) buf, count);
}

uint32 env_read_console(uint32 interface, char* buf, uint32 count) {
    return envcall3(ENV_READ_CONSOLE, interface, (uint32) buf, count);
}

uint32 env_set_green_led(uint32 enable) {
    return envcall1(ENV_SET_GREEN_LED, enable);
}

uint32 env_set_red_led(uint32 enable) {
    return envcall1(ENV_SET_RED_LED, enable);
}

uint32 env_set_blue_led(uint32 enable) {
    return envcall1(ENV_SET_BLUE_LED, enable);
}

uint32 env_set_gpio_pin(uint32 pin, uint32 enable) {
    return envcall2(ENV_SET_BLUE_LED, pin, enable);
}

uint32 env_terminate_task(uint32 taskid) {
    return envcall1(ENV_TERMINATE_TASK, taskid);
}

