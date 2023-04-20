#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "forward_list.h"

// cria uma lista
ForwardList* forward_list_construct(){
    ForwardList *fw = malloc(sizeof(ForwardList));

    fw->size = 0;
    fw->head = NULL;

    return fw;
}

// retorna o número de elementos na lista
int forward_list_size(ForwardList* l){
    return l->size;
}

// adiciona um item no início da lista
void forward_list_push_front(ForwardList* l, data_type val){
    Node *n = node_construct(val, l->head);
    l->head = n;
    l->size++;
}

// mostra a lista na tela
void forward_list_print(ForwardList* l, void (*print_fn)(data_type)){
    Node *aux = l->head;

    printf("[");
    while(aux != NULL){
        print_fn(aux->value);
        
        if(aux->next != NULL){
            printf(", ");
        }
        aux = aux->next;
    }
    printf("]");
}

// retorna o i-ésimo elemento da lista
data_type forward_list_get(ForwardList* l, int i){
    if(i < 0 || i > l->size){
        printf("Error: invalid index.\n");
        exit(1);
    }

    else{
        Node *aux = l->head;

        for(int idx = 0; idx < i; idx++){
            aux = aux->next;
        }

        return aux->value;
    }
}

// remove o primeiro elemento
data_type forward_list_pop_front(ForwardList* l){
    Node *aux = l->head;
    data_type value;

    l->head = aux->next;

    value = aux->value;
    node_destroy(aux);

    return value;
}
// retorna uma lista contendo o reverso de outra
ForwardList* forward_list_reverse(ForwardList* l){
    ForwardList *fw = forward_list_construct();
    Node *aux = l->head;

    for(int i = 0; i < l->size; i++){
        forward_list_push_front(fw, aux->value);
        aux = aux->next;
    }

    return fw;
}

ForwardList* forward_list_reverse_inplace(ForwardList* l){
    Node *current = l->head;
    Node *next = NULL;
    Node *previous = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    l->head = previous;

    return l;
}

void forward_list_destroy(ForwardList *l){

}