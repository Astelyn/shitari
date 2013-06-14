#ifndef _ROM_H
#define _ROM_H

#include "common.h"

#define READ(a) rom.read(a)

typedef enum {

} cart_type_e;

typedef struct {
    cart_type_e type;
    BYTE* mem;
    WORD* (*read)(WORD);
    void* (*write)(WORD, BYTE);
} rom_t;

WORD mmu_read(WORD addr);
void mmu_write(WORD addr, BYTE val);

#endif

