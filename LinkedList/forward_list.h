#ifndef _FORWARD_forward_list_H_
#define _FORWARD_forward_list_H_
#include "node.h"

typedef struct ForwardList ForwardList;

//This function creates a linked list and allocates memory to it
ForwardList* forward_list_construct();
//This function returns the linked list size
int forward_list_size(ForwardList* l);
//This function adds an item to the beginning of the list
void forward_list_push_front(ForwardList* l, data_type val);
//This function prints the linked list values on the screen. This function needs a function pointer that tells how to print the data_type
void forward_list_print(ForwardList* l, void (*print_fn)(data_type));
//This function returns the i-th element of the linked list
data_type forward_list_get(ForwardList* l, int i);
//This function removes the first element from the linked list
data_type forward_list_pop_front(ForwardList* l);
//This function returns a linked list containing the reverse of another
ForwardList* forward_list_reverse(ForwardList* l);
//This function returns the same reversed linked list, without creating a new one
ForwardList* forward_list_reverse_inplace(ForwardList* l);
//This function frees the memory allocated to the list and its nodes
void forward_list_destroy(ForwardList *l);

#endif