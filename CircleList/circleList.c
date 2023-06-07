#include <stdio.h>
#include <stdlib.h>
#include "circleList.h"

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

struct CircleFL{
    Node *head;
    Node *last;
    int size;
};

CircleFL *circle_fl_create(){
    CircleFL *list = (CircleFL *)malloc(sizeof(CircleFL));

    list->head = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void circle_fl_push_front(CircleFL *circle, data_type value){
    if(circle->size == MAX_LIST){
        exit(1);
    }

    if(!circle->size){
        Node *node = node_construct(value, NULL, NULL);

        node->next = node;
        node->prev = node;

        circle->head = node;
        circle->last = node;
    }

    else{
        Node *node = node_construct(value, circle->head, circle->last);

        circle->head->prev = node;
        circle->head = node;
        circle->last->next = node;
    }

    circle->size++;
}

data_type circle_fl_pop_back(CircleFL *circle){
    data_type value;

    if(!circle->size){
        exit(1);
    }

    if(circle->size <= 1){
        value = circle->head->value;
        
        node_destroy(circle->head);

        circle->head = NULL;
        circle->last = NULL;
    }

    else{
        Node *last = circle->last;

        last->prev->next = circle->head;
        circle->head->prev = last->prev;
        circle->last = last->prev;

        value = last->value;
        node_destroy(last);

        if(circle->size == 2){
            circle->head = circle->last;
        }
    }

    circle->size--;

    return value;
}

void circle_fl_print(CircleFL *circle, void (*print_fn)(data_type)){
    Node *aux = circle->head;

    if(circle->head == circle->last && circle->head != NULL){
        printf("[%d]\n", circle->head->value);
    }

    else{
        printf("[");
        while(aux != circle->last){
            printf("%d, ", aux->value);

            aux = aux->next;
        }
        if(circle->last != NULL){
            printf("%d", circle->last->value);
        }
        printf("]\n");
    }
}

int circle_fl_isEmpty(CircleFL *circle){
    if(!circle->size){
        return 1;
    }

    else{
        return 0;
    }
}
void circle_fl_destroy(CircleFL *circle){
    data_type garbage = 0;

    for(int i = 0; i < circle->size; i++){
        garbage = circle_fl_pop_back(circle);
    }

    free(circle);
}