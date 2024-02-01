#include "clint.h"
#include "../primitives.h"

#define MTIMECMP 0x2004000
#define MTIME 0x200bff8

#define MTIME_REG_LOW ((uint32 *) MTIME)
#define MTIME_REG_HIGH ((uint32 *) MTIME + WORD_SIZE)
#define MTIMECMP_REG_LOW ((uint32 *) MTIMECMP)
#define MTIMECMP_REG_HIGH ((uint32 *) MTIMECMP + WORD_SIZE)

#define MTIME_MILISECOND 33
#define MTIME_SECOND 32768
#define MTIME_HALF_SECOND 16384
#define MTIME_QUARTER_SECOND 8192


static inline uint32 read_mtime() {
    return *MTIME_REG_LOW;
}

static inline void write_mtime(uint32 mtime) {
    *MTIME_REG_LOW = mtime;
}

static inline uint32 read_mtimecmp() {
    return *MTIMECMP_REG_LOW;
}

static inline void write_mtimecmp(uint32 mtimecmp) {
    *MTIMECMP_REG_LOW = mtimecmp;
}

void add_timer_alarm(uint32 miliseconds) {
    uint32 seconds = miliseconds / 1000;
    uint16 remaining_miliseconds = miliseconds % 1000;
    uint8 halfsecond = remaining_miliseconds / 500;
    uint8 quartersecond = remaining_miliseconds / 250;
    remaining_miliseconds -= 500 * halfsecond;
    remaining_miliseconds -= 250 * quartersecond;

    uint32 mtimecmp_inc = seconds*MTIME_SECOND;
    mtimecmp_inc += halfsecond*MTIME_HALF_SECOND;
    mtimecmp_inc += quartersecond*MTIME_QUARTER_SECOND;
    mtimecmp_inc += remaining_miliseconds*MTIME_MILISECOND;

    write_mtimecmp(read_mtime() + mtimecmp_inc);
}

