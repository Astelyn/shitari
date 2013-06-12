#ifndef _CPU_H
#define _CPU_H

#include <stdint.h>
/* #include "mmu.h" */

typedef uint8_t BYTE;  /* Move these somewhere else later */
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int BOOL;
#define TRUE  1
#define FALSE 0

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

