//Numeros pseudoaleatorios sao gerados por uma funcao deterministica

/*#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x = rand();

    printf("%d\n", x);

    resultado encontrado: 1804289383
}*/

//Numeros aleatorios podem ser obtidos setando o divisior N (rand() % N) no tempo de execucao da funcao
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));
    
    int x = rand();

    printf("%d\n", x);
}