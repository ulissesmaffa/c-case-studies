/*
 * Preenchimento de Matriz 5x5 com Diagonal Principal
 * Este programa cria uma matriz 5x5, preenche a diagonal principal com 1s e os demais elementos com 0s, e exibe a matriz resultante.
 * A matriz é inicializada e preenchida dentro da função main().
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - A matriz é declarada com tamanho 5x5.
 * - Um loop duplo for é usado para percorrer a matriz.
 * - A condição i == j é usada para identificar os elementos da diagonal principal.
 * - Após o preenchimento, a matriz é exibida na tela com outro loop duplo for.
 */

#include <stdio.h>

#define ROW 5
#define COL 5

int main(){
    int m[ROW][COL];
    int i,j;
    
    //preechimento da matriz, 1 na diagonal e 0 no restante
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(i==j){
                m[i][j]=1;
            }else{
                m[i][j]=0;
            }
        }
    }

    //impressão matriz
    for(i=0;i<ROW;i++){
        printf("[%i] ",i);
        for(j=0;j<COL;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}