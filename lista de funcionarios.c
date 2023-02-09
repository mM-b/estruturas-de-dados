#include<stdio.h>
#include<stdlib.h>

typedef struct funcionarios{
    char nome[50];
    float salarios;
    char cargo[50];
}Funcionario;



int main(void){
    int tamanho;
    printf("informe a quantidade de funcionarios\n");
    scanf("%d",&tamanho);
    Funcionario * funcionarios  = (Funcionario*) malloc(tamanho * sizeof(Funcionario));
    for(int i=0;i<tamanho;i++){
        printf("informe seu nome\n");
        scanf(" %[^\n]s",funcionarios[i].nome);
        printf("informe o salario\n");
        scanf("%f",&funcionarios[i].salarios);
        printf("informe seu cargo\n");
        scanf(" %[^\n]s",funcionarios[i].cargo);
    }
printf("\n");
    for(int i=0;i<tamanho;i++){
        printf("nome:%s\nsalario:%.2f\ncargo:%s\n\n",funcionarios[i].nome,funcionarios[i].salarios,funcionarios[i].cargo);
    }
free(funcionarios);
    return 0;
}
