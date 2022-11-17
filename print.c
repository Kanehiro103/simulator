#include "print.h"
#include <stdio.h>

// プログラムカウンタ・レジスタ・命令実行回数を表示する
void print_reg(reg_set* reg) {
    int i, j;

    // プログラムカウンタ
    printf("\npc : %d\n", reg->pc);

    // レジスタ
    printf("\nreg:\n");
    for(i = 0; i * NEW_LINE < REGISTER_SIZE; i++) {
        printf("%10d ", i);
        for(j = 0; j < NEW_LINE; j++) {
            printf("%08x ", reg->reg[i * NEW_LINE + j]);
        }
        printf("\n");
    }
    printf("\n");

    // 命令実行回数
    printf("count: %d\n\n", reg->count);
}

// メモリを表示する
// 第二・第三引数で表示する行の初めと終わりを指定
void print_mem(reg_set* reg, int start, int end) {
    int i, j;
    printf("\nmem:\n");
    for(i = start; i <= end && i * NEW_LINE < MEMORY_SIZE; i++) {
        printf("%10d ", i);
        for(j = 0; j < NEW_LINE; j++) {
            printf("%08x ", reg->mem[i * NEW_LINE + j]);
        }
        printf("\n");
    }
    printf("\n");
}