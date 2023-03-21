/*
Crie uma matriz  5 x 5 de inteiros e posteriormente (após o preenchimentos dos elementos via teclado), 
escreva a localização (linha e a coluna) do maior valor.
*/

#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int main(){
    int m[ROW][COL]={
        {3,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,60,19,20},
        {21,22,23,24,25}
    };
    int i,j,aux,iaux=0,jaux=0;

    //impressão matriz
    for(i=0;i<ROW;i++){
        printf("[%i] ",i);
        for(j=0;j<COL;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }

    //procura maior valor
    aux=m[0][0];
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(aux<m[i][j]){
                aux=m[i][j];
                iaux=i;
                jaux=j;
            }
        }
    }
    printf("Maior: m[%i][%i]= %i \n",iaux,jaux,aux);

    return 0;

}