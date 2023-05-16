#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/**
 * @brief Memory allocation for a node pointer and assigning a value and two other pointers adresses to this node
 * 
 * @param value 
 * @param prev
 * @param next 
 * @return Node* 
 */
Node *node_construct(data_type value, Node *prev, Node *next)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = next;
    n->prev = prev;
    return n;
}

/**
 * @brief Freeing memory from a node pointer
 * 
 * @param n 
 */
void node_destroy(Node *n)
{
    free(n);
}

/**
 * @brief This function prints the value of the node on the screen. Needs a function pointer that tells how to print this value
 * 
 * @param l 
 * @param print_fn 
 */
void node_print(Node *n, void (*print_fn)(data_type))
{
    print_fn(n->value);
}