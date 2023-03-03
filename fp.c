#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    int c;
    // int nlinhas = 1;
    char entrada[121];
    char saida[121];
    FILE *e;
    FILE *s;
    // fp = fopen("entrada.txt", "rt");
    // if (fp == NULL)
    // {
    //     printf("erro");
    //     exit(1);
    // }
    // while ((c = fgetc(fp)) != EOF)//c recebe o retorno da função fgetc, que le os caracteres de fp, e compara se c é diferente de end of file
    // {
    //     if (c == '\n')//quando c=='n' uma linha é contada
    //     {
    //         nlinhas++;
    //     }
    // }
    printf("Digite o nome do arquivo de entrada: \n");
    scanf(" %120s", entrada);
    printf("Digite o nome do arquivo de said: \n");
    scanf("%120s", saida);

    e = fopen(entrada, "rt");
    if (e == NULL)
    {
        printf("nao foi possivel abrir o arquivo de entrada");
        return 1;
    }
    s = fopen(saida, "wt");
    if (s == NULL)
    {
        printf("nao foi possivel abrir o arquivo de saida");
        fclose(e);
        return 1;
    }

    while ((c = fgetc(e)) != EOF)
    {
        fputc(toupper(c), s); // toupper converte caracteres em caracteres maiusculos
    }
    fclose(e);
    fclose(s);

    // int valor = fclose(fp);
    // printf("numero de linhas %d\n", nlinhas);
    // if (valor != 0)
    // {
    //     printf("nao foi possivel fechar o arquivo");
    // }
    // else
    // {
    //     printf("fechou!");
    // }

    return 0;
}