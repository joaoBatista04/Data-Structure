#ifndef CIRCULAR_H
#define CIRCULAR_H

typedef int data_type;
typedef struct CircularFL CircularFL;

CircularFL* circular_fl_create();
void circular_fl_push_front(CircularFL *circular, data_type value);
data_type circular_fl_pop_back(CircularFL *circular);
void circular_fl_print(CircularFL *circular, void (*print_fn)(data_type));
int circular_fl_isEmpty(CircularFL *circular);
void circular_fl_destroy(CircularFL *circular);

#endif