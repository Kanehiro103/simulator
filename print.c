#include "print.h"
#include "register.h"
#include <stdio.h>

// レジスタファイルの内容表示
void print_reg(reg_set* rs) {
    int i, j;
    printf("\nreg:\n");
    for(i = 0; i * NEW_LINE < REG_SIZE; i++) {
        printf("%10d ", i);
        for(j = 0; j < NEW_LINE; j++) {
            printf("%08x ", rs->reg[i * NEW_LINE + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// メモリの内容表示
// start, end でそれぞれ表示を開始する行、終了する行を指定
void print_mem(reg_set* rs, int start, int end) {
    long i;
    int j;
    printf("\nmem:\n");
    for(i = start; i <= end && i * NEW_LINE < MEM_SIZE; i++) {
        printf("%10ld ", i);
        for(j = 0; j < NEW_LINE; j++) {
            printf("%08x ", rs->mem[i * NEW_LINE + j]);
        }
        printf("\n");
    }
    printf("\n");
}