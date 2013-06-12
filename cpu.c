#include "cpu.h"

cpu_t cpu;

static BYTE opcode;
static WORD oper_addr;
static WORD operand;
static int cycles_left;

static int timings[256] = {
/*     |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |A |B |C |D |E |F |*/
/* 0 */ 7, 6, 2, 8, 3, 3, 5, 5, 3, 2, 2, 2, 4, 4, 6, 6,
/* 1 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
/* 2 */ 6, 6, 2, 8, 3, 3, 5, 5, 4, 2, 2, 2, 4, 4, 6, 6,
/* 3 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
/* 4 */ 6, 6, 2, 8, 3, 3, 5, 5, 3, 2, 2, 2, 3, 4, 6, 6,
/* 5 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
/* 6 */ 6, 6, 2, 8, 3, 3, 5, 5, 4, 2, 2, 2, 5, 4, 6, 6,
/* 7 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
/* 8 */ 2, 6, 2, 6, 3, 3, 3, 3, 2, 2, 2, 2, 4, 4, 4, 4,
/* 9 */ 2, 6, 2, 6, 4, 4, 4, 4, 2, 5, 2, 5, 5, 5, 5, 5,
/* A */ 2, 6, 2, 6, 3, 3, 3, 3, 2, 2, 2, 2, 4, 4, 4, 4,
/* B */ 2, 5, 2, 5, 4, 4, 4, 4, 2, 4, 2, 4, 4, 4, 4, 4,
/* C */ 2, 6, 2, 8, 3, 3, 5, 5, 2, 2, 2, 2, 4, 4, 6, 6,
/* D */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
/* E */ 2, 6, 2, 8, 3, 3, 5, 5, 2, 2, 2, 2, 4, 4, 6, 6,
/* F */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7
};

void cpu_init(void)
{
    REG_A = 0;
    REG_X = 0;
    REG_Y = 0;
    REG_PC = 0;
    REG_SP = 0;

    opcode = 0;
    oper_addr = 0;
    operand = 0;
    cycles_left = 0;
}

void cpu_stop(void)
{
    cycles_left = 0;
}

void cpu_run(int cycles)
{
    cycles_left = cycles;

    while (cycles_left > 0) {
        opcode = mmu_read(REG_PC++);

        switch (opcode) {
            /* Storage */
            case 0xA9: // LDA IMM
                break;

            case 0xA5: // LDA ZP
                break;

            case 0xB5: // LDA ZPX
                break;

            case 0xAD: // LDA ABS
                break;

            case 0xBD: // LDA ABSX
                break;

            case 0xB9: // LDA ABSY
                break;

            case 0xA1: // LDA INDX
                break;

            case 0xB1: // LDA INDY
                break;

            case 0xA6: // LDX ZP
                break;

            case 0xB6: // LDX ZPY
                break;

            case 0xAE: // LDX ABS
                break;

            case 0xBE: // LDX ABSY
                break;

            case 0xA2: // LDX IMM
                break;

            case 0xA0: // LDY IMM
                break;

            case 0xA4: // LDY ZP
                break;

            case 0xB4: // LDY ZPX
                break;

            case 0xAC: // LDY ABS
                break;

            case 0xBC: // LDY ABSX
                break;

            case 0x85: // STA ZP
                break;

            case 0x95: // STA ZPX
                break;

            case 0x8D: // STA ABS
                break;

            case 0x9D: // STA ABSX
                break;

            case 0x99: // STA ABSY
                break;

            case 0x81: // STA INDX
                break;

            case 0x91: // STA INDY
                break;

            case 0x86: // STX ZP
                break;

            case 0x96: // STX ZPY
                break;

            case 0x8E: // STX ABS
                break;

            case 0x84: // STY ZP
                break;

            case 0x94: // STY ZPX
                break;

            case 0x8C: // STY ABS
                break;

            case 0xAA: // TAX
                break;

            case 0xA8: // TAY
                break;

            case 0xBA: // TSX
                break;

            case 0x8A: // TXA
                break;

            case 0x9A: // TXS
                break;

            case 0x98: // TYA
                break;


            /* Arithmetic */
            case 0x69: // ADC IMM
                break;

            case 0x65: // ADC ZP
                break;

            case 0x75: // ADC ZPX
                break;

            case 0x6D: // ADC ABS
                break;

            case 0x7D: // ADC ABSX
                break;

            case 0x79: // ADC ABSY
                break;

            case 0x61: // ADC INDX
                break;

            case 0x71: // ADC INDY
                break;

            case 0xD6: // DEC ZPX
                break;

            case 0xCE: // DEC ABS
                break;

            case 0xDE: // DEC ABSX
                break;

            case 0xCA: // DEX
                break;

            case 0x88: // DEY
                break;

            case 0xE6: // INC ZP
                break;

            case 0xF6: // INC ZPX
                break;

            case 0xEE: // INC ABS
                break;

            case 0xFE: // INC ABSX
                break;

            case 0xE8: // INX
                break;

            case 0xC8: // INY
                break;

            case 0xE9: // SBC IMM
                break;

            case 0xE5: // SBC ZP
                break;

            case 0xF5: // SBC ZPX
                break;

            case 0xED: // SBC ABS
                break;

            case 0xFD: // SBC ABSX
                break;

            case 0xF9: // SBC ABSY
                break;

            case 0xE1: // SBC INDX
                break;

            case 0xF1: // SBC INDY
                break;


            /* Bitwise */
            case 0x29: // AND IMM
                break;

            case 0x25: // AND ZP
                break;

            case 0x35: // AND ZPX
                break;

            case 0x2D: // AND ABS
                break;

            case 0x3D: // AND ABSX
                break;

            case 0x39: // AND ABSY
                break;

            case 0x21: // AND INDX
                break;

            case 0x31: // AND INDY
                break;

            case 0x0A: // ASL ACC
                break;

            case 0x06: // ASL ZP
                break;

            case 0x16: // ASL ZPX
                break;

            case 0x0E: // ASL ABS
                break;

            case 0x1E: // ASL ABSX
                break;

            case 0x24: // BIT ZP
                break;

            case 0x2C: // BIT ABS
                break;

            case 0x49: // EOR IMM
                break;

            case 0x45: // EOR ZP
                break;

            case 0x55: // EOR ZPX
                break;

            case 0x4D: // EOR ABS
                break;

            case 0x5D: // EOR ABSX
                break;

            case 0x59: // EOR ABSY
                break;

            case 0x41: // EOR INDX
                break;

            case 0x51: // EOR INDY
                break;

            case 0x4A: // LSR ACC
                break;

            case 0x46: // LSR ZP
                break;

            case 0x56: // LSR ZPX
                break;

            case 0x4E: // LSR ABS
                break;

            case 0x5E: // LSR ABSX
                break;

            case 0x09: // ORA IMM
                break;

            case 0x05: // ORA ZP
                break;

            case 0x15: // ORA ZPX
                break;

            case 0x0D: // ORA ABS
                break;

            case 0x1D: // ORA ABSX
                break;

            case 0x19: // ORA ABSY
                break;

            case 0x01: // ORA INDX
                break;

            case 0x11: // ORA INDY
                break;

            case 0x2A: // ROL ACC
                break;

            case 0x26: // ROL ZP
                break;

            case 0x36: // ROL ZPX
                break;

            case 0x2E: // ROL ABS
                break;

            case 0x3E: // ROL ABSX
                break;

            case 0x6A: // ROR ACC
                break;

            case 0x66: // ROR ZP
                break;

            case 0x76: // ROR ZPX
                break;

            case 0x6E: // ROR ABS
                break;

            case 0x7E: // ROR ABSX
                break;


            /* Branch */
            case 0x90: // BCC
                break;

            case 0xB0: // BCS
                break;

            case 0xF0: // BEQ
                break;

            case 0x30: // BMI
                break;

            case 0xD0: // BNE
                break;

            case 0x10: // BPL
                break;

            case 0x50: // BVC
                break;

            case 0x70: // BVS
                break;


            /* Jump */
            case 0x6C: // JMP IND
                break;

            case 0x4C: // JMP ABS
                break;

            case 0x20: // JSR
                break;

            case 0x40: // RTI
                break;

            case 0x60: // RTS
                break;


            /* Registers */
            case 0x18: // CLC
                break;

            case 0xD8: // CLD
                break;

            case 0x58: // CLI
                break;

            case 0xB8: // CLV
                break;

            case 0xC9: // CMP IMM
                break;

            case 0xC5: // CMP ZP
                break;

            case 0xD5: // CMP ZPX
                break;

            case 0xCD: // CMP ABS
                break;

            case 0xDD: // CMP ABSX
                break;

            case 0xD9: // CMP ABSY
                break;

            case 0xC1: // CMP INDX
                break;

            case 0xD1: // CMP INDY
                break;

            case 0xE0: // CPX IMM
                break;

            case 0xE4: // CPX ZP
                break;

            case 0xEC: // CPX ABS
                break;

            case 0xC0: // CPY IMM
                break;

            case 0xC4: // CPY ZP
                break;

            case 0xCC: // CPY ABS
                break;

            case 0x38: // SEC
                break;

            case 0xF8: // SED
                break;

            case 0x78: // SEI
                break;


            /* Stack */
            case 0x48: // PHA
                break;

            case 0x08: // PHP
                break;

            case 0x68: // PLA
                break;

            case 0x28: // PLP
                break;


            /* System */
            case 0x00: // BRK
                break;

            case 0xEA: // NOP
                break;
        }

        cycles_left -= timings[opcode];
    }
}

