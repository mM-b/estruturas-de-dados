#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    float npess;
    float FG = 0, MN = 0;
    printf("informe a quantidade pessoas");
    scanf("%f", &npess);

    char *sexo = (char *)malloc(30 * sizeof(char));           // aloca dinamicamente  um vetor de char
    char **opiniao = (char **)malloc(npess * sizeof(char *)); // aloca dinamicamente uma matriz de char
    if (sexo == NULL)                                         // verifica se a alocação foi bem sucedida
    {
        exit(1); // aborta a execução
    }
    if (opiniao == NULL)
    {
        exit(1);
    }
    for (int j = 0; j < npess; j++) // percorre as linhas da matriz
    {
        opiniao[j] = (char *)malloc(50 * sizeof(char)); // aloca dinamicamente um vetor de char em opniao[j]
    }
    for (int j = 0; j < npess; j++)
    {
        printf("informe o sexo.(respostas validas:M,F)");
        scanf(" %[^\n]s", sexo);
        printf("qual sua opiniao sobre o produto?(respostas validas:gostei,nao gostei)");
        scanf(" %[^\n]s", opiniao[j]);
        if ((strcmp(sexo, "F") == 0) && (strcmp(opiniao[j], "gostei") == 0)) // se as string forem iguais a função retorna zero, verificando que as condições foram atendidas
        {
            FG++; // conta a quantidade de pessoas do sexo feminino que gostaram
        }
        if ((strcmp(sexo, "M") == 0) && (strcmp(opiniao[j], "nao gostei") == 0))
        {
            MN++; // conta a quantidade de pessoas do sexo masculino que não gostaram
        }
    }

    printf("porcentagem de pessoas do sexo feminino que responderam que gostaram do produto: %f\nporcentagem de pessoas do sexo masculino que responderam que nao gostaram do produto:%f", (FG / npess) * 100.0, (MN / npess) * 100.0);

    free(sexo);
    for (int j = 0; j < npess; j++) // percorre todas as posições de opiniao
    {
        free(opiniao[j]); // libera a memoria de opniao na posição j
    }
    free(opiniao); // libera a memoria alocada em opiniao

    return 0;
}
