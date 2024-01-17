/*
 * Nome do Programa: Manipulação de Vetores
 * Descrição: 
 *    Este programa demonstra a inserção e impressão de elementos em um vetor dinâmico em C. 
 *    O usuário insere o tamanho do vetor, e o programa preenche o vetor com números aleatórios
 *    e, em seguida, imprime os valores armazenados e o tamanho do vetor.
 * 
 * Autor: Ulisses Maffazioli
 * 
 * Notas:
 *    - Este programa foi desenvolvido como parte de um projeto acadêmico.
 *    - O programa utiliza alocação dinâmica de memória para o vetor.
 *    - Funções utilizadas: 
 *        - insertVector: Insere valores aleatórios no vetor.
 *        - printVector: Imprime os valores do vetor e seu tamanho.
 */

#include <stdio.h>
#include <stdlib.h>

void insertVector(double *v, int size){
    int i;
    for(i=0;i<size;i++){
        v[i]=rand()%50;
    }
}

void printVector(double *v, int size){
    int i,tam=0;
    for(i=0;i<size;i++){
        printf("%2.f ",v[i]);
        tam++;
    }
    printf("\ntam:%i\n",tam);
}

int main(){
    int qtd;
    double *v;
    printf("Digite quantidade:\n");
    scanf("%d",&qtd);

    v = (double *) malloc(qtd * sizeof(double)); 

    insertVector(v,qtd); 
    printVector(v,qtd); 

    free(v);
    
    return 0;
}