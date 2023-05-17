#include <stdio.h>
#include <stdlib.h>
#include "forward_list.h"
#include "queue.h"

typedef struct Queue{
    ForwardList *forward_list;
    int size;
} Queue;

/**
 * @brief This function builds a Queue pointer and allocate memory for it
 * 
 * @return Queue* 
 */
Queue *queue_construct(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->forward_list = forward_list_construct();
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
    forward_list_push_back(queue->forward_list, value);
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

    val = forward_list_pop_front(queue->forward_list);
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
    forward_list_destroy(queue->forward_list);

    free(queue);
}