#include <stdio.h>
#include <math.h>

/**
 * calcula a area e o perimetro de um hexagono
 * @param l
 * @param *area
 * @param *perimetro
 */
void calcula_hexagono(float l, float *area, float *perimetro)
{
    *area = ((3 * pow(l, 2)) * (sqrt(3))) / 2;
    *perimetro = 6 * l;
}

int main(void)
{
    float l, area, perimetro;

    printf("informe o lado de um hexagono para verificar sua area e perimetro\n");
    scanf("%f", &l);
    calcula_hexagono(l, &area, &perimetro);// como função espera receber ponteiros, são passados dois endereços, o tipo de dados que ponteiro recebe
    printf("area do hexagono: %f\nperimetro do hexagono: %f", area, perimetro);
    return 0;
}
