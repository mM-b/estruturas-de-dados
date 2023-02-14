#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int qntfrutas, linha;
    printf("Digite a quantidade de frutas");
    scanf("%d", &qntfrutas);

    char **frutas = (int *)malloc(qntfrutas * sizeof(int *));
    if (frutas == NULL)
    {
        exit(1);
    }

    for (linha = 0; linha < qntfrutas; linha++)
    {
        frutas[linha] = (char *)malloc(50 * sizeof(char *));
    }

    float *preco = (float *)malloc(qntfrutas * sizeof(float));
    if (preco == NULL)
    {
        exit(1);
    }
    for (linha = 0; linha < qntfrutas; linha++)
    {
        scanf("%[^\n]s", frutas[linha]);
        scanf("%f", &preco[linha]);
    }

    for (linha = 0; linha < qntfrutas; linha++)
    {
        free(frutas[linha]);
    }
    free(frutas);
    free(preco);

    return 0;
}