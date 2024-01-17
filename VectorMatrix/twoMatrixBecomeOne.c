/*
 * Manipulação de matriz 4x4
 *
 * Autor: Ulisses Maffazioli
 */
#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

void randomMatrix(int row, int col, int m[row][col]){
    int i,j;    
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=rand()%100;
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

void printVector(int *v, int size){
    int i;
    //imprime vetor que somam as duas matrizes
    for(i=0;i<size;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

//cria uma nova matriz ordenando os números somados das duas matrizes recebidas
//as 3 matrizes, precisam ter o mesmo tamanho.
void newMatrix(int row, int col, int m1[row][col], int m2[row][col], int m3[row][col]){
    int sizev=row*col*2;
    int v[sizev];
    int i,j,k=0,aux;

    //pega valores da matriz 1
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            v[k]=m1[i][j];
            k++;
        }
    }

    //pega valores da matriz 2
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            v[k]=m2[i][j];
            k++;
        }
    }

    //imprime vetor que somam as duas matrizes
    printVector(v,sizev);

    //ordena com algoritmo bubble sort o vetor
    for(i=0;i<sizev-1;i++){
        for(j=0;j<sizev-i-1;j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
    //imprime vetor ordenado
    printVector(v,sizev);
    
    //monta nova matriz tendo o vetor como origem de forma crescente
    k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m3[i][j]=v[k];
            k++;
        }
    }

}

int main(){
    printf("\n");
    int m1[ROW][COL];
    int m2[ROW][COL];
    int m3[ROW][COL];

    randomMatrix(ROW,COL,m1);
    randomMatrix(ROW,COL,m2);

    printf("Impressão Matriz 1:\n");
    printMatrix(ROW,COL,m1);
    printf("\n");
    printf("Impressão Matriz 2:\n");
    printMatrix(ROW,COL,m2);
    printf("\n");

    newMatrix(ROW,COL,m1,m2,m3);
    
    printf("Impressão Matriz 3:\n");
    printMatrix(ROW,COL,m3);

    printf("\n");
    return 0;
}