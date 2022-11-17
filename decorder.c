#include "decorder.h"
#include "library.h"

//オペコード
enum opecode { OOO_op, OOI_op, OIO_op, IOO_op, IOI_op, III_op, IIO_op, Undefined_opecode };  // O = 0, I = 1

//5桁のfunct
enum funct5 { OOOOI, OOOIO, OOIOO, OIOOO, IOOOO, Undefined_funct5 };

//3桁のfunct
enum funct3 { OOI, OIO, IOO, OOO, Undefined_funct3 };

//オペコードの識別
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

//5桁のfunctの識別
enum funct5 identify_funct5(unsigned int num32) {
    switch(cut(num32, 28, 24)) {
        case 1: return OOOOI;
        case 2: return OOOIO;
        case 4: return OOIOO;
        case 8: return OIOOO;
        case 16: return IOOOO;
        default: return Undefined_funct5;
    }
}

//3桁のfunctの識別
enum funct3 identify_funct3(unsigned int num32) {
    switch(cut(num32, 28, 26)) {
        case 1: return OOI;
        case 2: return OIO;
        case 4: return IOO;
        case 0: return OOO;
        default: return Undefined_funct3;
    }
}

// 命令の種類を調べる
enum nemonic identify(unsigned int num32) {
    switch(identify_opecode(num32)) {   //オペコードの識別
        case OOO_op:    switch(identify_funct5(num32)) {    //functの識別
                            case OOOOI: return ADD;
                            case OOOIO: return SUB;
                            case OOIOO: return SLL;
                            case OIOOO: return SRL;
                            case IOOOO: return SRA;
                            default: return UNDEFINED;
                        }
        case OOI_op:    switch(identify_funct5(num32)) {
                            case OOOOI: return ADDI;
                            case OOIOO: return SLLI;
                            case OIOOO: return SRLI;
                            case IOOOO: return SRAI;
                            default: return UNDEFINED;
                        }
                        return UNDEFINED;
        case OIO_op:    switch(identify_funct5(num32)) {
                            case OOOOI: return FADD;
                            case OOOIO: return FSUB;
                            case OOIOO: return FMUL;
                            case OIOOO: return FDIV;
                            default: return UNDEFINED;
                        }
        case IOO_op:    switch(identify_funct3(num32)) {
                            case OOI: return BEQ;
                            case OIO: return BLT;
                            case IOO: return BLE;
                            default: return UNDEFINED;
                        }
        case IOI_op:    switch(identify_funct3(num32)) {
                            case OOO: return J;
                            case OOI: return JR;
                            default: return UNDEFINED;
                        }
        case III_op:    switch(identify_funct3(num32)) {
                            case OOO: return LW;
                            default: return UNDEFINED;
                        }
        case IIO_op:    switch(identify_funct3(num32)) {
                            case OOO: return SW;
                            default: return UNDEFINED;
                        }
        default:  return UNDEFINED;
    }
}

// 命令の種類と、各ブロック(引数に用いる)の内容を調べる
op_set decord(unsigned int num32) {
    op_set op;
    op.nemonic = identify(num32);
    op.dest = cut(num32, 23, 16);
    op.src1 = cut(num32, 15, 8);
    op.src2 = cut(num32, 7, 0);
    op.imm10 = cut(num32, 25, 16);
    op.imm26 = cut(num32, 25, 0);
    return op;
}