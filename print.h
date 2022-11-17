#ifndef _PRINT_H_
#define _PRINT_H_

#include "register.h"

// 改行までに表示する要素の数
#define NEW_LINE 8

// プログラムカウンタ・レジスタを表示する
void print_reg(reg_set*);

// メモリを表示する
// 第二・第三引数で行を指定
void print_mem(reg_set*, int, int);   

#endif