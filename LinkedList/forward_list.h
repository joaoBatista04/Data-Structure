#ifndef _FORWARD_forward_list_H_
#define _FORWARD_forward_list_H_
#include "node.h"

typedef struct forwardList{
    int size;
    Node *head;
} ForwardList;

// cria uma lista
ForwardList* forward_list_construct();
// retorna o número de elementos na lista
int forward_list_size(ForwardList* l);
// adiciona um item no início da lista
void forward_list_push_front(ForwardList* l, data_type val);
// mostra a lista na tela
void forward_list_print(ForwardList* l, void (*print_fn)(data_type));
// retorna o i-ésimo elemento da lista
data_type forward_list_get(ForwardList* l, int i);
// remove o primeiro elemento
data_type forward_list_pop_front(ForwardList* l);
// retorna uma lista contendo o reverso de outra
ForwardList* forward_list_reverse(ForwardList* l);

#endif