#ifndef _EXEC_H_
#define _EXEC_H_

#include "register.h"
#include <stdio.h>

typedef struct {
    FILE* fpl;
    FILE* fpu; 
    FILE* fpi;
} fps;

typedef struct {
    int pflag;
    int lflag;
    int uflag;
} flags;

// 32bitの命令を受け取って実行する
void exec(reg_set*, unsigned int, fps*, int*, flags*);

#endif