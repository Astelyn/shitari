#ifndef _CPU_H
#define _CPU_H

#include "common.h"
#include "mmu.h"

#define REG_A  (cpu.a)
#define REG_X  (cpu.x)
#define REG_Y  (cpu.y)
#define REG_S  (cpu.s)
#define REG_PC (cpu.pc)
#define REG_SP (cpu.sp)

typedef struct {
    BYTE a, x, y, s;
    WORD pc, sp;
} cpu_t;

void cpu_init(void);
void cpu_stop(void);
void cpu_run(int cycles);

#endif

