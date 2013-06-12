#ifndef _MMU_H
#define _MMU_H

#include "common.h"

typedef struct {
    BYTE* mem;
    // TODO: More will go here later
} mmu_t;

BYTE mmu_read(WORD addr);
void mmu_write(WORD addr, BYTE val);

#endif

