#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aprovacoes = 0, nquestoes;
    float nota, valor_questao;
    char *gabarito = (char *)malloc(50 * sizeof(char));
    char **respostas = (char **)malloc(10 * sizeof(char *));

    for (int i = 0; i < 10; i++)
    {
        respostas[i] = (char *)malloc(50 * sizeof(char));
    }

    printf("Informe a quantidade de questoes:");
    scanf("%d", &nquestoes);
    printf("Informe o gabarito das questoes (ex: bdccabd):");
    scanf("%s", gabarito);
    valor_questao = 10.0 / nquestoes;

    for (int i = 0; i < 10; i++)
    {
        printf("Respostas do aluno %d:", i + 1);
        scanf("%s", respostas[i]);

        nota = 0;
        for (int j = 0; j < nquestoes; j++)
        {
            if (respostas[i][j] == gabarito[j])
            {
                nota += valor_questao;
            }
        }
        if (nota >= 6)
        {
            aprovacoes++;
        }
        printf("\nNota do aluno %d: %.1f\n", i + 1, nota);
    }

    printf("Porcentagem de aprovacao: %.1f\n", aprovacoes * 10.0);

    free(gabarito);
    for (int i = 0; i < 10; i++)
    {
        free(respostas[i]);
    }
    free(respostas);

    return 0;
}
