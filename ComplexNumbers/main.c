#include <stdio.h>
#include "complex.h"

int main(){
    //complex.h no Makefile

    //Soma de dois numeros complexos
    Complex *n1 = complex_create();
    Complex *n2 = complex_create();

    Complex *soma = complex_sum_print(n1, n2);
    complex_print(soma);

    complex_destroy(n1);
    complex_destroy(n2);

    //Subtracao de dois numeros complexos
    Complex *n3 = complex_create();
    Complex *n4 = complex_create();

    Complex *subtracao = complex_subtraction_print(n1, n4);
    complex_print(subtracao);

    complex_destroy(n3);

    complex_destroy(subtracao);

    return 0;
}