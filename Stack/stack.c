#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Node{
    data_type value;
    struct Node *next;
} Node;

/**
 * @brief Memory allocation for a node pointer and assigning a value and another pointer adress to this node
 * 
 * @param value 
 * @param next 
 * @return Node* 
 */
Node *node_construct(data_type value, Node *next){
    Node *node = (Node *)malloc(sizeof(Node));
    
    node->value = value;
    node->next = next;

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

typedef struct Stack{
    Node *head;
    int size;
} Stack;

/**
 * @brief This function creates a stack and allocates memory to it
 * 
 * @return Stack* 
 */
Stack* stack_construct(){
    Stack *stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->head = NULL;

    return stack;
}

void stack_push(Stack *s, data_type val){
    
}