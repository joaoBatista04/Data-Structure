#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct CQueue CQueue;
typedef int data_type;

CQueue *cqueue_constuct();
void cqueue_push(CQueue *cqueue, data_type value);
int cqueue_isEmpty(CQueue *cqueue);
data_type cqueue_pop(CQueue *cqueue);
void cqueue_destroy(CQueue *cqueue);

#endif