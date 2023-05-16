#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

typedef struct Queue{
    List *list;
    int size;
} Queue;

/**
 * @brief This function builds a Queue pointer and allocate memory for it
 * 
 * @return Queue* 
 */
Queue *queue_construct(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->list = list_construct();
    queue->size = 0;

    return queue;
}

/**
 * @brief This function adds an value to the begin of the Queue
 * 
 * @param queue 
 * @param value 
 */
void queue_enqueue(Queue *queue, data_type value){
    list_push_front(queue->list, value);
    queue->size++;
}

/**
 * @brief This functions removes the value at the end of the Queue and returns this value
 * 
 * @param queue 
 * @return data_type 
 */
data_type queue_dequeue(Queue *queue){
    data_type val;

    val = list_pop_back(queue->list);
    queue->size--;

    return val;
}

/**
 * @brief This function returns 1 if the Queue is empty and 0 if the Queue contains at least one value
 * 
 * @param queue 
 * @return int 
 */
int queue_empty(Queue *queue){
    if(!queue->size){
        return 1;
    }

    else{
        return 0;
    }
}

/**
 * @brief This function frees the memory allocated to a Queue and its attributes
 * 
 * @param queue 
 */
void queue_destroy(Queue *queue){
    list_destroy(queue->list);

    free(queue);
}