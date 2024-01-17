
/*
 * Troca de Valores entre a 1ª Linha e a 4ª Coluna de uma Matriz 4x4
 * Este programa lê uma matriz 4x4, troca os valores da primeira linha com os da quarta coluna e vice-versa, e exibe a matriz resultante.
 * A matriz é preenchida com valores aleatórios e, após a troca, a matriz modificada é apresentada.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - Utiliza a função randomMatrix da biblioteca 'ulissesMatrix.h' para preencher a matriz com valores aleatórios.
 * - A função changeValues(int row, int col, int m[row][col]) realiza a troca dos valores entre a primeira linha e a quarta coluna.
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