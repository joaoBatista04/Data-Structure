#ifndef CIRCULAR_H
#define CIRCULAR_H

typedef int data_type;
typedef struct CircularList CircularList;

CircularList* circular_list_create();
void circular_list_push_front(CircularList *circular, data_type value);
data_type circular_list_pop_back(CircularList *circular);
void circular_list_print(CircularList *circular, void (*print_fn)(data_type));
int circular_list_isEmpty(CircularList *circular);
void circular_list_destroy(CircularList *circular);

#endif