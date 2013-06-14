#ifndef _MEM_H
#define _MEM_H

/*---------------------------+
 | $0000 | TIA registers     | Mirrored at addresses $xyz0
 | $003F |                   | x = even | y = anything | z = [0, 4]
 +-------+-------------------+
 | $0080 | RAM               | Mirrored at addresses $xy80
 |       |                   | x = even | y = [0, 1, 4, 5, 8, 9, C, D]
 |       |                   |
 | $00FF |                   |
 +-------+-------------------+
 | $0280 | PIA I/O registers | Mirrored at addresses $xyz0
 | $029F |                   | x = even | y = [2, 3, 6, 7, A, B, E, F] | z = [8, A, C, E]
 +-------+-------------------+
 | $1000 | PRG ROM           | Mirrored at addresses $x000
 |       |                   | x = odd
 |       |                   |
 |       |                   |
 |       |                   |
 |       |                   |
 | $1FFF |                   |
 +---------------------------*/

typedef struct {
    BYTE tia[0x0040]; // TIA registers
    BYTE ram[0x0080]; // RIOT RAM
    BYTE pia[0x0020]; // PIA registers
    BYTE* prg;        // Program ROM
    BYTE vec[0x0006]; // Vectors
} mem_t;

/* Global memory */
extern mem_t mem;

int mem_load_rom(char* file);
WORD mem_read(WORD addr);
void mem_write(WORD addr, BYTE val);

#endif

