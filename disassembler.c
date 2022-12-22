#include "disassembler.h"
#include "decorder.h"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int disassemble(char* fname) {
    FILE* fpin;
    FILE* fpout;
    char fin[128];
    char fout[128];
    char* samples = "./samples/";
    char* dat = ".dat";
    char* asms = "./asms/";
    char* s = ".s";
    char str[BUFFER_SIZE];
    char* endptr;
    int i = 0;

    sprintf(fin, "%s%s%s", samples, fname, dat);
    sprintf(fout, "%s%s%s", asms, fname, s);

    fpin = fopen(fin, "r");
    if(fpin == NULL) {
        return 1;
    }
    fpout = fopen(fout, "w");
    if(fpout == NULL) {
        return 1;
    }

    while(fgets(str, BUFFER_SIZE, fpin) != NULL) {
        unsigned int num32 = (unsigned int)strtol(str, &endptr, 16);
        if(*endptr == '\r' || *endptr == '\n') {
            op_set op = decord(num32);
            switch(op.nemonic) {
                case ADD:   fprintf(fpout, "%8d: add r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case SUB:   fprintf(fpout, "%8d: sub r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case SLL:   fprintf(fpout, "%8d: sll r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case SRL:   fprintf(fpout, "%8d: srl r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case SRA:   fprintf(fpout, "%8d: sra r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case FISPOS:   fprintf(fpout, "%8d: fispos r%u r%u\n", i, op.dest, op.src2); break;
                case FISNEG:   fprintf(fpout, "%8d: fisneg r%u r%u\n", i, op.dest, op.src2); break;
                case FNEG:  fprintf(fpout, "%8d: fneg r%u r%u\n", i, op.dest, op.src2); break;
                case ADDI:  fprintf(fpout, "%8d: addi r%u r%u %u\n", i, op.dest, op.src1, op.src2); break;
                case SUBI:  fprintf(fpout, "%8d: subi r%u r%u %u\n", i, op.dest, op.src1, op.src2); break;
                case SLLI:  fprintf(fpout, "%8d: slli r%u r%u %u\n", i, op.dest, op.src1, op.src2); break;
                case SRLI:  fprintf(fpout, "%8d: srli r%u r%u %u\n", i, op.dest, op.src1, op.src2); break;
                case SRAI:  fprintf(fpout, "%8d: srai r%u r%u %u\n", i, op.dest, op.src1, op.src2); break;
                case FADD:  fprintf(fpout, "%8d: fadd r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case FSUB:  fprintf(fpout, "%8d: fsub r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case FMUL:  fprintf(fpout, "%8d: fmul r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case FDIV:  fprintf(fpout, "%8d: fdiv r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case FLESS: fprintf(fpout, "%8d: fless r%u r%u r%u\n", i, op.dest, op.src1, op.src2); break;
                case FTOI:  fprintf(fpout, "%8d: ftoi r%u r%u\n", i, op.dest, op.src2); break;
                case ITOF:  fprintf(fpout, "%8d: itof r%u r%u\n", i, op.dest, op.src2); break;
                case FSQRT: fprintf(fpout, "%8d: fsqrt r%u r%u\n", i, op.dest, op.src2); break;
                case BEQ:   fprintf(fpout, "%8d: beq r%u r%u %d\n", i, op.src1, op.src2, to_signed(op.imm10, 10)); break;
                case BLT:   fprintf(fpout, "%8d: blt r%u r%u %d\n", i, op.src1, op.src2, to_signed(op.imm10, 10)); break;
                case BLE:   fprintf(fpout, "%8d: ble r%u r%u %d\n", i, op.src1, op.src2, to_signed(op.imm10, 10)); break;
                case J:     fprintf(fpout, "%8d: j %d\n", i, to_signed(op.imm26, 26)); break;
                case JR:    fprintf(fpout, "%8d: jr r%u\n", i, op.src2); break;
                case LW:    fprintf(fpout, "%8d: lw r%u r%u\n", i, op.dest, op.src2); break;
                case SW:    fprintf(fpout, "%8d: sw r%u r%u\n", i, op.src1, op.src2); break;
                default:    fprintf(fpout, "%8d: nop\n", i); break;
            }
            i++;
        }  
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}