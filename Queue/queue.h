#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int data_type;
typedef struct Queue Queue;

/**
 * @brief This function builds a Queue pointer and allocate memory for it
 * 
 * @return Queue* 
 */
Queue *queue_construct();

/**
 * @brief This function adds an value to the begin of the Queue
 * 
 * @param queue 
 * @param value 
 */
void queue_enqueue(Queue *queue, data_type value);

/**
 * @brief This functions removes the value at the end of the Queue and returns this value
 * 
 * @param queue 
 * @return data_type 
 */
data_type queue_dequeue(Queue *queue);

/**
 * @brief This function returns 1 if the Queue is empty and 0 if the Queue contains at least one value
 * 
 * @param queue 
 * @return int 
 */
int queue_empty(Queue *queue);

/**
 * @brief This function frees the memory allocated to a Queue and its attributes
 * 
 * @param queue 
 */
void queue_destroy(Queue *queue);

#endif