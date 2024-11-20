#include "../kernel_envcalls.h"
#include "interrupts.h"

__attribute__((interrupt ("machine"))) void exception_handler() {

}

__attribute__((interrupt ("machine"))) void default_handler() {

}

__attribute__((interrupt ("machine"))) void ext_handler() {

}

__attribute__((interrupt ("machine"))) void timer_handler() {

}

// the software handler should serve environment calls
__attribute__((interrupt ("machine"))) void sw_handler() {
    __save_trapframe();

    __restore_trapframe();
}

