
/*
Leia uma matriz 4 x 4 e troque os valores da 1ª.linha pelos da 4ª.coluna, vice-e-versa. Escrever ao final a matriz obtida
*/
#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"

#define ROW 4
#define COL 4

void changeValues(int row, int col, int m[row][col]){
    int i,j,k=0;
    int v[row];

    //pega os valores da primeira linha
    for(j=0;j<col;j++){
        v[k]=m[0][j];
        k++;
    }

    //grava linha 4 na linha 1
    for(j=0;j<col;j++){
        m[0][j]=m[3][j];
    }

    //grava vetor aux, antiga linha 1, na linha 4
    k=0;
    for(j=0;j<col;j++){
        m[3][j]=v[k];
        k++;
    }


}

int main(){
    int m1[ROW][COL];
    //funçoes presente na biblioteca ulissesMatrix.h
    randomMatrix(ROW,COL,m1);
    printMatrix(ROW,COL,m1);

    changeValues(ROW,COL,m1);

    printf("\nTroca realizada:\n");
    printMatrix(ROW,COL,m1);

    return (0);
}