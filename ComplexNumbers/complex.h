#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct Complex Complex;

Complex *complex_create();
Complex * complex_sum_print(Complex *complex1, Complex *complex2);
Complex * complex_subtraction_print(Complex *complex1, Complex *complex2);
void complex_print(Complex *complex);
void complex_destroy(Complex *complex);

#endif