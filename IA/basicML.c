#include <stdio.h>

#define ROW 4
#define COL 2

void mostrarMatriz(int row, int col, float m[row][col]){
    int i,j;    
    for(i=0;i<row;i++){
        printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%.2f ",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    float m[ROW][COL]={
        {0,0},
        {0,1},
        {1,0},
        {1,1}
    };

    int input[2];
    input[0]=1;
    input[1]=0;

    mostrarMatriz(ROW,COL,m);

    return 0;
}