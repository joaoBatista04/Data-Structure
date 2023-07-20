
#include <stdio.h>
#include <string.h>
#include "fila.h"

int main()
{
    int n, val;
    char op[5];

    Fila *f = fila_constroi();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("\n%s", op);

        if (!strcmp(op, "pop"))
            printf("%d\n", fila_pop(f));
        else
        {
            scanf("%d", &val);
            fila_push(f, val);
        }
    }

    fila_destroy(f);
    return 0;
}