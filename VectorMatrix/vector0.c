/*
 * Manipulação de matriz e vetor
 *
 * Autor: Ulisses Maffazioli
 */

#include<stdio.h>
#define SIZE_V1 6
#define SIZE_V2 10

void insertVector(int *v, int size);
void insertVectorUniq(int *v, int size);
void printVector(int *v, int size);
void sortVector(int *v, int size);
int compVector(int *v1, int size1, int *v2, int size2);
void resultMega(int res);

int main(){
    int v1[SIZE_V1], v2[SIZE_V2];
    int res=0;

    //Preenchimento vetor 1 de 6 posições
    insertVectorUniq(v1,SIZE_V1);
    sortVector(v1,SIZE_V1);
    printf("Vetor 1:\n");
    printVector(v1,SIZE_V1);

    //Preenchimento vetor 2 de 10 posições
    insertVectorUniq(v2,SIZE_V2);
    sortVector(v2,SIZE_V2);
    printf("Vetor 2:\n");
    printVector(v2,SIZE_V2);

    //Compara os vetores e quantifica números em comum
    res=compVector(v2,SIZE_V2,v1,SIZE_V1);

    //resultado mega sena
    resultMega(res);

    return 0;
}

//Recebe vetor e tamanho desejado para fazer inserção de dados
void insertVector(int *v, int size){
    int i;

    printf("Digite %i valores:\n",size);
    for(i=0;i<size;i++){
        scanf("%i",&v[i]);
    }
}

//Recebe vetor e tamanho desejada para fazer inseção de dados únicos
void insertVectorUniq(int *v, int size){
    int i,j;

    printf("Digite %i valores diferentes de 1 até 60:\n",size);
    for(i=0;i<size;i++){
        scanf("%i",&v[i]);
        if(v[i]>60 || v[i]<1){
            printf("Valor não permitido, apenas de 1 até 60\n");
            i=i-1;   
        }
        for(j=0;j<i;j++){
            if(v[i]==v[j]){
                printf("Número repetido, tente novamente!\n");
                i=i-1;
            }
        }
    }
}

//Recebe vetor e seu tamanho para imprimir na tela
void printVector(int *v, int size){
    int i;

    for(i=0;i<size;i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}

//Recebe vetor e seu tamanho e ordena o vetor
void sortVector(int *v, int size){
    int i, aux;

    for(i=0;i<size-1;i++){
        // printf("v[%i]:%i - v[%i]:%i\n",i,v[i],i+1,v[i+1]);
        if(v[i]>v[i+1]){
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
            i=-1;
        }
    }
}

//Função recebe dois vetores com seus respectivos vetores 
//e compara o vetor 1 com o vetor 2 retornando quantos números tem em comum
int compVector(int *v1, int size1, int *v2, int size2){
    int i,j,res=0;

    for(i=0;i<size1;i++){
        for(j=0;j<size2;j++){
            if(v1[i]==v2[j]){
                res=res+1;
            }
        }
    } 
    return res;
}

//Função que imprime o resultadoda aposta
void resultMega(int res){
    if(res==0){
        printf("Nenhum acerto!\n");
    }else if(res<5){
        printf("Você acertou %i!\n",res);
    }else if(res==5){
         printf("Você acertou a Quina!\n");
    } else if(res==6){
         printf("Você acertou a Mega Sena!\n");
    }else{
        printf("Algo deu errado\n");
    }
}

/*
TESTES

NENHUM ACERTO:
    int v1[]={2,5,9,33,54,74};
    int v2[]={4,6,34,35,36,53,65,67,80,89};
UM ACERTO
    int v1[]={2,5,9,33,54,74};
    int v2[]={5,6,34,35,36,53,65,67,80,89};
DOIS ACERTOS
    int v1[]={2,5,9,33,54,74};
    int v2[]={5,6,33,35,36,53,65,67,80,89};
TRÊS ACERTOS
    int v1[]={2,5,9,33,54,74};
    int v2[]={5,6,33,35,36,54,65,67,80,89};
QUATRO ACERTOS
    int v1[]={2,5,9,33,54,74};
    int v2[]={2,5,33,35,36,54,65,67,80,89};
CINCO ACERTOS
    int v1[]={2,5,9,33,54,74};
    int v2[]={2,5,9,33,36,54,65,67,80,89};
SEIS ACERTOS 1
    int v1[]={2,5,9,33,54,74};
    int v2[]={2,5,9,33,36,54,65,67,74,89};
NUMEROS REPETIDOS
    int v1[]={2,5,9,9,54,54};
    int v2[]={2,5,9,33,33,54,65,74,74,89};
*/