#include <stdio.h>
#include <stdlib.h>

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