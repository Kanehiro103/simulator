#ifndef _DECORDER_H_
#define _DECORDER_H_

// 命令の種類
enum nemonic  {
    ADD,
    SUB,
    SLL,
    SRL,
    SRA,
    ADDI,
    SLLI,
    SRLI,
    SRAI,
    FADD,
    FSUB,
    FMUL,
    FDIV,
    BEQ,
    BLT,
    BLE,
    J,
    JR,
    LW,
    SW,
    UNDEFINED   // 不正なニーモニック
};

// ニーモニックと、各ブロックの内容
typedef struct {
    enum nemonic nemonic;   // ニーモニック
    unsigned int dest;    // [23, 16]
    unsigned int src1;    // [15, 8], src1 or src
    unsigned int src2;    // [7, 0], src2 or imm
    unsigned int imm10;    // [25, 16]
    unsigned int imm26;    // [25, 0]
} op_set;

// 命令の種類と、各ブロックの内容を調べる
op_set decord(unsigned int);

#endif