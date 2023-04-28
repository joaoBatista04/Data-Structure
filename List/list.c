#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Node{
    data_type value;
    struct Node *next;
    struct Node *previous;
} Node;

/**
 * @brief Memory allocation for a node pointer and assigning a value and another pointer adress to this node
 * 
 * @param value 
 * @param next 
 * @return Node* 
 */
Node *node_construct(data_type value, Node *next, Node *previous){
    Node *node = (Node *)malloc(sizeof(Node));
    
    node->value = value;
    node->next = next;
    node->previous = previous;

    return node;
}

/**
 * @brief Freeing memory from a node pointer
 * 
 * @param n 
 */
void node_destroy(Node *n){
    free(n);
}

struct List{
    int size;
    Node *head;
    Node *last;
};

/**
 * @brief This function creates a doubly linked list and allocates memory to it
 * 
 * @return List* 
 */
List* list_construct(){
    List *fw = malloc(sizeof(List));

    fw->size = 0;
    fw->head = NULL;

    return fw;
}

/**
 * @brief This function returns the doubly linked list size
 * 
 * @param l 
 * @return int 
 */
int list_size(List* l){
    return l->size;
}

/**
 * @brief This function adds an item to the beginning of the doubly linked list
 * 
 * @param l 
 * @param val 
 */
void list_push_front(List* l, data_type val){
    Node *n = node_construct(val, l->head, NULL);

    if(l->size >= 1){
        l->head->previous = n;
    }

    l->head = n;
    l->size++;

    if(l->size == 1){
        l->last = l->head;
    }
}

/**
 * @brief This function prints the doubly linked list values on the screen. This function needs a function pointer that tells how to print the data_type
 * 
 * @param l 
 * @param print_fn 
 */
void list_print(List* l, void (*print_fn)(data_type)){
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
 * @brief This function returns the i-th element of the doubly linked list
 * 
 * @param l 
 * @param i 
 * @return data_type 
 */
data_type list_get(List* l, int i){
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
 * @brief This function removes the first element from the doubly linked list
 * 
 * @param l 
 * @return data_type 
 */
data_type list_pop_front(List* l){
    data_type value = l->head->value;
    Node *aux = l->head;

    aux->next->previous = NULL;


    l->head = aux->next;

    node_destroy(aux);
    l->size--;

    return value;
}

/**
 * @brief This function frees the memory allocated to the doubly linked list and its nodes
 * 
 * @param l 
 */
void list_destroy(List *l){
    Node *current = l->head;
    Node *next;

    while(current != NULL){
        next = current->next;
        node_destroy(current);
        current = next;
    }

    free(l);
}