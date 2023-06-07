#include <stdio.h>
#include <string.h>
#include "circularList.h"

void print_fn(data_type value){
    printf("%d", value);
}

int main(){
    CircularList *l = circular_list_create();

    int qtd;
    scanf("%d\n", &qtd);

    char op[5];
    int value;
    for(int i = 0; i < qtd; i++){
        scanf("%*c%s", op);

        if(!strcmp(op, "pop")){
            printf("%d\n", circular_list_pop_back(l));
        }

        else{
            scanf("%d", &value);
            circular_list_push_front(l, value);
        }

        //circle_list_print(l, print_fn);
    }

    circular_list_destroy(l);

    return 0;
}