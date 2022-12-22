#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>

// レジスタの変更内容を格納する構造体
typedef struct {
    unsigned int rm;   // 1:reg  2:mem
    unsigned int flag_pc;   // 0:pc更新なし  1:pc更新あり
    unsigned int flag_rm;    // 0:rm更新なし  1:rm更新あり
    unsigned int addr;  // 変更された場所(デフォルトは0)
    unsigned int before_pc; // 更新前のpc
    unsigned int after_pc;  // 更新後のpc
    unsigned int before_rm;  // 更新前のrm
    unsigned int after_rm;  // 更新後のrm
} change;

// 変更内容の初期化
void init_change(change*);

// 更新のログをファイルに書き込む
// [実行命令回数] [更新部分(pc or reg or mem)] [更新前] [更新後] [アドレス(pc の場合 0)]
void  logger(FILE*, change*, unsigned int);

void uart(FILE*, change*, unsigned int);

#endif