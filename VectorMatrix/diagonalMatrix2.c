
/*
Leia uma matriz 8 x 8 e a transforme numa matriz triangular inferior , 
atribuindo zero a todos os elementos acima da diagonal principal, escrevendo-a ao final.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"

#define ROW 8
#define COL 8

void diagonalMatrix(int row, int col, int m[row][col]){
    int i,j;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i<=j){
                m[i][j]=0;
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

    diagonalMatrix(ROW,COL,m1);
    printf("\nNova matriz:\n");
    printMatrix(ROW,COL,m1);
}