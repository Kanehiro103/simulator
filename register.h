#ifndef _REGISTER_H_
#define _REGISTER_H_

#define REG_SIZE 256    // レジスタサイズ
#define MEM_SIZE 4294967296 // メモリサイズ

// レジスタ・メモリを表現する構造体
typedef struct {
    unsigned long count; // 命令実行回数
    unsigned int pc;    // プログラムカウンタ
    unsigned int* reg;  // レジスタファイル
    unsigned int* mem;  // メモリ
} reg_set;

// レジスタ・メモリの領域確保及び初期化(ゼロクリア)
void init_rs(reg_set*);

// 領域の解放
void free_rs(reg_set*);

// レジスタの値を読み出す
unsigned int reg_fetch(reg_set*, unsigned int);

// メモリの値を読み出す
unsigned int mem_fetch(reg_set*, unsigned int);

// レジスタに書き込む
void reg_write(reg_set*, unsigned int, unsigned int);

// メモリに書き込む
void mem_write(reg_set*, unsigned int, unsigned int); 

#endif