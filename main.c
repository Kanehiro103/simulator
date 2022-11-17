#include "register.h"
#include "read.h"
#include "exec.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int flag = 0;

    FILE* fp = fopen("datalog.txt", "w");
    if(fp == NULL) {
        exit(1);
    }

    reg_set reg;
    init_reg(&reg);

    if(read(&reg, "./samples/fib.dat")) {
        exit(1);
    }

    while(!flag) {
        exec(&reg, reg.mem[reg.pc], fp, &flag);
    }
    print_reg(&reg);

    fclose(fp);
    return 0;
}