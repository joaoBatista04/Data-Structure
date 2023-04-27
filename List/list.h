#ifndef List_H_
#define List_H_

typedef int data_type;
typedef struct List List;

//This function creates a doubly linked list and allocates memory to it
List* list_construct();
//This function returns the doubly linked list size
int list_size(List* l);
//This function adds an item to the beginning of the doubly linked list
void list_push_front(List* l, data_type val);
//This function prints the doubly linked list values on the screen. This function needs a function pointer that tells how to print the data_type
void list_print(List* l, void (*print_fn)(data_type));
//This function returns the i-th element of the linked list
data_type list_get(List* l, int i);
//This function removes the first element from the linked list
data_type list_pop_front(List* l);
//This function returns a linked list containing the reverse of another
List* list_reverse(List* l);
//This function returns the same reversed linked list, without creating a new one
List* list_reverse_inplace(List* l);
//This function frees the memory allocated to the list and its nodes
void list_destroy(List *l);
//This function concatenates two linked list, adding the second one values at the beginning of the first one
void list_cat(List *list, List *listTwo);
//This function adds an item to the end of the list
void list_push_back(List *l, data_type value);


#endif