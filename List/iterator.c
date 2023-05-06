#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"
#include "iterator.h"

typedef struct ListIterator{
    Node *current;
} ListIterator;

// cria um iterador para percorrer a lista do início para o final.
ListIterator *list_front_iterator(List *l){
    ListIterator *it = (ListIterator *)malloc(sizeof(ListIterator));

    it->current = (Node *)list_return_head(l);

    return it;
}

// cria um iterador para percorrer a lista do final para o início.
ListIterator *list_back_iterator(List *l){
    ListIterator *it = (ListIterator *)malloc(sizeof(ListIterator));

    it->current = (Node *)list_return_last(l);

    return it;
}

// retorna o elemento do nó atual e move o iterador para o próximo nó.
data_type *list_iterator_next(ListIterator *it){
    data_type *data = (int *)&(it->current->value);

    it->current = it->current->next;

    return data;
}

// retorna o elemento do nó atual e move o iterador para o nó anterior.
data_type *list_iterator_previous(ListIterator *it){
    data_type *data = (int *)&(it->current->value);

    it->current = it->current->prev;

    return data;
}

// verifica se o iterador chegou ao final da lista
Bool list_iterator_is_over(ListIterator *it){
    Bool condition;

    if(it->current == NULL){
        return condition = 1;
    }

    else{
        return condition = 0;
    }
}

// libera a memória alocada para o iterador
void list_iterator_destroy(ListIterator *it){
    free(it);
}