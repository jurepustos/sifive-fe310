#ifndef CSR_H
#define CSR_H

#include "primitives.h"

#define MSTATUS_MPP_MASK (3 << 11) // previous mode
#define MSTATUS_MPP_M (3 << 11)
#define MSTATUS_MPP_U (0 << 11)
#define MSTATUS_MIE (1 << 3)    // machine-mode interrupt enable

#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software

static inline uint32 read_mstatus() {
    uint32 mstatus;
    asm volatile("csrr %0, mstatus" :  "=r" (mstatus));
    return mstatus;
}

static inline void write_mstatus(uint32 mstatus) {
    asm volatile("csrw mstatus, %0" : : "r" (mstatus)); 
}

static inline uint32 read_mcause() {
    uint32 mcause;
    asm volatile("csrr %0, mcause" :  "=r" (mcause));
    return mcause;
}

static inline void write_mcause(uint32 mcause) {
    asm volatile("csrw mcause, %0" : : "r" (mcause)); 
}

static inline uint32 read_mie() {
    uint32 mie;
    asm volatile("csrr %0, mie" :  "=r" (mie));
    return mie;
}

static inline void write_mie(uint32 mie) {
    asm volatile("csrw mie, %0" : : "r" (mie)); 
}

static inline uint32 read_mepc() {
    uint32 mepc;
    asm volatile("csrr %0, mepc" :  "=r" (mepc));
    return mepc;
}

static inline void write_mepc(uint32 mepc) {
    asm volatile("csrw mepc, %0" : : "r" (mepc)); 
}

static inline uint32 read_mpie() {
    uint32 mpie;
    asm volatile("csrr %0, mpie" :  "=r" (mpie));
    return mpie;
}

static inline void write_mpie(uint32 mpie) {
    asm volatile("csrw mpie, %0" : : "r" (mpie)); 
}

static inline uint32 read_mpp() {
    uint32 mpp;
    asm volatile("csrr %0, mpp" :  "=r" (mpp));
    return mpp;
}

static inline void write_mpp(uint32 mpp) {
    asm volatile("csrw mpp, %0" : : "r" (mpp)); 
}

static inline uint32 read_mtvec() {
    uint32 mtvec;
    asm volatile("csrr %0, mtvec" :  "=r" (mtvec));
    return mtvec;
}

static inline void write_mtvec(uint32 mtvec) {
    asm volatile("csrw mtvec, %0" : : "r" (mtvec)); 
}

static inline uint32 read_mscratch() {
    uint32 mscratch;
    asm volatile("csrr %0, mscratch" :  "=r" (mscratch));
    return mscratch;
}

static inline void write_mscratch(uint32 mscratch) {
    asm volatile("csrw mscratch, %0" : : "r" (mscratch)); 
}

static inline uint32 read_sp() {
    uint32 sp;
    asm volatile("mv %0, sp" : "=r" (sp) );
    return sp;
}

static inline void write_sp(uint32 sp) {
    asm volatile("mv sp, %0" : : "r" (sp) );
}

static inline uint32 read_tp() {
    uint32 tp;
    asm volatile("mv %0, tp" : "=r" (tp) );
    return tp;
}

static inline void write_tp(uint32 tp) {
    asm volatile("mv tp, %0" : : "r" (tp) );
}

static inline uint32 read_ra() {
    uint32 ra;
    asm volatile("mv %0, ra" : "=r" (ra) );
    return ra;
}

static inline void write_ra(uint32 ra) {
    asm volatile("mv ra, %0" : : "r" (ra) );
}



#endif
