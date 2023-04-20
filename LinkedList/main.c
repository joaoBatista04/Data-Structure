#include <stdio.h>
#include "forward_list.h"

void print_data_type(int value){
    printf("%d", value);
}

int main(){
    ForwardList *list = forward_list_construct();

    forward_list_print(list, print_data_type);
    forward_list_destroy(list);

    return 0;
}