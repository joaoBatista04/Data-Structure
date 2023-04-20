#include <stdio.h>
#include "forward_list.h"

void print_data_type(int value){
    printf("%d", value);
}

int main(){
    /*ForwardList *fw = forward_list_construct();

    forward_list_push_front(fw, 2);
    forward_list_push_front(fw, 3);
    forward_list_push_front(fw, 7);

    printf("%d\n", forward_list_get(fw, 0));

    forward_list_pop_front(fw);
    printf("%d\n", forward_list_get(fw, 0));*/

     int n, val;

    ForwardList *l = forward_list_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        forward_list_push_front(l, val);
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        printf("%d\n", forward_list_pop_front(l));

    // test the destroy function
    forward_list_destroy(l);

    return 0;

    return 0;
}