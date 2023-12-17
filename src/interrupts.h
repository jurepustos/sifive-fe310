#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#define MSTATUS_MIE (1 << 3)    // machine-mode interrupt enable
#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software

void enable_interrupts();
void disable_interrupts();
int get_interrupts_enabled();

void enable_timer_interrupts();
void disable_timer_interrupts();

void enable_external_interrupts();
void disable_external_interrupts();

void enable_software_interrupts();
void disable_software_interrupts();


#endif
