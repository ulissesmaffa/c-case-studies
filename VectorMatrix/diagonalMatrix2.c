/*
 * Transformação de Matriz 8x8 em Matriz Triangular Inferior
 * Este programa lê uma matriz 8x8 e a transforma em uma matriz triangular inferior,
 * atribuindo zero a todos os elementos acima da diagonal principal. A matriz resultante é exibida ao final.
 * A matriz inicial é preenchida com valores aleatórios.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - Utiliza a função randomMatrix da biblioteca 'ulissesMatrix.h' para gerar a matriz inicial.
 * - A função diagonalMatrix(int row, int col, int m[row][col]) é responsável pela transformação da matriz.
 * - Elementos acima da diagonal principal são definidos como zero para formar a matriz triangular inferior.
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