#ifndef _ROM_4K_H
#define _ROM_4K_H

/* 4KiB unbanked cartridge */

WORD rom_4k_read(WORD addr)
{
    return (WORD)(rom.mem[addr]);
}

void rom_4k_write(WORD addr, BYTE val)
{
    rom.mem[addr] = val;
}

#endif

