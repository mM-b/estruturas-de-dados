#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aprovacoes = 0, nquestoes;
    float nota, valor_questao;
    char *gabarito = (char *)malloc(50 * sizeof(char));      // aloca dinamicamente um vetor de char
    char **respostas = (char **)malloc(10 * sizeof(char *)); // aloca dinamicamente uma matriz de 10 linhas, pois são 10 alunos

    for (int i = 0; i < 10; i++) // laço de for para percorre todas as posições da matriz
    {
        respostas[i] = (char *)malloc(50 * sizeof(char)); //aloca dinamicamente um vetor de char em respota na posição i
    }

    printf("Informe a quantidade de questoes:");
    scanf("%d", &nquestoes);
    printf("Informe o gabarito das questoes (ex: bdccabd):");
    scanf("%s", gabarito);
    valor_questao = 10.0 / nquestoes; // dá o valor de cada questão 

    for (int i = 0; i < 10; i++) //for para verificar os 10 alunos 
    {
        printf("Respostas do aluno %d:", i + 1);
        scanf(" %[^\n]s", respostas[i]); //recebe a resposta do aluno na posição i

        nota = 0;
        for (int j = 0; j < nquestoes; j++)//percorre todas as questões
        {
            if (respostas[i][j] == gabarito[j]) //verifica cada uma das resposta individualmente
            {
                nota += valor_questao;//quando a condiça é atingida o aluno recebe uma parte da nota
            }
        }
        if (nota >= 6)//quanto o aluno atinge uma nota maior ou igual a 6 aprovações é incrementado
        {
            aprovacoes++;
        }
        printf("\nNota do aluno %d: %.1f\n", i + 1, nota);
    }

    printf("Porcentagem de aprovacao: %.1f\n", aprovacoes * 10.0);

    free(gabarito);//libera a memora alocada de gabarito
    for (int i = 0; i < 10; i++)//percorre todas as posições de respota
    {
        free(respostas[i]); //libera a memora alocada de resposta na posição i
    }
    free(respostas); //libera a memora alocada de respostas

    return 0;
}
