#ifndef _ERROR_H_
#define _ERROR_H_

// (op x1 x2) のシミュレート結果と実際の (op x1 x2) との相対誤差
float fadd_rerror(unsigned int, unsigned int);
float fsub_rerror(unsigned int, unsigned int);
float fmul_rerror(unsigned int, unsigned int);
float fdiv_rerror(unsigned int, unsigned int);
float fsqrt_rerror(unsigned int);

// (op x1 x2) のシミュレート結果と実際の (op x1 x2) との絶対誤差
// 真の答えがゼロに近い(と予想される)場合はこちらを使う
float fadd_aerror(unsigned int, unsigned int);
float fsub_aerror(unsigned int, unsigned int);
float fmul_aerror(unsigned int, unsigned int);
float fdiv_aerror(unsigned int, unsigned int);
float fsqrt_aerror(unsigned int);

#endif