#ifndef RISCV_H
#define RISCV_H

#include "primitives.h"

#define MSTATUS_MPP_MASK (3 << 11) // previous mode
#define MSTATUS_MPP_M (3 << 11)
#define MSTATUS_MPP_U (0 << 11)
#define MSTATUS_MIE (1 << 3)    // machine-mode interrupt enable

#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software


__attribute__((always_inline)) static inline uint32 read_mstatus() {
    uint32 mstatus;
    asm volatile("csrr %0, mstatus" :  "=r" (mstatus));
    return mstatus;
}

__attribute__((always_inline)) static inline void write_mstatus(uint32 mstatus) {
    asm volatile("csrw mstatus, %0" : : "r" (mstatus)); 
}

__attribute__((always_inline)) static inline uint32 read_mcause() {
    uint32 mcause;
    asm volatile("csrr %0, mcause" :  "=r" (mcause));
    return mcause;
}

__attribute__((always_inline)) static inline void write_mcause(uint32 mcause) {
    asm volatile("csrw mcause, %0" : : "r" (mcause)); 
}

__attribute__((always_inline)) static inline uint32 read_mie() {
    uint32 mie;
    asm volatile("csrr %0, mie" :  "=r" (mie));
    return mie;
}

__attribute__((always_inline)) static inline void write_mie(uint32 mie) {
    asm volatile("csrw mie, %0" : : "r" (mie)); 
}

__attribute__((always_inline)) static inline uint32 read_mepc() {
    uint32 mepc;
    asm volatile("csrr %0, mepc" :  "=r" (mepc));
    return mepc;
}

__attribute__((always_inline)) static inline void write_mepc(uint32 mepc) {
    asm volatile("csrw mepc, %0" : : "r" (mepc)); 
}

__attribute__((always_inline)) static inline uint32 read_mpie() {
    uint32 mpie;
    asm volatile("csrr %0, mpie" :  "=r" (mpie));
    return mpie;
}

__attribute__((always_inline)) static inline void write_mpie(uint32 mpie) {
    asm volatile("csrw mpie, %0" : : "r" (mpie)); 
}

__attribute__((always_inline)) static inline uint32 read_mpp() {
    uint32 mpp;
    asm volatile("csrr %0, mpp" :  "=r" (mpp));
    return mpp;
}

__attribute__((always_inline)) static inline void write_mpp(uint32 mpp) {
    asm volatile("csrw mpp, %0" : : "r" (mpp)); 
}

__attribute__((always_inline)) static inline uint32 read_mtvec() {
    uint32 mtvec;
    asm volatile("csrr %0, mtvec" :  "=r" (mtvec));
    return mtvec;
}

__attribute__((always_inline)) static inline void write_mtvec(uint32 mtvec) {
    asm volatile("csrw mtvec, %0" : : "r" (mtvec)); 
}

__attribute__((always_inline)) static inline uint32 read_mscratch() {
    uint32 mscratch;
    asm volatile("csrr %0, mscratch" :  "=r" (mscratch));
    return mscratch;
}

__attribute__((always_inline)) static inline void write_mscratch(uint32 mscratch) {
    asm volatile("csrw mscratch, %0" : : "r" (mscratch)); 
}

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
