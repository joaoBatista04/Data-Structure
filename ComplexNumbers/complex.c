#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

typedef struct Complex{
    float real;
    float imaginary;
} Complex;

Complex *complex_create(){
    Complex *complex = (Complex *)malloc(sizeof(Complex));

    float real, imaginary;
    scanf("%f %f", &real, &imaginary);

    complex->real = real;
    complex->imaginary = imaginary;

    return complex;
}

Complex *complex_sum_print(Complex *complex1, Complex *complex2){
    float newReal = complex1->real + complex2->real;
    float newImaginary = complex1->imaginary + complex2->imaginary;
    Complex *sumResult = (Complex *)calloc(1, sizeof(Complex));

    sumResult->imaginary = newImaginary;
    sumResult->real = newReal;

    if(newImaginary > 0){
        complex_print(sumResult);
    }

    else if(newImaginary < 0){
        complex_print(sumResult);     
    }

    else{
        complex_print(sumResult);
    }

    return sumResult;
}

Complex *complex_subtraction_print(Complex *complex1, Complex *complex2){
    float newReal = complex1->real - complex2->real;
    float newImaginary = complex1->imaginary - complex2->imaginary;
    Complex *subtractionResult;

    if(newImaginary > 0){
        complex_print(subtractionResult);
    }

    else if(newImaginary < 0){
        complex_print(subtractionResult);     
    }

    else{
        complex_print(subtractionResult);
    }


    return subtractionResult;
}

void complex_print(Complex *complex){
    if(complex->imaginary > 0){
        printf("%.2f + %.2fi\n", complex->real, complex->imaginary);
    }

    else if(complex->imaginary < 0){
        printf("%.2f %.2fi\n", complex->real, complex->imaginary);        
    }

    else{
        printf("%.2f\n", complex->real);
    }
}

void complex_destroy(Complex *complex){
    complex = NULL;

    free(complex);
}