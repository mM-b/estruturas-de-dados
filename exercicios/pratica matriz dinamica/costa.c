#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, M, N, costa = 0; // M vão ser as linhas da matriz N vão ser colunas da matriz
    printf("informe a quantidade de linhas\n");
    scanf("%d", &M);
    printf("informe a quantidade de colunas\n");
    scanf("%d", &N);

    char **mapa = (char **)malloc(M * sizeof(char *)); // cria uma matriz de caracteres e aloca o espaço dinamicamente
    for (i = 0; i < M; i++)                            // for percorre todas as linhas da matriz
    {
        mapa[i] = (char *)malloc(N * sizeof(char)); // aloca dinamicamente mapa na posição i
    }

    printf("\ninforme o terreno:\t(exemplo de entrada: ''...###..'')\t''.'' sera entendido como agua e ''#'' como terra\n");
    for (i = 0; i < M; i++)
    {

        scanf("%s", mapa[i]);
    }
    printf("\n");

    for (i = 0; i < M; i++) // percorre as linha da matriz
    {
        for (j = 0; j < N; j++) // precorre as colunas da matriz
        {
            // duas condições precisam ser verdadeiras
            // se mapa[i][j]=='#'
            // ou algumas das seguintes
            // i==0 é costa pois é uma borda do mapa, e o que vai além das bordas será considerado agua
            // mapa[i-1][j]=='.' verifica se há agua acima
            // mapa[i+1][j]=='.' verifica se há agua abaixo
            // i=M-1 é costa pois é uma borda do mapa, e o que vai além das bordas será considerado borda
            //  j=0 é costa pois é uma borda do mapa, e o que vai além das bordas será considerado agua
            // mapa[i][j - 1] == '.' verifica se há agua a esquerda
            // j == N - 1 é costa pois é uma borda do mapa, e o que vai além das bordas será considerado agua
            // mapa[i][j + 1] == '.' verifica se há agua a direita
            if (mapa[i][j] == '#' && ((i == 0 || mapa[i - 1][j] == '.') || (i == M - 1 || mapa[i + 1][j] == '.') || (j == 0 || mapa[i][j - 1] == '.') || (j == N - 1 || mapa[i][j + 1] == '.')))

            {
                costa++; // incrementa sempre que há # na posição mapa[i][j] e qualquer outra condição verdadeira
            }
        }
    }

   
    printf("%d", costa);
    
    for (i = 0; i < M; i++)
    {
        free(mapa[i]);//libera a memória de mapa na posição i
    }
    free(mapa); //libera a memória de mapa

    return 0;
}
