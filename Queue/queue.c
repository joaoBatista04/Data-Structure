#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

typedef struct Queue{
    List *list;
    int size;
} Queue;

Queue *queue_construct(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->list = list_construct();
    queue->size = 0;

    return queue;
}

void queue_enqueue(Queue *queue, data_type value){
    list_push_front(queue->list, value);
    queue->size++;
}

data_type queue_dequeue(Queue *queue){
    data_type val;

    val = list_pop_back(queue->list);
    queue->size--;

    return val;
}

int queue_empty(Queue *queue){
    if(!queue->size){
        return 1;
    }

    else{
        return 0;
    }
}

void queue_destroy(Queue *queue){
    list_destroy(queue->list);

    free(queue);
}