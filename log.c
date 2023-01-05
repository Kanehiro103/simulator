#include "log.h"
#include <stdio.h>

// 変更内容の初期化
void init_change(change* chg) {
    chg->rm = 0;
    chg->flag_pc = 0;
    chg->flag_rm = 0;
    chg->addr = 0;
    chg->before_pc = 0;
    chg->after_pc = 0;
    chg->before_rm = 0;
    chg->after_rm = 0;
}

// 更新のログをファイルに書き込む
// [実行命令回数] [更新部分(pc or reg or mem)] [更新前] [更新後] [アドレス(pc の場合 0)] 
void logger(FILE* fp, change* chg, unsigned int count) {
    // pcの更新ログ
    if(chg->flag_pc) {
        fprintf(fp, "%u %u %u %u %u\n", count, 0, chg->before_pc, chg->after_pc, 0);
    }

    // レジスタ/メモリの更新ログ
    if(chg->flag_rm) {
        fprintf(fp, "%u %u %u %u %u\n", count, chg->rm, chg->before_rm, chg->after_rm, chg->addr);
    }
}

void uart(FILE* fp, change* chg, unsigned int count) {
    if(chg->flag_rm) {
        if(chg->addr == -12) {
            fprintf(fp, "count: %u   data: %x\n",  count, chg->after_rm);
            //printf("count: %u   data: %x\n",  count, chg->after_rm);
        } 
    }
}