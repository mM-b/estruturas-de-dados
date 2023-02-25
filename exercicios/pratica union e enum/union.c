#include <stdio.h>

typedef union tipo //cria uma union para tipo
{
char alimento[50];
char eletronico[50];
char bebida[50];
}Tipo;

typedef struct produto //cria uma estrutura para produto 
{
    char nome[50];
    float preco;
    Tipo tipo;
}Produto;

int main(void)
{
    Produto Product;
printf("informe o nome do produto");
scanf(" %[^\n]s",Product.nome);
printf("informe o preco do produto:");
scanf("%f",Product.preco);
printf("informe o tipo de produto(alimento,eletronico,bedida)");
scanf(" %[^\n]", Product.tipo.alimento); //as variáveis que irão receber o tipo de produto serem do mesmo tipo, e pertencerem a uma union, todas compartilham o mesmo endereço
printf("nome do produto:%s\npreco:%f\ntipo do produto");

    return 0;
}
