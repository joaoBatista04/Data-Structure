#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"

struct List{
    int size;
    Node *head;
    Node *last;
    Node *previous;
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
    fw->last = NULL;
    fw->previous = NULL;

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
 * @brief This function adds an item to the beginning of the list
 * 
 * @param l 
 * @param val 
 */
void list_push_front(List* l, data_type val){
    Node *n = node_construct(val, l->head);
}