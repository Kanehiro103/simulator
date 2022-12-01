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

void print_id(enum nemonic op) {
    switch(op) {
        case ADD: printf("ADD\n");  break;
        case SUB: printf("SUB\n");  break;
        case SLL: printf("SLL\n");  break;
        case SRL: printf("SRL\n");  break;
        case SRA: printf("SRA\n");  break;
        case ADDI: printf("ADDI\n");  break;
        case SLLI: printf("SLLI\n");  break;
        case SRLI: printf("SRLI\n");  break;
        case SRAI: printf("SRAI\n");  break;
        case FADD: printf("FADD\n");  break;
        case FSUB: printf("FSUB\n");  break;
        case FMUL: printf("FMUL\n");  break;
        case FDIV: printf("FDIV\n");  break;
        case BEQ: printf("BEQ\n");  break;
        case BLT: printf("BLT\n");  break;
        case BLE: printf("BLE\n");  break;
        case J: printf("J\n");  break;
        case JR: printf("JR\n");  break;
        case LW: printf("LW\n");  break;
        case SW: printf("SW\n");  break;
        case UNDEFINED: printf("UNDEFINED\n");  break;
        default: printf("ERROR\n");
    }
}

void print_ro(reg_set* reg, op_set* op) {
    printf("pc: %u\n", reg->pc);
    printf("count: %u\n", reg->count);
    print_id(op->nemonic);
    printf("%u\n", op->dest);
    printf("%u\n", op->src1);
    printf("%u\n", op->src2);
    printf("r0 = %u\n", reg->reg[0]);
    printf("r250 = %u\n", reg->reg[250]);
    printf("r251 = %u\n", reg->reg[251]);
    printf("r252 = %u\n", reg->reg[252]);
    printf("r253 = %u\n", reg->reg[253]);
    printf("r254 = %u\n", reg->reg[254]);
    printf("r255 = %u\n\n", reg->reg[255]);
}