#include<stdio.h>
#include<string.h>
int sub(int x,int y){
    return x - y;
}
int soma(int nx, int ny){
    return nx + ny;
}
int calcula(int x, int y, int(*op)(int,int)){
    return(*op)(x,y);
}
int main(void){
    char x[50];
int resultado;
printf("para somar os valores digite 'soma' ");
scanf("%s",&x);
if(strcmp(x,"soma")==0){
    resultado = calcula(5,3,soma);
    printf("%d", resultado);
}
else if(strcmp(x,"sub")==0){
    resultado = calcula(5,3,sub);
    printf("%d",resultado);
}
    return 0;
}
