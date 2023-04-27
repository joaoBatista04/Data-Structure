#include <stdio.h>
#include "node.h"

int main(){
    Node *n = node_construct(5, NULL);
    Node *n1 = node_construct(3, n);
    Node *n2 = node_construct(1, n1);

    printf("%d\n", n2->next->next->value);
    printf("%d\n", n2->next->next->next);
    //printf("%d\n", n2->next->next->next->value); <-- SEGFAULT

    //Exercicio 1:
    printf("\n\nExercício 1\n");
    Node *anyNode = node_construct(1, NULL);
    printf("%d\n", anyNode->value);

    //Exercício 2:
    printf("\n\nExercício 2\n");
    Node *no = node_construct(5, NULL);
    Node *no1 = node_construct(3, no);
    Node *no2 = node_construct(1, no1);

    printf("%d\n", no->value);
    printf("%d\n", no1->value);
    printf("%d\n", no2->value);

    //Exercício 3:
    printf("\n\nExercício 3\n");
    Node *aux;

    for(int i = 0; i < 10; i++){
        n = node_construct(i + 1, n);
    }

    aux = n;
    for(int j = 0; j < 10; j++){
        printf("%d\n", aux->value);
        aux = aux->next;
    }

    //Exercício 4:
    //Construindo uma lista de nos. Nao tem problema em os nos terem o mesmo nome, pois eles apontam para enderecos especificos
    Node *n = NULL;

    for(int i = 10; i >= 0; i--){
        n = node_construct(i, n);
    }

    //Para nao perder a referencia dos nos da frente, cria-se um no auxiliar
    Node *head = n;

    //Printando o valor e acessando os proximos valores da lista
    while(n != NULL){
        printf("%d\n", n->value);
        n = n->next;
    }

    return 0;
}