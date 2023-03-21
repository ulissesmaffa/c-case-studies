/*
Leia uma matriz 50 x 2, onde cada coluna corresponde a um lado de um triangulo retângulo. 
Declare um vetor que contenha a área dos respectivos triângulos e o escreva.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"

#define ROW 50
#define COL 2

void calcArea(int row, int col, int m[row][col]){
    int i,j,k=0;
    int v[row];
    //calcula área da matrix
    for(i=0;i<row;i++){
        for(j=0;j<col-1;j++){
            v[k]=m[i][j]*m[i][j+1];
            k++;
        }
    }
    //imprime vetor de áreas
    for(k=0;k<row;k++){
        printf("%i ",v[k]);
    }
}

int main(){
    int m1[ROW][COL];
    //funçoes presente na biblioteca ulissesMatrix.h
    randomMatrix(ROW,COL,m1);
    printf("\n[1] Matriz original:\n");
    printMatrix(ROW,COL,m1);
    
    calcArea(ROW,COL,m1);

    return 0;
}
