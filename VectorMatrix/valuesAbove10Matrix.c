/*
 * Manipulação de matriz 6x6
 *
 * Autor: Ulisses Maffazioli
 */

#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

void randomMatrix(int row, int col, int m[row][col]){
    int i,j;    
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=rand()%49;
        }
    }
}

void printMatrix(int row, int col, int m[row][col]){
    int i,j;    
    
    for(i=0;i<row;i++){
        printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }
}

void search10(int row, int col, int m[row][col]){
    int i,j,aux;    
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(m[i][j]>10){
                printf("%i ",m[i][j]);
                aux++;
            }
        }
    }
    printf("\nTotal: %i\n",aux);
}

int main(){
    int m1[ROW][COL];
    randomMatrix(ROW,COL,m1);
    printMatrix(ROW,COL,m1);
    search10(ROW,COL,m1);

    return 0;
}