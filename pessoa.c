#include <stdio.h>

typedef enum genero
{
    MASCULINO,
    FEMININO,
    NEUTRO

} Genero;

typedef struct pessoa
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
    scanf("%d",&p1.idade);
    printf("informe o genero");
    scanf("%d",(int*)&p1.genero);

    printf("nome:%s\nidade:%d\n",p1.nome,p1.idade);
    p1.genero==MASCULINO?printf("Masculino\n"):printf("Feminino");
    return 0;
}