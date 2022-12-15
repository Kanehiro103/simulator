#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "register.h"
#include "print.h"
#include "exec.h"
#include "read.h"
#include "error.h"
#include "fpu.h"
#include "library.h"

int main(int argc, char* argv[]) {
    char* samples = "./samples/";
    char* dat = ".dat";
    char read_file[128];
    char s[16];
    int pflag = 0;
    int lflag = 0;
    FILE* fp = NULL;
    int op = 0;
    int flag = 0;

    if(argc <= 1) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    sprintf(read_file, "%s%s%s", samples, argv[1], dat);

    reg_set* rs;
    rs = (reg_set*)malloc(sizeof(reg_set));
    init_rs(rs);

    rs->mem[0xfffffff8] = 1024;

    if(read(rs, read_file)) {
        printf("file not found\n");
        exit(1);
    }

    while(1) {
        printf("stdout?   y/n : ");
        scanf("%s", s);
        if(strcmp(s, "y") == 0) {
            pflag = 1;
            break;
        } else if(strcmp(s, "n") == 0) {
            break;
        } else {
            continue;
        }
    }

    while(1) {
        printf("logfile?  y/n : ");
        scanf("%s", s);
        if(strcmp(s, "y") == 0) {
            lflag = 1;
            break;
        } else if(strcmp(s, "n") == 0) {
            break;
        } else {
            continue;
        }
    }

    if(lflag) {
        char* logfiles = "./logfiles/log_";
        char log_file[128];

        sprintf(log_file, "%s%s%s", logfiles, argv[1], dat);

        fp = fopen(log_file, "w");
        if(fp == NULL) {
            printf("faild to open log_file\n");
            exit(1);
        } else {
            op = 1;
        }
    }

    while(!flag) {
        exec(rs, rs->mem[rs->pc], fp, &flag, pflag, lflag);
    }
    print_reg(rs);

    free_rs(rs);

    if(op) {
        fclose(fp);
    }

    return 0;
}