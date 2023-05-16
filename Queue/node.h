#ifndef _NODE_H_
#define _NODE_H_

typedef int data_type;

typedef struct Node
{
    data_type value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Node Node;

/**
 * @brief Memory allocation for a node pointer and assigning a value and another pointer adress to this node
 * 
 * @param value 
 * @param next 
 * @return Node* 
 */
Node *node_construct(data_type value, Node *prev, Node *next);

/**
 * @brief Freeing memory from a node pointer
 * 
 * @param n 
 */
void node_destroy(Node *n);

/**
 * @brief This function prints the value of the node on the screen. Needs a function pointer that tells how to print this value
 * 
 * @param l 
 * @param print_fn 
 */
void node_print(Node *l, void (*print_fn)(data_type));

#endif