#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    float npess;
    float FG = 0, MN = 0;
    printf("informe a quantidade pessoas");
    scanf("%f", &npess);
    

    char *sexo = (char *)malloc(30 * sizeof(char));
    char **opiniao = (char **)malloc(npess * sizeof(char *));
    if (sexo == NULL)
    {
        exit(1);
    }
    if (opiniao == NULL)
    {
        exit(1);
    }
    for (int j = 0; j < npess; j++)
    {
        opiniao[j] = (char *)malloc(50 * sizeof(char));
    }
    for (int j = 0; j < npess; j++)
    {
        printf("informe o sexo.(respostas validas:M,F)");
        scanf(" %[^\n]s", sexo);
        printf("qual sua opiniao sobre o produto?(respostas validas:gostei,nao gostei)");
        scanf(" %[^\n]s", opiniao[j]);
        if ((strcmp(sexo,"F") == 0) && (strcmp(opiniao[j], "gostei") == 0))
        {
            FG++;
        }
        if ((strcmp(sexo, "M") == 0) && (strcmp(opiniao[j], "nao gostei") == 0))
        {
            MN++;
        }
    }

    printf("porcentagem de pessoas do sexo feminino que responderam que gostaram do produto: %f\nporcentagem de pessoas do sexo masculino que responderam que nao gostaram do produto:%f", (FG/npess)*100.0, (MN/npess)*100.0);  

    free(sexo);
    for (int j = 0; j < npess; j++)
    {
        free(opiniao[j]);
    }
    free(opiniao);

    return 0;
}
