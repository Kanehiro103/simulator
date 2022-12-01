#include <stdio.h>
#include <stdlib.h>
#include "register.h"
#include "print.h"
#include "exec.h"
#include "read.h"

int main(int argc, char* argv[]) {
    int flag = 0;
    char* samples = "./samples/";
    char* logfiles = "./logfiles/log_";
    char* dat = ".dat";
    char read_file[128];
    char log_file[128];

    if(argc <= 1) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    sprintf(read_file, "%s%s%s", samples, argv[1], dat);
    sprintf(log_file, "%s%s%s", logfiles, argv[1], dat);

    reg_set* rs;
    rs = (reg_set*)malloc(sizeof(reg_set));
    init_rs(rs);

    rs->mem[0xfffffff8] = 1024;

    if(read(rs, read_file)) {
        printf("file not found\n");
        exit(1);
    }

    FILE* fp = fopen(log_file, "w");
    if(fp == NULL) {
        exit(1);
    }

    while(!flag) {
        exec(rs, rs->mem[rs->pc], fp, &flag);
    }
    print_reg(rs);

    free_rs(rs);
    fclose(fp);

    return 0;
}