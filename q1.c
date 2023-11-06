#include <stdio.h>

void preencherArray(int valor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &valor[i]);
    }
}

void imprimirArray(int valor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", valor[i]);

        if (i < tamanho - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    int valor[10];

    preencherArray(valor, 10);

    imprimirArray(valor, 10);

    for (int rep = 9; rep > 0; rep--)
    {
        for (int k = 0; k < rep; k++)
        {
            valor[k] += valor[k + 1];
        }
        imprimirArray(valor, rep);
    }

    return 0;
}
