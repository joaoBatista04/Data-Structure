#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_data_type(int value){
    printf("%d", value);
}

int main(){
    List *list = list_construct();

    list_push_front(list, 6);
    list_push_front(list, 10);
    list_push_front(list, 11);

    list_print(list, print_data_type);
}