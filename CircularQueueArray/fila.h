
#ifndef _FILA_H_
#define _FILA_H_

typedef struct Fila Fila;

Fila *fila_constroi();
void fila_push(Fila *f, int item);
int fila_pop(Fila *f);
int fila_empty(Fila *f);
void fila_destroy(Fila *f);

#endif