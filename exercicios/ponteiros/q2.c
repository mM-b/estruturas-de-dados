#include <stdio.h>

int main(void)
{
    int x, *p; // declarando as variáveis
    x = 100;   // atribui 100 a x
    p = x;     // p recebe x
    printf("Valor de p = %p\tValor de *p = %d", p, *p);
}

/**
 * a) advertencia
 * b) pois o programa tenta imprimir com os tipos errados
 * c) não
 * d) p=&x;
 * e) sim
 */
