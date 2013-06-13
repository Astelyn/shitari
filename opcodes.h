/* Storage */
case 0xA9: FETCH_IMM(); goto LDA;     // LDA IMM
case 0xA5: FETCH_ZPG(); goto LDA;     // LDA ZP
case 0xB5: FETCH_ZPX(); goto LDA;     // LDA ZPX
case 0xAD: FETCH_ABS(); goto LDA;     // LDA ABS
case 0xBD: FETCH_ABX(); goto LDA;     // LDA ABSX
case 0xB9: FETCH_ABY(); goto LDA;     // LDA ABSY
case 0xA1: FETCH_INX(); goto LDA;     // LDA INDX
case 0xB1: FETCH_INY();               // LDA INDY
LDA:                                  // Load a value into A
    REG_A = operand;
    CALC_Z(REG_A);
    CALC_S(REG_A);
    break;

case 0xA6: FETCH_ZPG(); goto LDX;     // LDX ZP
case 0xB6: FETCH_ZPY(); goto LDX;     // LDX ZPY
case 0xAE: FETCH_ABS(); goto LDX;     // LDX ABS
case 0xBE: FETCH_ABY(); goto LDX;     // LDX ABSY
case 0xA2: FETCH_IMM();               // LDX IMM
LDX:                                  // Load a value into X
    REG_X = operand;
    CALC_Z(REG_X);
    CALC_S(REG_X);
    break;

case 0xA0: FETCH_IMM(); goto LDY;     // LDY IMM
case 0xA4: FETCH_ZPG(); goto LDY;     // LDY ZP
case 0xB4: FETCH_ZPX(); goto LDY;     // LDY ZPX
case 0xAC: FETCH_ABS(); goto LDY;     // LDY ABS
case 0xBC: FETCH_ABX();               // LDY ABSX
LDY:                                  // Load a value into Y
    REG_Y = operand;
    CALC_Z(REG_Y);
    CALC_S(REG_Y);
    break;

case 0x85: FETCH_ZPG(); goto STA;     // STA ZP
case 0x95: FETCH_ZPX(); goto STA;     // STA ZPX
case 0x8D: FETCH_ABS(); goto STA;     // STA ABS
case 0x9D: FETCH_ABX(); goto STA;     // STA ABSX
case 0x99: FETCH_ABY(); goto STA;     // STA ABSY
case 0x81: FETCH_INX(); goto STA;     // STA INDX
case 0x91: FETCH_INY();               // STA INDY
STA:                                  // Store operand in A
    mmu_write(oper_addr, REG_A);
    break;

case 0x86: FETCH_ZPG(); goto STX;     // STX ZP
case 0x96: FETCH_ZPY(); goto STX;     // STX ZPY
case 0x8E: FETCH_ABS();               // STX ABS
STX:                                  // Store operand in X
    mmu_write(oper_addr, REG_X);
    break;

case 0x84: FETCH_ZPG(); goto STY;     // STY ZP
case 0x94: FETCH_ZPX(); goto STY;     // STY ZPX
case 0x8C: FETCH_ABS();               // STY ABS
STY:                                  // Store operand in Y
    mmu_write(oper_addr, REG_Y);
    break;

case 0xAA:                            // TAX
    REG_X = REG_A;                    // Transfer A to X
    CALC_Z(REG_X);
    CALC_S(REG_X);
    break;

case 0xA8:                            // TAY
    REG_Y = REG_A;                    // Transfer A to Y
    CALC_Z(REG_Y);
    CALC_S(REG_Y);
    break;

case 0xBA:                            // TSX
    REG_X = REG_SP;                   // Transfer SP to X
    CALC_Z(REG_X);
    CALC_S(REG_X);
    break;

case 0x8A:                            // TXA
    REG_A = REG_X;                    // Transfer X to A
    CALC_Z(REG_A);
    CALC_S(REG_A);
    break;

case 0x9A:                            // TXS
    REG_SP = REG_X;                   // Transfer X to SP
    break;

case 0x98:                            // TYA
    REG_A = REG_Y;                    // Transfer Y to A
    CALC_Z(REG_A);
    CALC_S(REG_A);
    break;

/* Arithmetic */
case 0x69: FETCH_IMM(); goto ADC;     // ADC IMM
case 0x65: FETCH_ZPG(); goto ADC;     // ADC ZP
case 0x75: FETCH_ZPX(); goto ADC;     // ADC ZPX
case 0x6D: FETCH_ABS(); goto ADC;     // ADC ABS
case 0x7D: FETCH_ABX(); goto ADC;     // ADC ABSX
case 0x79: FETCH_ABY(); goto ADC;     // ADC ABSY
case 0x61: FETCH_INX(); goto ADC;     // ADC INDX
case 0x71: FETCH_INY();               // ADC INDY
ADC:                                  // Add with Carry
    REG_A = REG_A + operand
            + (REG_S & FLAG_C);
    CALC_C(REG_A);
    CALC_Z(REG_A);
    CALC_V(REG_A);
    CALC_S(REG_A);
    //TODO: NES-specific stuff
    break;

case 0xD6: FETCH_ZPX(); goto DEC;     // DEC ZPX
case 0xCE: FETCH_ABS(); goto DEC;     // DEC ABS
case 0xDE: FETCH_ABX();               // DEC ABSX
DEC:                                  // Decrement operand by 1
    tmp = operand - 1;
    mmu_write(oper_addr, tmp);
    CALC_Z(tmp);
    CALC_S(tmp);
    break;

case 0xCA:                            // DEX
    REG_X--;                          // Decrement X by 1
    CALC_Z(REG_X);
    CALC_S(REG_X);
    break;

case 0x88:                            // DEY
    REG_Y--;                          // Decrement Y by 1
    CALC_Z(REG_Y);
    CALC_S(REG_Y);
    break;

case 0xE6: FETCH_ZPG(); goto INC;     // INC ZP
case 0xF6: FETCH_ZPX(); goto INC;     // INC ZPX
case 0xEE: FETCH_ABS(); goto INC;     // INC ABS
case 0xFE: FETCH_ABX();               // INC ABSX
INC:                                  // Increment operand by 1
    tmp = operand + 1;
    mmu_write(oper_addr, tmp);
    CALC_Z(tmp);
    CALC_S(tmp);
    break;

case 0xE8:                            // INX
    REG_X++;                          // Increment X by 1
    CALC_Z(REG_X);
    CALC_S(REG_X);
    break;

case 0xC8:                            // INY
    REG_Y++;                          // Increment Y by 1
    CALC_Z(REG_Y);
    CALC_S(REG_Y);
    break;

case 0xE9: FETCH_IMM(); goto SBC;     // SBC IMM
case 0xE5: FETCH_ZPG(); goto SBC;     // SBC ZP
case 0xF5: FETCH_ZPX(); goto SBC;     // SBC ZPX
case 0xED: FETCH_ABS(); goto SBC;     // SBC ABS
case 0xFD: FETCH_ABX(); goto SBC;     // SBC ABSX
case 0xF9: FETCH_ABY(); goto SBC;     // SBC ABSY
case 0xE1: FETCH_INX(); goto SBC;     // SBC INDX
case 0xF1: FETCH_INY();               // SBC INDY
SBC:                                  // Subtract with Carry
    REG_A = REG_A + (operand ^ 0xFF)
            + (REG_S & FLAG_C);
    CALC_C(REG_A);
    CALC_Z(REG_A);
    CALC_V(REG_A);
    CALV_S(REG_A);
    break;

/* Bitwise */
case 0x29: FETCH_IMM(); goto AND;     // AND IMM
case 0x25: FETCH_ZPG(); goto AND;     // AND ZP
case 0x35: FETCH_ZPX(); goto AND;     // AND ZPX
case 0x2D: FETCH_ABS(); goto AND;     // AND ABS
case 0x3D: FETCH_ABX(); goto AND;     // AND ABSX
case 0x39: FETCH_ABY(); goto AND;     // AND ABSY
case 0x21: FETCH_INX(); goto AND;     // AND INDX
case 0x31: FETCH_INY();               // AND INDY
AND:
    break;

case 0x0A: FETCH_ACC(); goto ;     // ASL ACC
case 0x06: FETCH_ZPG(); goto ;     // ASL ZP
case 0x16: FETCH_ZPX(); goto ;     // ASL ZPX
case 0x0E: FETCH_ABS(); goto ;     // ASL ABS
case 0x1E: FETCH_ABX(); goto ;     // ASL ABSX
ASL:
    break;

case 0x24: FETCH_ZPG(); goto ;     // BIT ZP
case 0x2C: FETCH_ABS(); goto ;     // BIT ABS
BIT:
    break;

case 0x49: FETCH_IMM(); goto ;     // EOR IMM
case 0x45: FETCH_ZPG(); goto ;     // EOR ZP
case 0x55: FETCH_ZPX(); goto ;     // EOR ZPX
case 0x4D: FETCH_ABS(); goto ;     // EOR ABS
case 0x5D: FETCH_ABX(); goto ;     // EOR ABSX
case 0x59: FETCH_ABY(); goto ;     // EOR ABSY
case 0x41: FETCH_INX(); goto ;     // EOR INDX
case 0x51: FETCH_INY(); goto ;     // EOR INDY
EOR:
    break;

case 0x4A: FETCH_ACC(); goto ;     // LSR ACC
case 0x46: FETCH_ZPG(); goto ;     // LSR ZP
case 0x56: FETCH_ZPX(); goto ;     // LSR ZPX
case 0x4E: FETCH_ABS(); goto ;     // LSR ABS
case 0x5E: FETCH_ABX(); goto ;     // LSR ABSX
LSR:
    break;

case 0x09: FETCH_IMM(); goto ;     // ORA IMM
case 0x05: FETCH_ZPG(); goto ;     // ORA ZP
case 0x15: FETCH_ZPX(); goto ;     // ORA ZPX
case 0x0D: FETCH_ABS(); goto ;     // ORA ABS
case 0x1D: FETCH_ABX(); goto ;     // ORA ABSX
case 0x19: FETCH_ABY(); goto ;     // ORA ABSY
case 0x01: FETCH_INX(); goto ;     // ORA INDX
case 0x11: FETCH_INY(); goto ;     // ORA INDY
ORA:
    break;

case 0x2A: FETCH_ACC(); goto ;     // ROL ACC
case 0x26: FETCH_ZPG(); goto ;     // ROL ZP
case 0x36: FETCH_ZPX(); goto ;     // ROL ZPX
case 0x2E: FETCH_ABS(); goto ;     // ROL ABS
case 0x3E: FETCH_ABX(); goto ;     // ROL ABSX
ROL:
    break;

case 0x6A: FETCH_ACC(); goto ;     // ROR ACC
case 0x66: FETCH_ZPG(); goto ;     // ROR ZP
case 0x76: FETCH_ZPX(); goto ;     // ROR ZPX
case 0x6E: FETCH_ABS(); goto ;     // ROR ABS
case 0x7E: FETCH_ABX(); goto ;     // ROR ABSX
ROR:
    break;

/* Branch */
case 0x90: FETCH_(); goto ;     // BCC
case 0xB0: FETCH_(); goto ;     // BCS
case 0xF0: FETCH_(); goto ;     // BEQ
case 0x30: FETCH_(); goto ;     // BMI
case 0xD0: FETCH_(); goto ;     // BNE
case 0x10: FETCH_(); goto ;     // BPL
case 0x50: FETCH_(); goto ;     // BVC
case 0x70: FETCH_(); goto ;     // BVS

/* Jump */
case 0x6C: FETCH_IND(); goto ;     // JMP IND
case 0x4C: FETCH_ABS(); goto ;     // JMP ABS
JMP:
    break;

case 0x20: FETCH_(); goto ;     // JSR
case 0x40: FETCH_(); goto ;     // RTI
case 0x60: FETCH_(); goto ;     // RTS

/* Registers */
case 0x18: FETCH_(); goto ;     // CLC
case 0xD8: FETCH_(); goto ;     // CLD
case 0x58: FETCH_(); goto ;     // CLI
case 0xB8: FETCH_(); goto ;     // CLV

case 0xC9: FETCH_IMM(); goto ;     // CMP IMM
case 0xC5: FETCH_ZPG(); goto ;     // CMP ZP
case 0xD5: FETCH_ZPX(); goto ;     // CMP ZPX
case 0xCD: FETCH_ABS(); goto ;     // CMP ABS
case 0xDD: FETCH_ABX(); goto ;     // CMP ABSX
case 0xD9: FETCH_ABY(); goto ;     // CMP ABSY
case 0xC1: FETCH_INX(); goto ;     // CMP INDX
case 0xD1: FETCH_INY(); goto ;     // CMP INDY
CMP:
    break;

case 0xE0: FETCH_IMM(); goto ;     // CPX IMM
case 0xE4: FETCH_ZPG(); goto ;     // CPX ZP
case 0xEC: FETCH_ABS(); goto ;     // CPX ABS
CPX:
    break;

case 0xC0: FETCH_IMM(); goto ;     // CPY IMM
case 0xC4: FETCH_ZPG(); goto ;     // CPY ZP
case 0xCC: FETCH_ABS(); goto ;     // CPY ABS
CPY:
    break;

case 0x38: FETCH_(); goto ;     // SEC
case 0xF8: FETCH_(); goto ;     // SED
case 0x78: FETCH_(); goto ;     // SEI

/* Stack */
case 0x48: FETCH_(); goto ;     // PHA
case 0x08: FETCH_(); goto ;     // PHP
case 0x68: FETCH_(); goto ;     // PLA
case 0x28: FETCH_(); goto ;     // PLP

/* System */
case 0x00: FETCH_(); goto ;     // BRK
case 0xEA: FETCH_(); goto ;     // NOP

