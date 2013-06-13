/* Storage */
case 0xA9: FETCH_IMM(); goto LDA; // LDA IMM
case 0xA5: FETCH_ZPG(); goto LDA; // LDA ZP
case 0xB5: FETCH_ZPX(); goto LDA; // LDA ZPX
case 0xAD: FETCH_ABS(); goto LDA; // LDA ABS
case 0xBD: FETCH_ABX(); goto LDA; // LDA ABSX
case 0xB9: FETCH_ABY(); goto LDA; // LDA ABSY
case 0xA1: FETCH_INX(); goto LDA; // LDA INDX
case 0xB1: FETCH_INY();           // LDA INDY
LDA:
    REG_A = (BYTE)operand;        // Load a value into A
    CALC_Z(REG_A);
    CALC_S(REG_A);
    break;

case 0xA6: FETCH_ZPG(); goto LDX; // LDX ZP
case 0xB6: FETCH_ZPY(); goto LDX; // LDX ZPY
case 0xAE: FETCH_ABS(); goto LDX; // LDX ABS
case 0xBE: FETCH_ABY(); goto LDX; // LDX ABSY
case 0xA2: FETCH_IMM(); goto LDX; // LDX IMM
LDX:
    REG_X = (BYTE)operand;        // Load a value into X
    CALC_Z(REG_X);
    CALC_S(REG_X);
    break;

case 0xA0: FETCH_IMM(); goto LDY; // LDY IMM
case 0xA4: FETCH_ZPG(); goto LDY; // LDY ZP
case 0xB4: FETCH_ZPX(); goto LDY; // LDY ZPX
case 0xAC: FETCH_ABS(); goto LDY; // LDY ABS
case 0xBC: FETCH_ABX(); goto LDY; // LDY ABSX
LDY:
    REG_Y = (BYTE)operand;        // Load a value into Y
    CALC_Z(REG_Y);
    CALC_S(REG_Y);
    break;

case 0x85: // STA ZP
case 0x95: // STA ZPX
case 0x8D: // STA ABS
case 0x9D: // STA ABSX
case 0x99: // STA ABSY
case 0x81: // STA INDX
case 0x91: // STA INDY
STA:
    break;

case 0x86: // STX ZP
case 0x96: // STX ZPY
case 0x8E: // STX ABS
STX:
    break;

case 0x84: // STY ZP
case 0x94: // STY ZPX
case 0x8C: // STY ABS
STY:
    break;

case 0xAA: // TAX
case 0xA8: // TAY
case 0xBA: // TSX
case 0x8A: // TXA
case 0x9A: // TXS
case 0x98: // TYA

/* Arithmetic */
case 0x69: // ADC IMM
case 0x65: // ADC ZP
case 0x75: // ADC ZPX
case 0x6D: // ADC ABS
case 0x7D: // ADC ABSX
case 0x79: // ADC ABSY
case 0x61: // ADC INDX
case 0x71: // ADC INDY
ADC:
    break;

case 0xD6: // DEC ZPX
case 0xCE: // DEC ABS
case 0xDE: // DEC ABSX
DEC:
    break;

case 0xCA: // DEX
case 0x88: // DEY

case 0xE6: // INC ZP
case 0xF6: // INC ZPX
case 0xEE: // INC ABS
case 0xFE: // INC ABSX
INC:
    break;

case 0xE8: // INX
case 0xC8: // INY

case 0xE9: // SBC IMM
case 0xE5: // SBC ZP
case 0xF5: // SBC ZPX
case 0xED: // SBC ABS
case 0xFD: // SBC ABSX
case 0xF9: // SBC ABSY
case 0xE1: // SBC INDX
case 0xF1: // SBC INDY
SBC:
    break;

/* Bitwise */
case 0x29: // AND IMM
case 0x25: // AND ZP
case 0x35: // AND ZPX
case 0x2D: // AND ABS
case 0x3D: // AND ABSX
case 0x39: // AND ABSY
case 0x21: // AND INDX
case 0x31: // AND INDY
AND:
    break;

case 0x0A: // ASL ACC
case 0x06: // ASL ZP
case 0x16: // ASL ZPX
case 0x0E: // ASL ABS
case 0x1E: // ASL ABSX
ASL:
    break;

case 0x24: // BIT ZP
case 0x2C: // BIT ABS
BIT:
    break;

case 0x49: // EOR IMM
case 0x45: // EOR ZP
case 0x55: // EOR ZPX
case 0x4D: // EOR ABS
case 0x5D: // EOR ABSX
case 0x59: // EOR ABSY
case 0x41: // EOR INDX
case 0x51: // EOR INDY
EOR:
    break;

case 0x4A: // LSR ACC
case 0x46: // LSR ZP
case 0x56: // LSR ZPX
case 0x4E: // LSR ABS
case 0x5E: // LSR ABSX
LSR:
    break;

case 0x09: // ORA IMM
case 0x05: // ORA ZP
case 0x15: // ORA ZPX
case 0x0D: // ORA ABS
case 0x1D: // ORA ABSX
case 0x19: // ORA ABSY
case 0x01: // ORA INDX
case 0x11: // ORA INDY
ORA:
    break;

case 0x2A: // ROL ACC
case 0x26: // ROL ZP
case 0x36: // ROL ZPX
case 0x2E: // ROL ABS
case 0x3E: // ROL ABSX
ROL:
    break;

case 0x6A: // ROR ACC
case 0x66: // ROR ZP
case 0x76: // ROR ZPX
case 0x6E: // ROR ABS
case 0x7E: // ROR ABSX
ROR:
    break;

/* Branch */
case 0x90: // BCC
case 0xB0: // BCS
case 0xF0: // BEQ
case 0x30: // BMI
case 0xD0: // BNE
case 0x10: // BPL
case 0x50: // BVC
case 0x70: // BVS

/* Jump */
case 0x6C: // JMP IND
case 0x4C: // JMP ABS
JMP:
    break;

case 0x20: // JSR
case 0x40: // RTI
case 0x60: // RTS

/* Registers */
case 0x18: // CLC
case 0xD8: // CLD
case 0x58: // CLI
case 0xB8: // CLV

case 0xC9: // CMP IMM
case 0xC5: // CMP ZP
case 0xD5: // CMP ZPX
case 0xCD: // CMP ABS
case 0xDD: // CMP ABSX
case 0xD9: // CMP ABSY
case 0xC1: // CMP INDX
case 0xD1: // CMP INDY
CMP:
    break;

case 0xE0: // CPX IMM
case 0xE4: // CPX ZP
case 0xEC: // CPX ABS
CPX:
    break;

case 0xC0: // CPY IMM
case 0xC4: // CPY ZP
case 0xCC: // CPY ABS
CPY:
    break;

case 0x38: // SEC
case 0xF8: // SED
case 0x78: // SEI

/* Stack */
case 0x48: // PHA
case 0x08: // PHP
case 0x68: // PLA
case 0x28: // PLP

/* System */
case 0x00: // BRK
case 0xEA: // NOP

