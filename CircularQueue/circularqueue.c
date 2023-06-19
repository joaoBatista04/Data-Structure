#include <stdlib.h>
#include "circularqueue.h"

struct CQueue{
    data_type *arr;
    int start;
    int end;
    int size;
    int allocd;
};

const int initial_size = 5;
const int growth_rate = 5;

CQueue *cqueue_constuct(){
    CQueue *cqueue = (CQueue *)malloc(sizeof(CQueue));

    cqueue->arr = (data_type *)malloc(initial_size * sizeof(data_type));

    cqueue->start = 0;
    cqueue->end = 0;
    cqueue->size = 0;
    cqueue->allocd = initial_size;

    return cqueue;
}

void cqueue_push(CQueue *cqueue, data_type value){
    if(cqueue->size == cqueue->allocd){
        data_type *prev = cqueue->arr;

        cqueue->allocd += growth_rate;
        cqueue->arr = (data_type *)calloc(cqueue->allocd, sizeof(data_type));

        int i = cqueue->start;
        int c = 0;

        while(c < cqueue->size){
            cqueue->arr[c] = prev[i];
            i = (i + 1) % cqueue->size;
            c++;
        }

        free(prev);
        cqueue->start = 0;
        cqueue->end = cqueue->size;
    }


    cqueue->arr[cqueue->end] = value;
    cqueue->end = (cqueue->end + 1) % cqueue->allocd;
    cqueue->size++;
}

int cqueue_isEmpty(CQueue *cqueue){
    return cqueue->size == 0;
}

data_type cqueue_pop(CQueue *cqueue){
    data_type val = cqueue->arr[cqueue->start];
    cqueue->start = (cqueue->start + 1) % cqueue->allocd;
    cqueue->size--;

    return val;
}

void cqueue_destroy(CQueue *cqueue){
    free(cqueue->arr);

    free(cqueue);
}