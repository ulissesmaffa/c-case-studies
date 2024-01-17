/*
 * Identificação do Maior Valor em uma Matriz 5x5
 * Este programa cria uma matriz 5x5 de inteiros, preenchida manualmente, 
 * e identifica a localização (linha e coluna) do maior valor na matriz.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A matriz é preenchida com valores definidos previamente no código.
 * - Um loop duplo for é utilizado para percorrer a matriz e identificar o maior valor e sua localização.
 * - A localização do maior valor na matriz é exibida ao final.
 */

#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int main(){
    int m[ROW][COL]={
        {3,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,60,19,20},
        {21,22,23,24,25}
    };
    int i,j,aux,iaux=0,jaux=0;

    //impressão matriz
    for(i=0;i<ROW;i++){
        printf("[%i] ",i);
        for(j=0;j<COL;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }

    //procura maior valor
    aux=m[0][0];
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(aux<m[i][j]){
                aux=m[i][j];
                iaux=i;
                jaux=j;
            }
        }
    }
    printf("Maior: m[%i][%i]= %i \n",iaux,jaux,aux);

    return 0;

}