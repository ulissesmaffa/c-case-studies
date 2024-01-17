/*
 * Nome do Programa: Preenchimento e Manipulação de Matriz
 * Descrição: 
 *    Este programa cria uma matriz nxn de inteiros, com suas dimensões lidas do teclado.
 *    A matriz é inicialmente preenchida com zeros e, posteriormente, preenchida com números
 *    de 1 a 10000, utilizando alocação dinâmica de memória e aritmética de ponteiros para 
 *    manipulação da matriz. As funções incluem a criação, inicialização, preenchimento e
 *    impressão da matriz.
 * 
 * Autor: Ulisses Maffazioli
 * 
 * Notas:
 *    - O programa demonstra o uso de ponteiros duplos para manipulação de matrizes em C.
 *    - As funções principais incluem:
 *        - printMatrix: Imprime a matriz.
 *        - insertMatrix: Inicializa a matriz com zeros.
 *        - fillMatrix: Preenche a matriz com números de 1 a 10000.
 *    - A memória alocada para a matriz é liberada antes do término do programa.
 *    - Ref: https://www.youtube.com/watch?v=YNVKlEL2hpo&t=1343s
 */

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int row, int col, int **m){
    int i,j;
    for(i=0;i<row;i++){
        printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%i ",*(*(m+i)+j));  //usando aritimética de ponteiros
                                        // *(m+i) = valor que tem no endereço de um vetor, o vetor linha, que é o endereço do vetor
                                        // *(*(m+i)+j) = valor da coluna da linha apontada.
        }
        printf("\n");
    }
    printf("\nrow:%i x col:%i\n",row,col);
}

void insertMatrix(int row, int col, int **m){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            *(*(m+i)+j)=rand()%9;
        }
    }
}

int main(){
    int row,col;
    int **m;
    int i;

    printf("Digite qtd de linhas e qtd de colunas:\n");
    scanf("%i %i",&row,&col);

    m = (int **) malloc(row * sizeof(int*));//Alocando vetores de ponteiros que apontam para inteiros
    for(i=0;i<row;i++){
        m[i] = (int *) malloc(col * sizeof(int));//alocando vetor de inteiros
    }
    
    insertMatrix(row,col,m);
    printMatrix(row,col,m);

    return 0;
}



/*
int **matriz = (int **) malloc(n * sizeof(int *));
O que isso significa? Vamos explicar linha por linha:

int **matriz: declara um ponteiro duplo para int. Esse ponteiro irá apontar para o primeiro elemento da matriz. O uso de um ponteiro duplo é necessário para permitir que cada linha da matriz aponte para um bloco de memória alocado dinamicamente.

malloc(n * sizeof(int *)): aloca dinamicamente uma área de memória de tamanho n * sizeof(int *). Essa área de memória é usada para armazenar os ponteiros para as linhas da matriz. Em outras palavras, é alocado um bloco de memória para armazenar n ponteiros para inteiros.

(int **): faz um casting do ponteiro retornado por malloc() para um ponteiro duplo para inteiros. Isso é necessário porque malloc() retorna um ponteiro genérico do tipo void *.


*/