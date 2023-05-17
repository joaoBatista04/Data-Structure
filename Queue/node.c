#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *node_construct(data_type value, Node *next){
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = next;

    return node;
}

void node_destroy(Node *node){
    node->next = NULL;

    free(node);
}