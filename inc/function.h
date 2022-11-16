#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <math.h>
#include "../inc/matrix.h"
#include "../inc/params.h"

double h_response(double, double, double);
double readback(int _col,double t, double jitter, MATRIX_TYPE (*d)[_col], double SS, double TT, double TLL);

#if 0
Matrix** gen_firtaps_v2(Matrix* random, Matrix *sampled, MATRIX_TYPE* gpr_coeff, int fir_len, char constraint,char method);
Matrix* auto_corr(Matrix *x, int bot, int top);
Matrix* cross_corr(Matrix *x, Matrix *y, int K, int L);
MATRIX_TYPE Caculate_lagrange(Matrix * R_matrix, Matrix* A_matrix, Matrix *T_matrix, Matrix *I_matrix);
Matrix *Caculate_gpr_coeff(Matrix *R_matrix, Matrix *A_matrix, Matrix *T_matrix, Matrix *I_matrix, MATRIX_TYPE lagrange);
Matrix *Caculate_fir_coeff(Matrix *R_matrix, Matrix *T_matrix, Matrix *gpr_coeff);
#endif

#endif
