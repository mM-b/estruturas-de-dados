#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, M, N, costa = 0; // M linhas N colunas
    printf("informe a quantidade de linhas\n");
    scanf("%d", &M);
    printf("informe a quantidade de colunas\n");
    scanf("%d", &N);

    char **mapa = (char **)malloc(M * sizeof(char *));
    for (i = 0; i < M; i++)
    {
        mapa[i] = (char *)malloc(N * sizeof(char));
    }

    printf("\ninforme o terreno:\t(exemplo de entrada: ''...###..'')\t''.'' sera entendido como agua e ''#'' como terra\n");
    for (i = 0; i < M; i++)
    {

        scanf("%s", mapa[i]);
    }
    printf("\n");

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (mapa[i][j] == '#' && ((i == 0 || mapa[i - 1][j] == '.') || (i == M - 1 || mapa[i + 1][j] == '.') || (j == 0 || mapa[i][j - 1] == '.') || (j == N - 1 || mapa[i][j + 1] == '.')))
            {
                costa++;
            }
        }
    }

    // exibicao para teste
    for (i = 0; i < M; i++)
    {

        printf("%s\n", mapa[i]);
    }
    printf("%d",costa);

    for (i = 0; i < M; i++)
    {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}
