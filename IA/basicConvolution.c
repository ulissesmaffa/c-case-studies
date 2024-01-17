/*
 * Programa de Convolução de Matrizes
 * Realiza a operação de convolução entre uma matriz principal e um kernel, gerando uma nova matriz.
 * Utiliza matrizes definidas pelo usuário para demonstrar o cálculo de convolução.
 *
 * Autor: Ulisses Maffazioli
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

//Linhas e colunas matriz principal
#define M_ROW 6
#define M_COL 6
//Linhas e colunas kernel
#define K_ROW 3
#define K_COL 3

void printMatrix(int row, int col, int m[row][col]){
    int i,j;    
    for(i=0;i<row;i++){
        // printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }
}

void convolution(int m_row, int m_col, int m[m_row][m_col],
                 int k_row, int k_col, int k[k_row][k_col], 
                 int out[m_row-k_row+1][m_col-k_col+1]){
    int i,j,x,y;
    int calc=0;
    for(x=0;x<m_row-k_row+1;x++){//percorre linha da matriz pela linha do kernel
        for(y=0;y<m_col-k_col+1;y++){//percorre coluna da matriz pela coluna do kernel
            for(i=0;i<k_row;i++){//percorre linha do kernel para calcular na matriz
                for(j=0;j<k_col;j++){//percorre coluna do kernel para calcular na matriz
                    calc=calc+m[i+x][j+y]*k[i][j];
                }
            }
            out[x][y]=calc;
            calc=0;
        }
    }
}

int main(){
    int matrix[M_ROW][M_COL]={
        {2,0,1,4,2,3},
        {1,1,2,3,3,3},
        {1,0,0,0,0,3},
        {5,5,5,4,7,8},
        {1,1,1,2,2,2},
        {5,5,5,5,5,5}
    };

    int kernel[K_ROW][K_COL]={
        {0,1,1},
        {1,-1,0},
        {1,-1,1}
    };

    int out[M_ROW - K_ROW + 1][M_COL - K_COL + 1];

    printf("Matriz Principal:\n");
    printMatrix(M_ROW,M_COL,matrix);
    printf("Kernel:\n");
    printMatrix(K_ROW,K_COL,kernel);

    convolution(M_ROW,M_COL,matrix,K_ROW,K_COL,kernel,out);
    
    printf("Nova Matriz:\n");
    printMatrix(M_ROW - K_ROW + 1, M_COL - K_COL + 1, out);
    
    return 0;
}