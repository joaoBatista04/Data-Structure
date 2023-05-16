
#ifndef _STACK_H_
#define _STACK_H_

typedef int data_type;
typedef struct Stack Stack;

/**
 * @brief This function builds a Stack type and allocates memory for it
 * 
 * @return Stack* 
 */
Stack *stack_construct();

/**
 * @brief This function adds a new value to the top of the Stack
 * 
 * @param stack 
 * @param val 
 */
void stack_push(Stack *stack, data_type val);

/**
 * @brief This function removes the value at the top of the Stack
 * 
 * @param stack
 * @return data_type 
 */
data_type stack_pop(Stack *stack);

/**
 * @brief This function returns 1 if the Stack is empty and 0 if the Stack contains at least one value
 * 
 * @param stack 
 * @return int 
 */
int stack_empty(Stack *stack);

/**
 * @brief This function frees the memory allocated to a Stack
 * 
 * @param stack
 */
void stack_destroy(Stack *stack);

#endif