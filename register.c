#include "register.h"
#include <stdlib.h>

// レジスタ・メモリの領域確保及び初期化(ゼロクリア)
void init_rs(reg_set* rs) {
    rs->count = 0;
    rs->pc = 0;
    rs->reg = (unsigned int*)calloc(REG_SIZE, sizeof(unsigned int));
    rs->mem = (unsigned int*)calloc(MEM_SIZE, sizeof(unsigned int));
}

// 領域の解放
void free_rs(reg_set* rs) {
    free(rs->reg);
    free(rs->mem);
    free(rs);
}

// レジスタの値を読み出す
unsigned int reg_fetch(reg_set* rs, unsigned int src) {
    return rs->reg[src];
}

// メモリの値を読み出す
unsigned int mem_fetch(reg_set* rs, unsigned int src) {
    return rs->mem[src];
}

// レジスタに書き込む
void reg_write(reg_set* rs, unsigned int dest, unsigned int num) {
    rs->reg[dest] = num;
}

// メモリに書き込む
void mem_write(reg_set* rs, unsigned int addr, unsigned int num) {
    rs->mem[addr] = num;
}