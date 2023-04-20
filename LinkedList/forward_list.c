#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "forward_list.h"

/**
 * @brief This function creates a linked list and allocates memory to it
 * 
 * @return ForwardList* 
 */
ForwardList* forward_list_construct(){
    ForwardList *fw = malloc(sizeof(ForwardList));

    fw->size = 0;
    fw->head = NULL;

    return fw;
}

/**
 * @brief This function returns the linked list size
 * 
 * @param l 
 * @return int 
 */
int forward_list_size(ForwardList* l){
    return l->size;
}

/**
 * @brief This function adds an item to the beginning of the list
 * 
 * @param l 
 * @param val 
 */
void forward_list_push_front(ForwardList* l, data_type val){
    Node *n = node_construct(val, l->head);
    l->head = n;
    l->size++;
}

/**
 * @brief This function prints the linked list values on the screen
 * 
 * @param l 
 * @param print_fn 
 */
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

/**
 * @brief This function returns the i-th element of the linked list
 * 
 * @param l 
 * @param i 
 * @return data_type 
 */
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

/**
 * @brief This function removes the first element from the linked list
 * 
 * @param l 
 * @return data_type 
 */
data_type forward_list_pop_front(ForwardList* l){
    Node *aux = l->head;
    data_type value;

    l->head = aux->next;

    value = aux->value;
    node_destroy(aux);

    return value;
}
/**
 * @brief This function returns a linked list containing the reverse of another
 * 
 * @param l 
 * @return ForwardList* 
 */
ForwardList* forward_list_reverse(ForwardList* l){
    ForwardList *fw = forward_list_construct();
    Node *aux = l->head;

    for(int i = 0; i < l->size; i++){
        forward_list_push_front(fw, aux->value);
        aux = aux->next;
    }

    return fw;
}

/**
 * @brief This function returns the same reversed linked list, without creating a new one
 * 
 * @param l 
 * @return ForwardList* 
 */
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

/**
 * @brief This function frees the memory allocated to the list and its nodes
 * 
 * @param l 
 */
void forward_list_destroy(ForwardList *l){
    Node *current = l->head;
    Node *next;

    while(current != NULL){
        next = current->next;
        node_destroy(current);
        current = next;
    }

    free(l);
}