/*
 * Substituição entre Diagonais de Duas Matrizes 10x10
 * Este programa lê duas matrizes 10x10, troca a diagonal principal da primeira matriz com a diagonal secundária da segunda e exibe as matrizes modificadas.
 * As matrizes são preenchidas com valores aleatórios e, após a substituição das diagonais, as matrizes modificadas são apresentadas.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - Utiliza a função randomMatrix da biblioteca 'ulissesMatrix.h' para preencher as matrizes com valores aleatórios.
 * - A função changeDiagonal2(int row, int col, int m1[row][col], int m2[row][col]) realiza a troca das diagonais entre as duas matrizes.
 * - A diagonal principal da primeira matriz e a diagonal secundária da segunda matriz são copiadas e substituídas entre si.
 */


#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"

#define ROW 10
#define COL 10

void changeDiagonal2(int row, int col, int m1[row][col], int m2[row][col]){
    int i,j,k=0;
    int v[row];

    //copia diagonal principal da matriz 1
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==j){
                v[k]=m1[i][j];
                k++;
            }
        }
    }
    //impressao do vetor
    for(k=0;k<row;k++){
        printf("%i ",v[k]);
    }

    //copia diagonal secundária da matriz 2 para diagonal principal da matriz1
    k=row-1;//sempre lembrar desse detalhe do -1
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==j){
                m1[i][j]=m2[i][k];
                k--;
            }
        }
    }

    //copia vetor com a diagonal principal da m1 para a diagonal secundária da m2
    k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i+j==row-1){
                m2[i][j]=v[k];
                k++;
            }
        }
    }

}

int main(){
    int m1[ROW][COL];
    int m2[ROW][COL];
    //funçoes presente na biblioteca ulissesMatrix.h
    randomMatrix(ROW,COL,m1);
    printf("\n[1] Matriz original:\n");
    printMatrix(ROW,COL,m1);
    
    randomMatrix(ROW,COL,m2);
    printf("\n[2] Matriz original:\n");
    printMatrix(ROW,COL,m2);

    changeDiagonal2(ROW,COL,m1,m2);
    printf("\n[1] Nova matriz:\n");
    printMatrix(ROW,COL,m1);
    
    printf("\n[2] Nova matriz:\n");
    printMatrix(ROW,COL,m2);

    return 0;
}
