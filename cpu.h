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

#define FLAG_C 0x01
#define FLAG_Z 0x02
#define FLAG_I 0x03
#define FLAG_D 0x08
#define FLAG_B 0x10
#define FLAG_T 0x20
#define FLAG_V 0x40
#define FLAG_S 0x80

typedef struct {
    BYTE a, x, y, s;
    WORD pc, sp;
} cpu_t;

void cpu_init(void);
void cpu_stop(void);
void cpu_run(int cycles);

#endif

