#include "decorder.h"
#include "library.h"

// オペコードの識別
enum opecode identify_opecode(unsigned int num32) {
    switch(cut(num32, 31, 29)) {
        case 0: return OOO_op;
        case 1: return OOI_op;
        case 2: return OIO_op;
        case 4: return IOO_op;
        case 5: return IOI_op;
        case 7: return III_op;
        case 6: return IIO_op;
        default: return Undefined_opecode;
    }
}

// 5桁のfunctの識別
enum funct5 identify_funct5(unsigned int num32) {
    switch(cut(num32, 28, 24)) {
        case 1: return OOOOI;
        case 2: return OOOIO;
        case 4: return OOIOO;
        case 8: return OIOOO;
        case 16: return IOOOO;
        case 17: return IOOOI;
        case 18: return IOOIO;
        case 20: return IOIOO;
        default: return Undefined_funct5;
    }
}

// 3桁のfunctの識別
enum funct3 identify_funct3(unsigned int num32) {
    switch(cut(num32, 28, 26)) {
        case 1: return OOI;
        case 2: return OIO;
        case 4: return IOO;
        case 0: return OOO;
        default: return Undefined_funct3;
    }
}

// ニーモニックの識別
enum nemonic identify_nemonic(enum opecode opecode, enum funct5 funct5, enum funct3 funct3) {
    switch(opecode) {
        case OOO_op:    switch(funct5) {
                            case OOOOI: return ADD;
                            case OOOIO: return SUB;
                            case OOIOO: return SLL;
                            case OIOOO: return SRL;
                            case IOOOO: return SRA;
                            case IOOOI: return FISPOS;
                            case IOOIO: return FISNEG;
                            case IOIOO: return FNEG;
                            default: return UNDEFINED;
                        }
        case OOI_op:    switch(funct5) {
                            case OOOOI: return ADDI;
                            case OOOIO: return SUBI;
                            case OOIOO: return SLLI;
                            case OIOOO: return SRLI;
                            case IOOOO: return SRAI;
                            default: return UNDEFINED;
                        }
                        return UNDEFINED;
        case OIO_op:    switch(funct5) {
                            case OOOOI: return FADD;
                            case OOOIO: return FSUB;
                            case OOIOO: return FMUL;
                            case OIOOO: return FDIV;
                            case IOOOI: return FLESS;
                            case IOOIO: return FTOI;
                            case IOIOO: return ITOF;
                            default: return UNDEFINED;
                        }
        case IOO_op:    switch(funct3) {
                            case OOI: return BEQ;
                            case OIO: return BLT;
                            case IOO: return BLE;
                            default: return UNDEFINED;
                        }
        case IOI_op:    switch(funct3) {
                            case OOO: return J;
                            case OOI: return JR;
                            default: return UNDEFINED;
                        }
        case III_op:    switch(funct3) {
                            case OOO: return LW;
                            default: return UNDEFINED;
                        }
        case IIO_op:    switch(funct3) {
                            case OOO: return SW;
                            default: return UNDEFINED;
                        }
        default:  return UNDEFINED;
    }
}

op_set decord(unsigned int num32) {
    op_set op;
    op.opecode = identify_opecode(num32);
    op.funct5 = identify_funct5(num32);
    op.funct3 = identify_funct3(num32);
    op.nemonic = identify_nemonic(op.opecode, op.funct5, op.funct3);
    op.dest = cut(num32, 23, 16);
    op.src1 = cut(num32, 15, 8);
    op.src2 = cut(num32, 7, 0);
    op.imm10 = cut(num32, 25, 16);
    op.imm26 = cut(num32, 25, 0);
    return op;
}