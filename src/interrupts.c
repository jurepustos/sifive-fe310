#include "interrupts.h"
#include "riscv.h"

inline void enable_interrupts() {
    write_mstatus(read_mstatus() | MSTATUS_MIE);
}

inline void disable_interrupts() {
    write_mstatus(read_mstatus() | ~MSTATUS_MIE);
}

inline int get_interrupts_enabled() {
    return (read_mstatus() & MSTATUS_MIE) != 0;
}

inline void enable_timer_interrupts() {
    write_mie(read_mie() | MIE_MTIE);
}

inline void disable_timer_interrupts() {
    write_mie(read_mie() | ~MIE_MTIE);
}

inline void enable_external_interrupts() {
    write_mie(read_mie() | MIE_MEIE);
}

inline void disable_external_interrupts() {
    write_mie(read_mie() | ~MIE_MEIE);
}

inline void enable_software_interrupts() {
    write_mie(read_mie() | MIE_MSIE);
}

inline void disable_software_interrupts() {
    write_mie(read_mie() | ~MIE_MSIE);
}


