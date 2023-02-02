#include<stdio.h>
#include<stdlib.h>

int main(void){
    int linha = 0, linhas = 3, coluna = 3 ;
    int **M= (int**) malloc(linhas* sizeof(int*));
    for(linha=0;linha<linhas;linha++){
        M[linha]= (int*) malloc(coluna*sizeof(int));
    }
    int i, j;
    for(i=0;i<linhas;i++){
        for(j=0;j<coluna;j++){
            M[i][j]= i*3 + j;
        }
    }

    for(i=1;i<=linhas;i++){
        for(j=1;j<=coluna;j++){
            
            printf("%d\t",M[i-1][j-1]);
            if(j%3==0){
                printf("\n");
            }
        }

    }
    
int x;
for(x=0;x<linhas; x++){
free(M[x]);
}
free(M);
    return 0;

}