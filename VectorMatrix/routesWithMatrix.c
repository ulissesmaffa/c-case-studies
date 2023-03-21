/*
Questão 16 da lista
*/

#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"

#define ROW 6
#define COL 6
#define SIZE_V 6

void createMatrix(int row, int col, int m[row][col]){
    int i,j;
    int temp[ROW][COL] = {
        {0,  63,  210, 190, 20,  190},
        {63, 0,   160, 150, 95,  83},
        {210,160, 0,   10,  12,  32},
        {190,150, 10,  0,   2,   41},
        {20, 95,  12,  2,   0,   80},
        {190,83,  32,  41,  80,  0}
    };
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=temp[i][j];
        }
    }
}

void calcDistance(int *v, int size, int row, int col, int m[row][col]){
    int k;
    int aux=0;
    printf("\n");
    for(k=0;k<size-1;k++){
        printf("Percorrer de %i até %i = %i\n",v[k],v[k+1],m[v[k]][v[k+1]]);
        aux=aux+m[v[k]][v[k+1]];
    }

    printf("Distância total: %i\n",aux);
}

int main(){
    int m[ROW][COL];
    int v[SIZE_V]={2,3,1,4,5,0};
    int i;

    createMatrix(ROW,COL,m);
    printMatrix(ROW,COL,m);
    //vetor de deslocamento
    printf("Vetor de deslocamento: ");
    for(i=0;i<SIZE_V;i++){
        printf("%i ",v[i]);
    }
    calcDistance(v,SIZE_V,ROW,COL,m);

    return 0;
}