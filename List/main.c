
#include <stdio.h>

#include "list.h"

void print_int(data_type data){
    printf("%d", data);
}

int main()
{
    int n, val;

    List *l = list_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        list_push_front(l, val);
    }

    list_push_back(l, 6);
    list_push_back(l, 5);
    list_print(l, print_int);

    printf("\n\n");

    list_pop_back(l);
    list_print(l, print_int);
    
    list_destroy(l);

    return 0;
}