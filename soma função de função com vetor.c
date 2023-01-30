#include<stdio.h>
int soma(int nx, int ny){
    return nx + ny;
}
int calcula(int x, int y, int(*op)(int,int)){
    return(*op)(x,y);
}
int main(void){
int resultado = calcula(5,3,soma);
printf("%d",resultado);
}
