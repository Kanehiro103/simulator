#include "exec.h"
#include "register.h"
#include "decorder.h"
#include "library.h"
#include "alu.h"
#include "log.h"
#include <stdio.h>
 
 // レジスタに変更があったかどうか調べる
void check_chg(change* chg) {
    if(chg->before_pc != chg->after_pc) {
        chg->flag_pc = 1;
    }
    if(chg->before_rm != chg->after_rm) {
        chg->flag_rm = 1;
    }
}

void add(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = add_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void sub(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = sub_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void sll(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = sll_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void srl(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = srl_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void sra(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = sra_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void addi(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);

    // 実行
    unsigned int ans =  addi_num(x1, op->src2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void slli(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);

    // 実行
    unsigned int ans =slli_num(x1, op->src2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void srli(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);

    // 実行
    unsigned int ans = srli_num(x1, op->src2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void srai(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);

    // 実行
    unsigned int ans = srai_num(x1, op->src2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void fadd(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = fadd_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void fsub(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = fsub_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void fmul(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = fmul_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void fdiv(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int ans = fdiv_num(x1, x2);

    // メモリアクセス

    // ライトバック
    reg_write(reg, op->dest, ans);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void beq(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->before_pc = reg->pc;

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int label = reg->pc + to_signed(op->imm10, 10);

    // メモリアクセス

    // ライトバック

    // pc更新
    if(x1 == x2) {
        reg->pc = label;
    } else {
        reg->pc++;
    }

    // 更新チェック
    chg->after_pc = reg->pc;
    check_chg(chg);
}

void ble(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->before_pc = reg->pc;

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int label = reg->pc + to_signed(op->imm10, 10);

    // メモリアクセス

    // ライトバック

    // pc更新
    if((int)x1 <= (int)x2) {
        reg->pc = label;
    } else {
        reg->pc++;
    }

    // 更新チェック
    chg->after_pc = reg->pc;
    check_chg(chg);
}

void blt(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->before_pc = reg->pc;

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src1);
    unsigned int x2 = reg_fetch(reg, op->src2);

    // 実行
    unsigned int label = reg->pc + to_signed(op->imm10, 10);

    // メモリアクセス

    // ライトバック

    // pc更新
    if((int)x1 < (int)x2) {
        reg->pc = label;
    } else {
        reg->pc++;
    }

    // 更新チェック
    chg->after_pc = reg->pc;
    check_chg(chg);
}

void j(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->before_pc = reg->pc;

    // レジスタフェッチ

    // 実行
    unsigned int label = reg->pc + to_signed(op->imm26, 26);

    // メモリアクセス

    // ライトバック

    // pc更新
    reg->pc = label;

    // 更新チェック
    chg->after_pc = reg->pc;
    check_chg(chg);
}

void jr(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->before_pc = reg->pc;

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src2);

    // 実行

    // メモリアクセス

    // ライトバック

    // pc更新
    reg->pc = x1;

    // 更新チェック
    chg->after_pc = reg->pc;
    check_chg(chg);
}

void lw(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 1;
    chg->addr = op->dest;
    chg->before_pc = reg->pc;
    chg->before_rm = reg_fetch(reg, op->dest);

    // レジスタフェッチ
    unsigned int x = reg_fetch(reg, op->src2);

    // 実行

    // メモリアクセス
    unsigned int x1 = mem_fetch(reg, x);

    // ライトバック
    reg_write(reg, op->dest, x1);

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = reg_fetch(reg, op->dest);
    check_chg(chg);
}

void sw(reg_set* reg, op_set* op, change* chg) {
    // 前情報の保存
    chg->rm = 2;
    chg->before_pc = reg->pc;

    // レジスタフェッチ
    unsigned int x1 = reg_fetch(reg, op->src2); // addr
    unsigned int x2 = reg_fetch(reg, op->src1); // num

    // 前情報の保存
    chg->addr = x1;
    chg->before_rm = mem_fetch(reg, x1);

    // 実行

    // メモリアクセス
    mem_write(reg, x1, x2);

    // ライトバック

    // pc更新
    reg->pc++;

    // 更新チェック
    chg->after_pc = reg->pc;
    chg->after_rm = mem_fetch(reg, x1);
    check_chg(chg);
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

// 32bitの命令を受け取って実行する
void exec(reg_set* reg, unsigned int num32, FILE* fp, int* flag) {
    op_set op = decord(num32);
    printf("pc: %u\n", reg->pc);
    printf("count: %u\n", reg->count);
    print_id(op.nemonic);
    printf("%u\n", op.dest);
    printf("%u\n", op.src1);
    printf("%u\n", op.src2);
    printf("r0 = %u\n", reg->reg[0]);
    printf("r95 = %u\n", reg->reg[95]);
    printf("r250 = %u\n", reg->reg[250]);
    printf("r251 = %u\n", reg->reg[251]);
    printf("r252 = %u\n", reg->reg[252]);
    printf("r253 = %u\n", reg->reg[253]);
    printf("r254 = %u\n", reg->reg[254]);
    printf("r255 = %u\n\n", reg->reg[255]);
    change chg;
    init_change(&chg);
    switch(op.nemonic) {
        case ADD:   add(reg, &op, &chg);   break;
        case SUB:   sub(reg, &op, &chg);   break;
        case SLL:   sll(reg, &op, &chg);   break;
        case SRL:   srl(reg, &op, &chg);   break;
        case SRA:   sra(reg, &op, &chg);   break;
        case ADDI:  addi(reg, &op, &chg);   break;
        case SLLI:  slli(reg, &op, &chg);   break;
        case SRLI:  srli(reg, &op, &chg);   break;
        case SRAI:  srai(reg, &op, &chg);   break;
        case FADD:  fadd(reg, &op, &chg);   break;
        case FSUB:  fsub(reg, &op, &chg);   break;
        case FMUL:  fmul(reg, &op, &chg);   break;
        case FDIV:  fdiv(reg, &op, &chg);   break;
        case BEQ:   beq(reg, &op, &chg);    break;
        case BLE:   ble(reg, &op, &chg);    break;
        case BLT:   blt(reg, &op, &chg);  break;
        case J:     j(reg, &op, &chg);  break;
        case JR:    jr(reg, &op, &chg);    break;
        case LW:    lw(reg, &op, &chg);    break;
        case SW:    sw(reg, &op, &chg);    break;
        default: break;
    }
    reg->count++;

    if(chg.flag_pc + chg.flag_rm == 0) {
        reg->count--;
        *flag = 1;
    } else {
        logger(fp, &chg, reg->count);
    }
}