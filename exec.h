#ifndef _EXEC_H_
#define _EXEC_H_

#include "register.h"
#include <stdio.h>

// 32bitの命令を受け取って実行する
void exec(reg_set*, unsigned int, FILE*, int*);

#endif