#include <stdio.h>
int main(void)
{
    int x, y, *p;                       // declaração de variaveis
    y = 0;                              // y recebe 0
    p = &y;                             // p recebe o endereço de y
    x = *p;                             // x recebe o endereço que p aponta
    x = 4;                              // x recebe 4
    (*p)++;                             // o endereço que p aponta é incrementado
    --x;                                // decrementa o valor de x
    (*p) += x;                          // o conteudo onde p aponta é somado com x

    printf("x= %d y=%d p=%p", x, y, p); 
    return 0;
}
