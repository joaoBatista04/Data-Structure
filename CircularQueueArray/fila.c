
#include <stdlib.h>
#include "fila.h"

struct Fila
{
    int *arr;
    int start;
    int end;
    int size;
    int allocd;
};

const int initial_size = 5;
const int growth_step = 5;

Fila *fila_constroi()
{
    Fila *f = (Fila *)calloc(1, sizeof(Fila));

    f->arr = (int *)calloc(initial_size, sizeof(int));
    f->start = 0;
    f->end = 0;
    f->size = 0;
    f->allocd = initial_size;

    return f;
}

void fila_push(Fila *f, int item)
{
    if (f->size == f->allocd)
    {
        int *prev = f->arr;

        f->allocd = f->allocd + growth_step;
        f->arr = (int *)calloc(f->allocd, sizeof(int));

        int i = f->start;
        int c = 0;

        while (c < f->size)
        {
            f->arr[c] = prev[i];
            i = (i + 1) % f->size;
            c++;
        }

        free(prev);
        f->start = 0;
        f->end = f->size;
    }

    f->arr[f->end] = item;
    f->end = (f->end + 1) % f->allocd;
    f->size++;
}

int fila_empty(Fila *f)
{
    return f->size == 0;
}

int fila_pop(Fila *f)
{
    int val = f->arr[f->start];
    f->start = (f->start + 1) % f->allocd;
    f->size--;
    return val;
}

void fila_destroy(Fila *f)
{
    free(f->arr);
    free(f);
}
