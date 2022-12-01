#ifndef _PRINT_H_
#define _PRINT_H_

#include "register.h"
#include "decorder.h"

#define NEW_LINE 8  // 改行までに表示する要素の数

// レジスタファイルの内容表示
void print_reg(reg_set*);

// メモリ内容の表示
// start, end でそれぞれ表示を開始する行、終了する行を指定
void print_mem(reg_set*, int, int);

void print_ro(reg_set*, op_set*);

#endif