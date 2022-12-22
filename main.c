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
#include "disassembler.h"

int main(int argc, char* argv[]) {
    char* samples = "./samples/";
    char* dat = ".dat";
    char read_file[128];
    char s[16];
    flags flgs;
    flgs.pflag = 0;
    flgs.lflag = 0;
    flgs.uflag = 0;
    fps fps;
    fps.fpl = NULL;
    fps.fpu = NULL;
    int opl = 0;
    int opu = 0;
    int flag = 0;

    if(argc <= 1) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if(strcmp(argv[1], "#disasm") == 0) {
        char fname[128];
        printf("filename? ");
        scanf("%s", fname);
        if(disassemble(fname)) {
            printf("file not found\n");
            exit(1);
        }
    } else {
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
                flgs.pflag = 1;
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
                flgs.lflag = 1;
                break;
            } else if(strcmp(s, "n") == 0) {
                break;
            } else {
                continue;
            }
        }

        while(1) {
            printf("uart?     y/n : ");
            scanf("%s", s);
            if(strcmp(s, "y") == 0) {
                flgs.uflag = 1;
                break;
            } else if(strcmp(s, "n") == 0) {
                break;
            } else {
                continue;
            }
        }

        if(flgs.lflag) {
            char* logfiles = "./logfiles/log_";
            char log_file[128];

            sprintf(log_file, "%s%s%s", logfiles, argv[1], dat);

            fps.fpl = fopen(log_file, "w");
            if(fps.fpl == NULL) {
                printf("faild to open log_file\n");
                exit(1);
            } else {
                opl = 1;
            }
        }

        if(flgs.uflag) {
            char* uartfiles = "./uart/uart_";
            char uart_file[128];

            sprintf(uart_file, "%s%s%s", uartfiles, argv[1], dat);

            fps.fpu = fopen(uart_file, "w");
            if(fps.fpu == NULL) {
                printf("faild to open log_file\n");
                exit(1);
            } else {
                opu = 1;
            }
        }

        while(!flag) {
            exec(rs, rs->mem[rs->pc], &fps, &flag, &flgs);
        }
        print_reg(rs);

        free_rs(rs);

        if(opl) {
            fclose(fps.fpl);
        }

        if(opu) {
            fclose(fps.fpu);
        }
    }

    /*
    union { float f; unsigned int i; } a;

    a.f = 4.0 * 8.0 + 5.0 * 10.0 + 6.0 * 12.0;
    //scanf("%f", &a.f);
    //scanf("%f", &b.f);
    printf("%d\n", ftoi_num(a.i));
    */
    return 0;
}