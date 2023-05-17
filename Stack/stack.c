#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"

typedef struct Stack{
    Vector *vector;
    int size;
} Stack;

/**
 * @brief This function builds a Stack type and allocates memory for it
 * 
 * @return Stack* 
 */
Stack *stack_construct(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->size = 0;
    stack->vector = vector_construct();

    return stack;
}

/**
 * @brief This function adds a new value to the top of the Stack
 * 
 * @param stack 
 * @param val 
 */
void stack_push(Stack *s, data_type val){
    vector_push_back(s->vector, val);
    s->size++;
}

/**
 * @brief This function removes the value at the top of the Stack
 * 
 * @param stack
 * @return data_type 
 */
data_type stack_pop(Stack *s){
    data_type val;
    val = vector_pop_back(s->vector);
    s->size--;

    return val;
}

/**
 * @brief This function returns 1 if the Stack is empty and 0 if the Stack contains at least one value
 * 
 * @param stack 
 * @return int 
 */
int stack_empty(Stack *s){
    if(!s->size){
        return 1;
    }

    else{
        return 0;
    }
}

/**
 * @brief This function frees the memory allocated to a Stack
 * 
 * @param stack
 */
void stack_destroy(Stack *s){
    vector_destroy(s->vector);

    free(s);
}