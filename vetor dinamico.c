#include<stdio.h>
#include<stdlib.h>
int main(void){
int tamanho = 10;
int i;
int * vetor = (int*) malloc(tamanho*sizeof(int));
if(vetor == NULL){
    exit(1);
}
for(i=0;i<tamanho;i++){
    vetor[i]=i;
}
for(i=0; i<tamanho; i++){
    printf("%d\t",vetor[i]);
}
free(vetor);
return 0;
}
