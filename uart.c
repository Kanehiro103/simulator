#include "uart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int uart_read(FILE* fp) {
    char* c = ".";
    char buf[16];
    union { float f; unsigned int i; } a;
    if(fp == NULL) {
        return 0;
    } else {
        int eof = fscanf(fp, "%s", buf);
        if(eof == EOF) {
            return 0;
        } else {
            if(strstr(buf, c)) {
                sscanf(buf, "%f", &a.f);
            } else {
                sscanf(buf, "%u", &a.i);
            }
            return a.i;
        }
    }
}