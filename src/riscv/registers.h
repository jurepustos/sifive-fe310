#ifndef RISCV_REGISTERS_H
#define RISCV_REGISTERS_H

#include "../primitives.h"

__attribute__((always_inline)) static inline uint32 read_sp() {
    uint32 sp;
    asm volatile("mv %0, sp" : "=r" (sp) );
    return sp;
}

__attribute__((always_inline)) static inline void write_sp(uint32 sp) {
    asm volatile("mv sp, %0" : : "r" (sp) );
}

__attribute__((always_inline)) static inline uint32 read_tp() {
    uint32 tp;
    asm volatile("mv %0, tp" : "=r" (tp) );
    return tp;
}

__attribute__((always_inline)) static inline void write_tp(uint32 tp) {
    asm volatile("mv tp, %0" : : "r" (tp) );
}

__attribute__((always_inline)) static inline uint32 read_ra() {
    uint32 ra;
    asm volatile("mv %0, ra" : "=r" (ra) );
    return ra;
}

__attribute__((always_inline)) static inline void write_ra(uint32 ra) {
    asm volatile("mv ra, %0" : : "r" (ra) );
}


#endif
