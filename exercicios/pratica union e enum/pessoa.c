#include <stdio.h>

typedef enum genero // cria um enum para generos
{
    MASCULINO,//recebe o valor 0
    FEMININO//recebe o valor 1
} Genero;

typedef struct pessoa //cria uma estrutura de pessoa
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;
int main(void)
{
    Pessoa p1;
    printf("informe o nome:");
    scanf(" %[^\n]s", p1.nome);
    printf("informe a idade:");
    scanf("%d", &p1.idade);
    printf("informe o genero");
    scanf("%d", (int *)&p1.genero);

    printf("nome:%s\nidade:%d\n", p1.nome, p1.idade);
    p1.genero == MASCULINO ? printf("Masculino\n") : printf("Feminino");
    //é uma declaração condicional. Se a variavel genero da estrutura aluno for igual a MASCULINO , Masculino é impresso, senao, Feminino é impresso
    return 0;
}
