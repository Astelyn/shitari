#include "common.h"
#include "mem.h"

int mem_load_rom(char* file)
{
    FILE* fp;
    uint64_t size;

    fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("ROM file could not be loaded.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    /* This is where we'd determine the cartridge type
     * based on size and a few other factors. However,
     * for now we'll just assume 4KiB unbanked.
     */

    mem.prg = (BYTE*)malloc(size);
    fread(mem.prg, 1, size, fp);

    fclose(fp);
}

WORD mem_read(WORD addr)
{

}

void mem_write(WORD addr, BYTE val)
{

}

