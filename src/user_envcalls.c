#include "user_envcalls.h"

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

uint32 env_terminate_task(uint32 taskid) {
    return envcall0(ENV_TERMINATE_TASK);
}
