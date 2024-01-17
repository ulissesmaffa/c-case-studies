/*
 * Manipulação de matriz 15 x 15
 *
 * Autor: Ulisses Maffazioli
 */

#include <stdio.h>
#include <stdlib.h>
#include "ulissesMatrix.h"
#include <time.h>

#define ROW 15
#define COL 10
#define SIZE_V 10

char createRandomLetter(){
    int random_num = rand() % 4; // gera um número aleatório entre 0 e 3
    char random_letter = 'a' + random_num; // mapeia o número para uma letra entre 'a' e 'd'
    return random_letter;
}

void createGradesMatrix(int row, int col, char m[row][col]){
    int i,j;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=createRandomLetter();
        }
    }
}

void printMatrixChar(int row, int col, char m[row][col]){
    int i,j;    
    
    for(i=0;i<row;i++){
        printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%c ",m[i][j]);
        }
        printf("\n");
    }
}

void createAnswer(char *v, int size){
    int i;

    for(i=0;i<size;i++){
        v[i]=createRandomLetter();
    }
}

void printVector(char *v, int size){
    int i;

    printf("Gabarito: ");
    for(i=0;i<size;i++){
        printf("%c ",v[i]);
    }
    printf("\n");
}

void calcResult(char *v, int size, int row, int col, char m[row][col]){
    int vaux[size];
    int i,j,k=0,aux=0;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(m[i][j]==v[k]){
                aux++;
            }
            //ultima nota do aluno, fazer o fechamento da nota
            if(j==col-1){
                printf("Aluno %i acertou: %i\n",i,aux);
                aux=0;
            }
            k++;
        }
    k=0;
    }
}

int main(){
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    char m[ROW][COL];
    char v[SIZE_V];

    createGradesMatrix(ROW,COL,m);
    printMatrixChar(ROW,COL,m);
    createAnswer(v,SIZE_V);
    printVector(v,SIZE_V);
    calcResult(v,SIZE_V,ROW,COL,m);

    return 0;
}