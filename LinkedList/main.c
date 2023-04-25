#include <stdio.h>
#include "forward_list.h"

void print_data_type(int value){
    printf("%d", value);
}

int main(){
    int n, val;

    ForwardList *l = forward_list_construct();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        forward_list_push_front(l, val);
    }

    ForwardList *l2 = forward_list_construct();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        forward_list_push_front(l2, val);
    }

    forward_list_cat(l, l2);

    forward_list_print(l, print_data_type);

    forward_list_destroy(l);
    forward_list_destroy(l2);

    return 0;
}