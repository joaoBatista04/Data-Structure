#ifndef NODE_H
#define NODE_H

typedef int data_type;

typedef struct Node{
    data_type value;
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
Node *node_construct(data_type value, Node *next);

/**
 * @brief Freeing memory from a node pointer
 * 
 * @param n 
 */
void node_destroy(Node *n);

/**
 * @brief Returning the next node adress
 * 
 * @param node 
 * @return Node* 
 */
Node *node_return_next(Node *node);

/**
 * @brief Returning the node value (data_type)
 * 
 * @param node 
 * @return data_type 
 */
data_type node_return_data(Node *node);

#endif