#include "rom.h"

/* Include different cartridge headers here */
#include "rom_4k.h"

/* Proprietary read functions */
WORD (*read_funcs[])(WORD) = {
    rom_4k_read,
};

/* Proprietary write functions */
void (*write_funcs[])(WORD, BYTE) = {
    rom_4k_write,
};

int rom_load(char* file)
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

    rom.type = _4K_UNBANKED;
    
    rom.read = read_funcs[rom.type];
    rom.write = write_funcs[rom.type];

    rom.mem = (BYTE*)malloc(size);
}

