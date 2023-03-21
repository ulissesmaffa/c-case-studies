/*
Leia uma matriz 5 x 5 e faça uma troca entre as diagonais principal e secundária. Escreva-a ao final.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"

#define ROW 5
#define COL 5

void changeDiagonal(int row, int col, int m[row][col]){
    int i,j,k=0;
    int v[row];

    //copia diagonal principal para vetor
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==j){
                v[k]=m[i][j];
                k++;
            }
        }
    }
    //impressao do vetor
    for(k=0;k<row;k++){
        printf("%i ",v[k]);
    }

    //copia diagonal secundária para diagonal principal
    k=row-1;//sempre lembrar desse detalhe do -1
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==j){
                m[i][j]=m[i][k];
                k--;
            }
        }
    }

    //copia vetor com a diagonal principal para a diagonal secundária
    k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i+j==row-1){
                m[i][j]=v[k];
                k++;
            }
        }
    }

}

int main(){
     int m1[ROW][COL];
    //funçoes presente na biblioteca ulissesMatrix.h
    randomMatrix(ROW,COL,m1);
    printf("Matriz original:\n");
    printMatrix(ROW,COL,m1);

    changeDiagonal(ROW,COL,m1);
    printf("\nNova matriz:\n");
    printMatrix(ROW,COL,m1);

    return 0;
}
