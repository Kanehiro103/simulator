#ifndef _REGISTER_H_
#define _REGISTER_H_

#define REGISTER_SIZE 256   // レジスタ数
#define MEMORY_SIZE 1024    // メモリサイズ

// プログラムカウンタ・レジスタ・メモリを表現する構造体
typedef struct {
    unsigned int pc;    // プログラムカウンタ
    unsigned int reg[REGISTER_SIZE];    // レジスタ
    unsigned int mem[MEMORY_SIZE];  // メモリ
    unsigned int count;     // 命令実行回数
} reg_set;

// レジスタのゼロクリア
void init_reg(reg_set*);

// レジスタの値を読み出す
unsigned int reg_fetch(reg_set*, unsigned int);

// メモリの値を読み出す
unsigned int mem_fetch(reg_set*, unsigned int);

// レジスタに書き込む
void reg_write(reg_set*, unsigned int, unsigned int);

// メモリに書き込む
void mem_write(reg_set*, unsigned int, unsigned int); 

#endif