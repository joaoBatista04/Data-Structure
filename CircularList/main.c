#include <stdio.h>
#include <string.h>
#include "circularList.h"

void print_fn(data_type value){
    printf("%d", value);
}

int main(){
    CircularFL *l = circular_fl_create();

    int qtd;
    scanf("%d\n", &qtd);

    char op[5];
    int value;
    for(int i = 0; i < qtd; i++){
        scanf("%*c%s", op);

        if(!strcmp(op, "pop")){
            printf("%d\n", circular_fl_pop_back(l));
        }

        else{
            scanf("%d", &value);
            circular_fl_push_front(l, value);
        }

        //circle_fl_print(l, print_fn);
    }

    circular_fl_destroy(l);

    return 0;
}