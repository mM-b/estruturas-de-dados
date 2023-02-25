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
    Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma;

/**
 *cria uma turma
 *@param id
 */
Turma *cria_turma(char id)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma)); // cria uma estrutura de Turma dinamicamente
    turma->id = id;                                // atribui o id na variável id de turma
    turma->vagas = MAX_VAGAS;                      // define a quantidade maxima de alunos
    for (int i = 0; i < MAX_VAGAS; i++)            // preenche todas as vagas com null
    {
        turma->alunos[i] = NULL;
    }
    return turma;
}

/**
 * matricula um aluno
 * @param *tuma
 * @param mat
 * @param *nome
 */
void matricula_aluno(Turma *turma, int mat, char *nome)
{
    if (turma->vagas == 0) // quando vagas estão em zero não matricula mais alunos
    {
        printf("Nao ha vagas disponiveis na turma %c.\n", turma->id);
    }
    else
    {
        Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno)); // aloca uma estrutura de aluno dinamicamente
        novo_aluno->mat = mat;                              // atribui a matricula pelo parametro
        strcpy(novo_aluno->nome, nome);                     // a função strcpy copia o nome para nome da estrutura aluno
        novo_aluno->notas[0] = 0;                           // inicia as notas em 0
        novo_aluno->notas[1] = 0;
        novo_aluno->notas[2] = 0;
        novo_aluno->media = 0; // inicia a meédia em 0

        for (int i = 0; i < MAX_VAGAS; i++)
        {
            if (turma->alunos[i] == NULL) // se na posição indice estiver NULL a vaga é preenchida
            {
                turma->alunos[i] = novo_aluno;
                turma->vagas--; // como uma vaga foi preenchida logo uma vaga diminui
                break;          // break, interrompe o for, para não preencher as vagas restante
            }
        }
    }
}

/***
 * lança a nota do aluno
 * @param *turma
 */
void lanca_notas(Turma *turma)
{
    for (int i = 0; i < MAX_VAGAS; i++) // percorre todas as posições do vetor aluno
    {
        if (turma->alunos[i] != NULL) // garante que apenas alunos matriculados recebam nota
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
                soma += turma->alunos[i]->notas[k]; // soma recebe a soma das três nota do aluno na posição i
            }
            turma->alunos[i]->media = soma / 3.0;
        }
    }
    printf("Notas lancadas com sucesso!\n");
}
/***
 * imprime as informações dos alunos da turma
 * @param *turma
 */
void imprime_alunos(Turma *turma)
{
    printf("Alunos da turma %c:\n\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++) // percorre as posicoes de aluno
    {
        Aluno *aluno = turma->alunos[i];
        if (aluno != NULL) // verifica que só alunos matriculados vao ser impressos
        {
            printf("Matricula: %d\nNome: %s\nNotas: %.1f, %.1f, %.1f\nMedia: %.1f\n\n", aluno->mat, aluno->nome, aluno->notas[0], aluno->notas[1], aluno->notas[2], aluno->media);
        }
    }
}

/**
 * imprime as turmas e suas vagas
 * @param **turma
 * @param nturmas
 */
void imprime_turmas(Turma **turma, int nturmas)
{

    printf("turmas disponiveis:\n\n");
    for (int i = 0; i < nturmas; i++) // percorre todas as poseções da matriz de turma
    {
        Turma *turmaimprime = turma[i]; // para acessar as tumas individualmente, e imprimir
        printf("tumar %c - vagas disponiveis %d\n", turmaimprime->id, turmaimprime->vagas);
    }
}
/**
 * procura a turma para auxiliar outras funções
 * @param **turmas
 * @param n
 * @param id
 * @return Turma
 */
Turma *procura_turma(Turma **turmas, int n, char id) // n é quantidade de turmas
{
    int i;
    for (i = 0; i < n; i++) // percorre todas as posições de turmas
    {
        if (turmas[i]->id == id) // verifica se a turma na posição i possui o mesmo id que foi passado como parâmetro
        {

            break; // break é usado para interromper o laço for quando os ids forem iguais
        }
    }
    return turmas[i]; // retorna a turma conforme o id informado
}

int main(void)
{
    Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *)); // aloca dinamicamente uma matriz de estrutura de tamanho MAX_TURMAS
    Turma *procuraturma;                                             // cria um ponteiro de estrutura
    char id;                                                         // será usado como parametro
    char nome[81];                                                   // será usado como parametro
    int opcao;                                                       // serve para controlar o switch, colocando em execução as intruições do case selecionado
    int x = 0;                                                       // variável de controle para interromper o funcionamento do programa
    int nturmas = 0;                                                 // conta o número de turmas
    int matriculx;                                                   // será usado como parametro
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as\nfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    while (x != 1)
    {
        printf("MENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:

            system("cls"); // serve para limpar a tela do prompt de comando
            printf("criando turma...\n");
            if (nturmas == MAX_TURMAS) // impede que mais de 3 turmas sejam criadas
            {
                printf("\nnumero de turmas excedido!\n\n");
            }
            else
            {
                printf("informe o id\n");
                scanf(" %c", &id);
                turmas[nturmas] = (Turma *)malloc(sizeof(Turma)); // aloca dinamicamente uma estrutura de Turma na posição nturmas
                turmas[nturmas] = cria_turma(id);                 // cria uma turma na posição nturma com o id que o usuario informa
                procuraturma = turmas[nturmas];                   // variavel para tratamento individual da turma
                nturmas++;                                        // incrementa nturmas, pois uma turma foi criada
                system("cls");                                    // serve para limpar a tela do prompt de comando
                printf("\nTurma %c criada\n\n", id);
            }
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
            procuraturma = procura_turma(turmas, nturmas, id);
            matricula_aluno(procuraturma, matriculx, nome);
            printf("Aluno matriculado com sucesso!\n");
            break;
        case 4:
            system("cls");
            printf("Lancando notas...\n");
            printf("Digite o id da turma:\n");
            scanf(" %c", &id);
            procuraturma = procura_turma(turmas, nturmas, id);
            lanca_notas(procuraturma);
            break;
        case 5:
            system("cls");
            printf("Listando alunos...");
            printf("Digite o id da turma:\n");
            scanf(" %c", &id);
            procuraturma = procura_turma(turmas, nturmas, id);
            imprime_alunos(procuraturma);
            break;
        case 6:
            printf("Obrigado por usar este programa!");
            x = 1; // para o laço de while
            break;

        default:           // quando o usuario digita uma opção invalida a seguinte mensagem é exibida
            system("cls"); // serve para limpar a tela do prompt de comando
            printf("\t!!!\ninforme um valor valido!\n\n");
            break;
        }
    }
    for (int i = 0; i < nturmas; i++) // percorre todas as posições de turmas
    {
        free(turmas[i]); // libera a memória na posição i de turmas
    }
    free(turmas); // libera a memoria de turmas
    return 0;
}
