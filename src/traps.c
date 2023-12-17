#include "primitives.h"


__attribute__((interrupt ("machine"))) void exception_handler() {

}

__attribute__((interrupt ("machine"))) void default_handler() {

}

__attribute__((interrupt ("machine"))) void ext_handler() {

}

// the timer handler should context-switch
__attribute__((interrupt ("machine"))) void timer_handler() {

}

// the software handler should serve environment calls
// in particular, one of the environment calls starts the task scheduler 
__attribute__((interrupt ("machine"))) void sw_handler() {

}

