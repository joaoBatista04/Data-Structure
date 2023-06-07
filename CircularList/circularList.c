#include <stdio.h>
#include <stdlib.h>
#include "circularList.h"

#define MAX_LIST 5

typedef struct Node{
    data_type value;
    struct Node *next;
    struct Node* prev;
} Node;

Node *node_construct(data_type value, Node *next, Node *prev){
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->next = next;
    node->prev = prev;

    return node;
}

void node_destroy(Node *node){
    free(node);
}

struct CircularList{
    Node *head;
    Node *last;
    int size;
};

CircularList *circular_list_create(){
    CircularList *list = (CircularList *)malloc(sizeof(CircularList));

    list->head = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void circular_list_push_front(CircularList *circular, data_type value){
    if(circular->size == MAX_LIST){
        exit(1);
    }

    if(!circular->size){
        Node *node = node_construct(value, NULL, NULL);

        node->next = node;
        node->prev = node;

        circular->head = node;
        circular->last = node;
    }

    else{
        Node *node = node_construct(value, circular->head, circular->last);

        circular->head->prev = node;
        circular->head = node;
        circular->last->next = node;
    }

    circular->size++;
}

data_type circular_list_pop_back(CircularList *circular){
    data_type value;

    if(!circular->size){
        exit(1);
    }

    if(circular->size <= 1){
        value = circular->head->value;
        
        node_destroy(circular->head);

        circular->head = NULL;
        circular->last = NULL;
    }

    else{
        Node *last = circular->last;

        last->prev->next = circular->head;
        circular->head->prev = last->prev;
        circular->last = last->prev;

        value = last->value;
        node_destroy(last);

        if(circular->size == 2){
            circular->head = circular->last;
        }
    }

    circular->size--;

    return value;
}

void circular_list_print(CircularList *circular, void (*print_fn)(data_type)){
    Node *aux = circular->head;

    if(circular->head == circular->last && circular->head != NULL){
        printf("[%d]\n", circular->head->value);
    }

    else{
        printf("[");
        while(aux != circular->last){
            printf("%d, ", aux->value);

            aux = aux->next;
        }
        if(circular->last != NULL){
            printf("%d", circular->last->value);
        }
        printf("]\n");
    }
}

int circular_list_isEmpty(CircularList *circular){
    if(!circular->size){
        return 1;
    }

    else{
        return 0;
    }
}
void circular_list_destroy(CircularList *circular){
    data_type garbage = 0;

    for(int i = 0; i < circular->size; i++){
        garbage = circular_list_pop_back(circular);
    }

    free(circular);
}