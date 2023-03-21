/*
Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos. Escreva ao final a matriz obtida.
*/

#include <stdio.h>

#define ROW 5
#define COL 5

int main(){
    int m[ROW][COL];
    int i,j;
    
    //preechimento da matriz, 1 na diagonal e 0 no restante
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(i==j){
                m[i][j]=1;
            }else{
                m[i][j]=0;
            }
        }
    }

    //impressão matriz
    for(i=0;i<ROW;i++){
        printf("[%i] ",i);
        for(j=0;j<COL;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}