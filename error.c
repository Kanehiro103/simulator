#include "error.h"
#include "fpu.h"
#include "library.h"
#include <math.h>

// (fadd x1 x2) のシミュレート結果と、実際の x1 + x2 の相対誤差
float fadd_rerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) + to_float(x2);
    float ans = to_float(fadd_num(x1, x2));
    return (ans - f) / f;
}

// (fsub x1 x2) のシミュレート結果と、実際の x1 - x2 の相対誤差
float fsub_rerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) - to_float(x2);
    float ans = to_float(fsub_num(x1, x2));
    return (ans - f) / f;
}

// (fmul x1 x2) のシミュレート結果と、実際の x1 * x2 の相対誤差
float fmul_rerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) * to_float(x2);
    float ans = to_float(fmul_num(x1, x2));
    return (ans - f) / f;
}

// (fdiv x1 x2) のシミュレート結果と、実際の x1 / x2 の相対誤差
float fdiv_rerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) / to_float(x2);
    float ans = to_float(fdiv_num(x1, x2));
    return (ans - f) / f;
}

float fsqrt_rerror(unsigned int x2) {
    float f = sqrtf(to_float(x2));
    float ans = to_float(fsqrt_num(x2));
    return (ans - f) / f;
}

// (fadd x1 x2) のシミュレート結果と、実際の x1 + x2 の絶対誤差
float fadd_aerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) + to_float(x2);
    float ans = to_float(fadd_num(x1, x2));
    return ans - f;
}

// (fsub x1 x2) のシミュレート結果と、実際の x1 - x2 の絶対誤差
float fsub_aerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) - to_float(x2);
    float ans = to_float(fsub_num(x1, x2));
    return ans - f;
}

// (fmul x1 x2) のシミュレート結果と、実際の x1 * x2 の絶対誤差
float fmul_aerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) * to_float(x2);
    float ans = to_float(fmul_num(x1, x2));
    return ans - f;
}

// (fdiv x1 x2) のシミュレート結果と、実際の x1 / x2 の絶対誤差
float fdiv_aerror(unsigned int x1, unsigned int x2) {
    float f = to_float(x1) / to_float(x2);
    float ans = to_float(fdiv_num(x1, x2));
    return ans - f;
}

float fsqrt_aerror(unsigned int x2) {
    float f = sqrtf(to_float(x2));
    float ans = to_float(fsqrt_num(x2));
    return ans - f;
}