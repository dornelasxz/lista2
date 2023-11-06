#include <stdio.h>
#include <stdlib.h>

void inicioMatrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void preencherMatrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printfMatrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int primeiraM[4][4], segundaM[4][4], Resfinal[4][4];
    char operacao[10];

    inicioMatrix(Resfinal);

    preencherMatrix(primeiraM);

    preencherMatrix(segundaM);

    scanf("%s", operacao);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (operacao[0] == 's' && operacao[1] == 'o' && operacao[2] == 'm' && operacao[3] == 'a' && operacao[4] == '\0')
            {
                Resfinal[i][j] = primeiraM[i][j] + segundaM[i][j];
            }
            else if (operacao[0] == 's' && operacao[1] == 'u' && operacao[2] == 'b' && operacao[3] == '\0')
            {
                Resfinal[i][j] = primeiraM[i][j] - segundaM[i][j];
            }
            else if (operacao[0] == 'm' && operacao[1] == 'u' && operacao[2] == 'l' && operacao[3] == 't' && operacao[4] == '\0')
            {
                for (int k = 0; k < 4; k++)
                {
                    Resfinal[i][j] += primeiraM[i][k] * segundaM[k][j];
                }
            }
        }
    }

    printfMatrix(Resfinal);

    return 0;
}