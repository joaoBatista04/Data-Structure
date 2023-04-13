#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

double get_timestamp()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec + (((double)now.tv_nsec) / 1e9);
}

int main(){
    srand(time(NULL));
    printf("N menor maior media primeiroElem ultimoElem\n");
    double maior, menor, somador, media, primeiro, ultimo;

    for(int i = 1; i <= 10001; i += 200){
        Vector *vector = vector_construct();

        for(int j = 0; j < i; j++){
            vector_push_back(vector, rand());
        }

        vector_sort(vector);

        for(int k = 0; k < 1000; k++){
            if(k == 0){
                menor = 0;
                maior = 0;
                somador = 0;
            }

            int idx = rand() % i;

            int valor = vector_get(vector, idx);

            double inicio = get_timestamp();
            vector_binary_search(vector, valor);
            double fim = get_timestamp();
            double duracao = fim - inicio;


            if(k == 0){
                menor = duracao;
                somador += duracao;
            }

            else{
                if(duracao < menor){
                    menor = duracao;
                }

                if(duracao > maior){
                    maior = duracao;
                }

                somador += duracao;
            }

            valor = vector_get(vector, 0);
            inicio = get_timestamp();
            vector_binary_search(vector, valor);
            fim = get_timestamp();
            primeiro = fim - inicio;

            valor = vector_get(vector, i);
            inicio = get_timestamp();
            vector_binary_search(vector, valor);
            fim = get_timestamp();
            ultimo = fim - inicio;
        }
        media = somador/1000;

        printf("%d %.7lf %.7lf %.7lf %.7lf %.7lf\n", i, menor, maior, media, primeiro, ultimo);
        vector_destroy(vector);
    }

    return 0;
}