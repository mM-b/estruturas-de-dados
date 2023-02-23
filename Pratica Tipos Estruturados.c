#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VAGAS 3
#define MAX_TURMAS 3

struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma
{
    char id;
    int vagas;
    Aluno *alunos[3];
};
typedef struct turma Turma;

Turma *cria_turma(char id)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));
    turma->id = id;
    turma->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        turma->alunos[i] = NULL;
    }
    return turma;
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    if (turma->vagas == 0)
    {
        printf("Nao ha vagas disponiveis na turma %c.\n", turma->id);
    }
    else
    {
        Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
        novo_aluno->mat = mat;
        strcpy(novo_aluno->nome, nome);
        novo_aluno->notas[0] = 0;
        novo_aluno->notas[1] = 0;
        novo_aluno->notas[2] = 0;
        novo_aluno->media = 0;

        for (int i = 0; i < MAX_VAGAS; i++)
        {
            if (turma->alunos[i] == NULL)
            {
                turma->alunos[i] = novo_aluno;
                turma->vagas--;
            }
        }
    }
}

void lanca_notas(Turma *turma)
{
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Aluno: %s\n", turma->alunos[i]->nome);
            for (int j = 0; j < 3; j++)
            {
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &turma->alunos[i]->notas[j]);
            }

            float soma = 0.0;
            for (int k = 0; k < 3; k++)
            {
                soma += turma->alunos[i]->notas[k];
            }
            turma->alunos[i]->media = soma / 3.0;
        }
    }
    printf("Notas lancadas com sucesso!\n");
}

void imprime_alunos(Turma *turma)
{
    printf("Alunos da turma %c:\n\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        Aluno *aluno = turma->alunos[i];
        if (aluno != NULL)
        {
            printf("Matricula: %d\nNome: %s\nNotas: %.1f, %.1f, %.1f\nMedia: %.1f\n\n", aluno->mat, aluno->nome, aluno->notas[0], aluno->notas[1], aluno->notas[2], aluno->media);
        }
    }
}
void imprime_turmas(Turma **turma, int nturmas)
{
    system("cls");
    printf("turmas disponiveis:\n\n");
    for (int i = 0; i < nturmas; i++)
    {
        Turma *turmaimprime = turma[i];
        printf("tumar %c - vagas disponiveis %d\n", turmaimprime->id, turmaimprime->vagas);
    }
}

int main(void)
{
    Turma **turmas = (Turma **)malloc(3 * sizeof(Turma *));
    Turma *procuraturma;
    char id;
    char nome[81];
    int opcao, x = 0, nturmas = 0, matriculx;
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as\nfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    while (x != 1)
    {
        printf("MENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            printf("criando turma...\n");
            printf("informe o id\n");
            scanf(" %c", &id);
            turmas[nturmas] = (Turma *)malloc(sizeof(Turma));
            turmas[nturmas] = cria_turma(id);
            procuraturma = turmas[nturmas];
            nturmas++;
            system("cls");
            printf("\nTurma %c criada\n\n", id);
            break;
        case 2:
            system("cls");
            printf("listando turmas...\n");
            imprime_turmas(turmas, nturmas);
            break;
        case 3:
            printf("matriculando aluno...\n");
            printf("Digite o id da turma:\n");
            scanf(" %c", &id);
            printf("Digite a matricula:\n");
            scanf("%d", &matriculx);
            printf("Digite o nome:\n");
            scanf(" %[^\n]s", nome);
            matricula_aluno(procuraturma, matriculx, nome);
            printf("Aluno matriculado com sucesso!\n");
            break;
        case 4:
            system("cls");
            printf("Lancando notas...");
            lanca_notas(procuraturma);
            break;
        case 5:
            system("cls");
            printf("Listando alunos...");
            imprime_alunos(procuraturma);
            break;
        case 6:
            printf("Obrigado por usar este programa!");
            x = 1;
            break;

        default:
            system("cls");
            printf("\t!!!\ninforme um valor valido!\n\n");
            break;
        }
    }
    for (int i = 0; i < nturmas; i++)
    {
        free(turmas[i]);
    }
    free(turmas);
    return 0;
}