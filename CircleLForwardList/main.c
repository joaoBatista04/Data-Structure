#include <stdio.h>
#include <string.h>
#include "circleList.h"

void print_fn(data_type value){
    printf("%d", value);
}

int main(){
    CircleFL *l = circle_fl_create();

    int qtd;
    scanf("%d\n", &qtd);

    char op[5];
    int value;
    for(int i = 0; i < qtd; i++){
        scanf("%*c%s", op);

        if(!strcmp(op, "pop")){
            printf("%d\n", circle_fl_pop_back(l));
        }

        else{
            scanf("%d", &value);
            circle_fl_push_front(l, value);
        }

        //circle_fl_print(l, print_fn);
    }

    circle_fl_destroy(l);

    return 0;
}