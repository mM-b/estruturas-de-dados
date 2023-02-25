#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    int *p1;
    int *p2 = &a; // p2 recebe o endereço de a
    int *p3 = &c; // p3 recebe o endereço de c
    p1 = p2;      // p1 recebe o endereço de a
    *p2 = 10;     // a=10 pois é onde p2 aponta
    b = 20;
    int **pp;
    pp = &p1;          // pp recebe o endereço de p1
    *p3 = **pp;        // p3 recebe o endereço de a
    int *p4 = &d;      // p4 recebe o endereço de d
    *p4 = b + (*p1)++; // d recebe 20 + 10++;, d=30 e a=11 apos a execução da linha
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    return 0;
}

// a=11 b=20 c=10 d=30
