#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "forward_list.h"

typedef struct Stack{
    ForwardList *forwardList;
    int size;
} Stack;

// cria uma stack
Stack *stack_construct(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->size = 0;
    stack->forwardList = forward_list_construct();

    return stack;
}

// insere um item na stack
void stack_push(Stack *s, data_type val){
    forward_list_push_front(s->forwardList, val);
    s->size++;
}

// remove o ultimo item inserido e o retorna
data_type stack_pop(Stack *s){
    data_type val;
    val = forward_list_pop_front(s->forwardList);
    s->size--;

    return val;
}

// retorna 1 se a stack está vazia e 0 caso contrário
int stack_empty(Stack *s){
    if(!s->size){
        return 1;
    }

    else{
        return 0;
    }
}

// libera o espaço alocado para a stack
void stack_destroy(Stack *s){
    forward_list_destroy(s->forwardList);

    free(s);
}