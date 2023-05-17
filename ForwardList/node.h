#ifndef NODE_H
#define NODE_H

typedef struct Node{
    data_type value;
    struct Node* next;
} Node;

typedef int data_type;

Node *node_construct(data_type value, Node *next);
void node_destroy(Node *node);

#endif