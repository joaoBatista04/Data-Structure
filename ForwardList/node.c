#include <stdio.h>
#include <stdlib.h>
#include "node.h"

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