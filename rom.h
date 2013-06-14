#ifndef _ROM_H
#define _ROM_H

#include "common.h"

#define MEM_READ(a) rom.read(a)
#define MEM_WRITE(a, b) rom.write(a, b)

/* Cartridge format */
typedef enum {
    _4K_UNBANKED // 4KiB unbanked -- rom_4k.h
} cart_type_e;

/* ROM data structure */
typedef struct {
    cart_type_e type;
    BYTE* mem;
    WORD (*read)(WORD);        // Pointer to proprietary read function
    void (*write)(WORD, BYTE); // Pointer to proprietary write function
} rom_t;

extern rom_t rom;

int rom_load(char* file);

#endif

