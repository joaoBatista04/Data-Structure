#ifndef NODE_H
#define NODE_H

typedef int data_type;

typedef struct node{
    data_type value;
    struct node *next;
} Node;

Node *node_construct(data_type value, Node *next);
void node_destroy(Node *n);

#endif