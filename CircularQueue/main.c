#include <stdio.h>
#include "circularqueue.h"

int main(){
    CQueue *cqueue = cqueue_constuct();

    cqueue_push(cqueue, 5);
    cqueue_pop(cqueue);

    cqueue_destroy(cqueue);
    
    return 0;
}