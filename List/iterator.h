#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct ListIterator ListIterator;
typedef unsigned int Bool;

// cria um iterador para percorrer a lista do início para o final.
ListIterator *list_front_iterator(List *l);

// cria um iterador para percorrer a lista do final para o início.
ListIterator *list_back_iterator(List *l);

// retorna o elemento do nó atual e move o iterador para o próximo nó.
data_type *list_iterator_next(ListIterator *it);

// retorna o elemento do nó atual e move o iterador para o nó anterior.
data_type *list_iterator_previous(ListIterator *it);

// verifica se o iterador chegou ao final da lista
Bool list_iterator_is_over(ListIterator *it);

// libera a memória alocada para o iterador
void list_iterator_destroy(ListIterator *it);

#endif