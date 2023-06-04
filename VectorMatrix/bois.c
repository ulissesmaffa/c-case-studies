#include <stdio.h>
#define TAM 3

void inserirPeso(float *v){
    int i;
    printf("informar peso dos bois: \n");
    for(i=0;i<TAM;i++){
        do{
            printf("[%i]=",i);
            scanf("%f",&v[i]);
        }while(v[i]<0);
 
        
    }
}

void printVector(float *v){
    int i;
    printf("Print Vector:\n");
    for(i=0;i<TAM;i++){
        printf("[%i]=%.2f\n",i,v[i]);
    }
}

void atualizaPreco(float *peso, float *preco){
    int i;
    printf("Calcula preco:\n");
    for(i=0;i<TAM;i++){
        if(peso[i]>300){
            preco[i]=peso[i]*7.2;
        }else{
            preco[i]=peso[i]*5;
        }
    }
}

void magroGordo(float *peso, int *magro, int *gordo){
    int i;
    float aux_magro, aux_gordo;

    aux_magro=peso[0];
    aux_gordo=peso[0];
    for(i=0;i<TAM;i++){
        if(peso[i]<=aux_magro){
            *magro=i;
            aux_magro=peso[i];
        }

        if(peso[i]>=aux_gordo){
            *gordo=i;
            aux_gordo=peso[i];
        }
    }

    printf("Gordo=%i - Magro=%i\n",*gordo,*magro);
}

int main(){
    float v_peso[TAM],v_preco[TAM];
    int magro,gordo;

    inserirPeso(v_peso);
    printVector(v_peso);
    magroGordo(v_peso,&magro,&gordo);
    atualizaPreco(v_peso,v_preco);
    printVector(v_preco);

    return 0;
}