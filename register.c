#include "register.h"

//レジスタ内容のゼロクリア
void init_reg(reg_set* reg) {
    int i;
    reg->pc = 0;
    for(i = 0; i < REGISTER_SIZE; i++) {
        reg->reg[i] = 0;
    }
    for(i = 0; i < MEMORY_SIZE; i++) {
        reg->mem[i] = 0;
    }
    reg->count = 0;
}

// レジスタの値を読み出す
unsigned int reg_fetch(reg_set* reg, unsigned int src) {
    return reg->reg[src];
}

// メモリの値を読み出す
unsigned int mem_fetch(reg_set* reg, unsigned int src) {
    return reg->mem[src];
}

// レジスタに書き込む
void reg_write(reg_set* reg, unsigned int dest, unsigned int num) {
    reg->reg[dest] = num;
}

// メモリに書き込む
void mem_write(reg_set* reg, unsigned int addr, unsigned int num) {
    reg->mem[addr] = num;
}