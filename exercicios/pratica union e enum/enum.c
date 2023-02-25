#include <stdio.h>

typedef enum mes // cria um para mes
{
    janeiro,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
} Mes;

typedef struct data // cria uma estrutura para data
{
    int dia;
    Mes mes;
    int ano;
} Data;

int main(void)
{
    Data data;
    printf("informe o dia:\n");
    scanf(" %d", &data.dia);
    printf("informe o mes:\n");
    scanf(" %d", (int *)&data.mes); // força o compilador a reconher data.mes como inteiro
    printf("informe o ano:\n");
    scanf(" %d", &data.ano);
    data.mes = data.mes - 1; // subtrai um para o mês possuir o mesmo valor das constantes do enum
    switch (data.mes) 
    {
    case janeiro:
        printf("%d/01/%d", data.dia, data.ano);
        break;
    case fevereiro:
        printf("%d/02/%d", data.dia, data.ano);
        break;
    case marco:
        printf("%d/03/%d", data.dia, data.ano);
        break;
    case abril:
        printf("%d/04/%d", data.dia, data.ano);
        break;
    case maio:
        printf("%d/05/%d", data.dia, data.ano);
        break;
    case junho:
        printf("%d/06/%d", data.dia, data.ano);
        break;
    case julho:
        printf("%d/07/%d", data.dia, data.ano);
        break;
    case agosto:
        printf("%d/08/%d", data.dia, data.ano);
        break;
    case setembro:
        printf("%d/09/%d", data.dia, data.ano);
        break;
    case outubro:
        printf("%d/10/%d", data.dia, data.ano);
        break;
    case novembro:
        printf("%d/11/%d", data.dia, data.ano);
        break;
    case dezembro:
        printf("%d/12/%d", data.dia, data.ano);
        break;
    default:
        printf("\nnumero invalido!\n");
        break;
    }

    return 0;
}
