#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"

typedef struct List{
    Node *head;
    Node *last;
    int size;
} List;

/**
 * @brief Construct a new double linked list object
 *  Allocates memory for a new double linked list and returns a pointer to it.
 * @return List*
 * Pointer to the newly allocated double linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the double linked list using list_destroy().
 *
 */
List *list_construct(){
    List *list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;
    list->last = NULL;

    return list;
}

/**
 * @brief Returns the size of the double linked list.
 *  Returns the number of nodes in the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @return int
 * Number of nodes in the double linked list.
 *
 */
int list_size(List *l){
    return l->size;
}

/**
 * @brief Returns the head of the double linked list.
 *  Returns the node pointer of the doubly linked list head.
 * @param l
 * Pointer to the double linked list.
 * @return void*
 * Node pointer of the doubly linked list head.
 *
 */
void *list_return_head(List *l){
    return l->head;
}

/**
 * @brief Returns the last node of the double linked list.
 *  Returns the node pointer of the doubly linked list last node.
 * @param l
 * Pointer to the double linked list.
 * @return void*
 * Node pointer of the doubly linked list last node.
 *
 */
void *list_return_last(List *l){
    return l->last;
}

/**
 * @brief Pushes a new node to the front of the double linked list.
 *  Allocates memory for a new node and inserts it at the front of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param data
 * Pointer to the data to be stored in the new node.
 *
 */
void list_push_front(List *l, data_type data){
    Node *next = l->head;
    Node *prev = NULL;

    Node *aux = node_construct(data, prev, next);
    
    if(l->size > 0){
        l->head->prev = aux;
    }

    l->head = aux;
    l->size++;

    if(l->size == 1){
        l->last = l->head;
    }
}

/**
 * @brief Pushes a new node to the back of the double linked list.
 *
 * @param l
 * Pointer to the double linked list.
 * @param data
 * data to be stored in the new node.
 */
void list_push_back(List *l, data_type data){
    Node *new_node = node_construct(data, l->last, NULL);

    if(l->last != NULL){
        l->last->next = new_node;
    }

    else{
        l->head = new_node;
    }

    l->last = new_node;

    l->size++;
}

/**
 * @brief Remove the first node of the double linked list and returns its data.
 * @param l
 * Pointer to the double linked list.
 * @return data_type
 * Pointer to the data stored in the first node of the double linked list that was removed.
 *
 */
data_type list_pop_front(List *l){   
    if(l->head == NULL){
        exit(printf("Error: list is empty"));
    }

    data_type valueReturned = l->head->value;

    Node *aux = l->head;

    l->head = aux->next;
    
    if(l->size > 1){
        l->head->prev = NULL;
    }

    node_destroy(aux);

    l->size--;

     if(l->size < 1){
        l->last = l->head;
    }

    return valueReturned;
}

/**
 * @brief Remove the last node of the double linked list and returns its data.
 * @param l
 * Pointer to the double linked list.
 * @return data_type
 * Data stored in the last node of the double linked list that was removed.
 */
data_type list_pop_back(List *l){
    if(l->size == 0){
        exit(1);
    }

    Node *node_to_remove = l->last;
    data_type dataReturn = node_to_remove->value;

    l->last = l->last->prev;

    if(l->last != NULL){
        l->last->next = NULL;
    }

    else{
        l->head = NULL;
    }

    node_destroy(node_to_remove);
    l->size--;

    return dataReturn;
}

/**
 * @brief Print the elements of the double linked list.
 *  Print the elements of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 *
 */
void list_print(List *l, void (*print_fn)(data_type)){
    Node *aux = l->last;

    printf("[");
    while(aux != NULL){
        print_fn(aux->value);
        
        if(aux->next != NULL){
            printf(", ");
        }
        aux = aux->prev;
    }
    printf("]");
}

/**
 * @brief Print the elements of the double linked list in reverse form.
 *  Print the elements of the double linked list in reverse form.
 * @param l
 * Pointer to the double linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 *
 */
void list_print_reverse(List *l, void (*print_fn)(data_type)){
    Node *aux = l->last;

    printf("[");
    while(aux != NULL){
        print_fn(aux->value);
        
        if(aux->prev != NULL){
            printf(", ");
        }
        aux = aux->prev;
    }
    printf("]");
}

/**
 * @brief Destroys the double linked list.
 *  Frees the memory allocated for the double linked list and all its nodes.
 * @param l
 * Pointer to the double linked list.
 *
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