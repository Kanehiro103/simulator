#ifndef _DECORDER_H_
#define _DECORDER_H_

// 命令の種類
enum nemonic  {
    ADD,    // 算術演算(整数)
    SUB,
    SLL,
    SRL,
    SRA,
    ADDI,
    SUBI,
    SLLI,
    SRLI,
    SRAI,
    FISPOS,
    FISNEG,
    FNEG,
    FADD,   // 算術演算(小数)
    FSUB,
    FMUL,
    FDIV,
    FLESS,
    FTOI,
    ITOF,
    BEQ,    // 分岐
    BLT,
    BLE,
    J,      // ジャンプ
    JR,
    LW,     // メモリアクセス
    SW,
    UNDEFINED   // 不正なニーモニック
};

//オペコード
enum opecode { OOO_op, OOI_op, OIO_op, IOO_op, IOI_op, III_op, IIO_op, Undefined_opecode };  // O = 0, I = 1

//5桁のfunct
enum funct5 { OOOOI, OOOIO, OOIOO, OIOOO, IOOOO, IOOOI, IOOIO, IOIOO, Undefined_funct5 };

//3桁のfunct
enum funct3 { OOI, OIO, IOO, OOO, Undefined_funct3 };

// ニーモニックと、各ブロックの内容
typedef struct {
    enum opecode opecode;   // オペコード
    enum funct5 funct5; // 5桁のfunct
    enum funct3 funct3; // 3桁のfunct
    enum nemonic nemonic;   // ニーモニック
    unsigned int dest;  // [23, 16]
    unsigned int src1;  // [15, 8], src1 or src
    unsigned int src2;  // [7, 0], src2 or imm
    unsigned int imm10; // [25, 16]
    unsigned int imm26; // [25, 0]
} op_set;

// 命令の種類と、各ブロックの内容を調べる
op_set decord(unsigned int);

#endif