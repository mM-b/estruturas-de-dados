#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{ // cria uma estrutura para pessoa
    char nome[50];
    int numero;
    int idade;
} Pessoa;
int contador;

/**
 * função para leitura de dados de uma pessoa
 * @param *pessoa
 * @param tamanho
 */
void recebe(Pessoa *pessoa, int tamanho)
{
    for (contador = 0; contador < tamanho; contador++)
    {
        printf("informe seu nome\n");
        scanf(" %[^\n]s", pessoa[contador].nome);
        printf("informe o numero do documento\n");
        scanf("%d", &pessoa[contador].numero);
        printf("informe sua idade\n");
        scanf("%d", &pessoa[contador].idade);
    }
}

/**
 * função que imprime os dados fornecidos pelo usuario
 * @param *pessoa
 * @param tamanho
 */
void imprime(Pessoa *pessoa, int tamanho)
{
    for (contador = 0; contador < tamanho; contador++)
    {
        printf("\nNome:%s\nNumero do documento:%d\nidade:%d\n\n", pessoa[contador].nome, pessoa[contador].numero, pessoa[contador].idade);
    }
}

/**
 * função para alterar a idade de uma pessoa
 * @param *pessoa
 */
void altera_id(Pessoa *pessoa)
{
    printf("informe a nova idade");
    int nv_idade;
    scanf("%d", &nv_idade);
    pessoa->idade = nv_idade;
}

/**
 * função que descobre a pessoa mais vela e a pessoa mais nova
 * @param *pessoa
 * @param tamanho
 */
void maisvelho_novo(Pessoa *pessoa, int tamanho)
{
    int ivelho = 0, inovo = 0; // inicia os indices em zeros, esse indice vão servir para descobri o nome da pessoa

    int velho = pessoa[0].idade; // atribui a pessoa[0] como mais velha
    int novo = pessoa[0].idade;  // atribui a pessoa[0] como a mais nova
    for (contador = 0; contador < tamanho; contador++)
    {

        if (pessoa[contador].idade > velho) // verifica se a idade da pessoa[contador] é maior que a idade armazenada em velho
        {
            velho = pessoa[contador].idade; // quando a condição de if é verdadeira, a variável velho é atualizada
            ivelho = contador;              // o indice dessa pessoa é registrado
        }
        if (pessoa[contador].idade < novo) // verifica se a idade da pessoa[contador] é menor que a idade armazenada em novo
        {
            novo = pessoa[contador].idade; // quando a condição de if é verdadeira, a variável novo é atualizada
            inovo = contador;              // o indice dessa pessoa é registrado
        }
    }
    printf("nome da pessoa mais velha:%s\nnome da pessoa mais nova:%s", pessoa[ivelho].nome, pessoa[inovo].nome);
}

int main(void)
{
    int tamanho;
    printf("informe a quantidade de pessoas\n");
    scanf("%d", &tamanho);
    Pessoa *pessoa = (Pessoa *)malloc(tamanho * sizeof(Pessoa)); // aloca dinamicamente um vetor de estrutura
    if(pessoa==NULL){//verifica se a alocação foi bem sucedida
        exit(1);
    }

    recebe(pessoa, tamanho);

    imprime(pessoa, tamanho);

    int funcio; 
    printf("Qual pessoa voce deseja alterar a idade: (1-primeira pessoa,2-segunda pessoa,3...\n)");
    scanf("%d", &funcio);

    altera_id(&pessoa[funcio - 1]);

    imprime(pessoa, tamanho);

    maisvelho_novo(pessoa, tamanho);

    free(pessoa); //libera a memória alocada por pessoa
    return 0;
}
