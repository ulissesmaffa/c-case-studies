#include <stdio.h>
#include <stdlib.h>

//PROGRAMA SEM STRUCT
void inserirInfo(int *estoque, float *v_compra, float *v_venda, int qtd){
    int i;
    printf("Inserir dados dos produtos\n");
    for(i=0;i<qtd;i++){
        do{
            printf("Produto %i\n",i);
            printf("Estoque:");
            scanf("%i",&estoque[i]);
            printf("Valor de Compra:");
            scanf("%f",&v_compra[i]);
            printf("Valor de Venda:");
            scanf("%f",&v_venda[i]);
        }while(estoque[i]<0 || v_compra[i]<0 || v_venda[i]<0);
    }
}

void imprimirInfo(int *estoque, float *v_compra, float *v_venda, int qtd){
    int i;
    printf("\nProdutos cadastrados:\n");
    for(i=0;i<qtd;i++){
        printf("Produto %i - Estoque:%i - Valor Compra:%.2f - Valor Venda:%.2f\n",i,estoque[i],v_compra[i],v_venda[i]);
    }
}

int main(){
    int qtd;
    int *estoque;//quantidade estocada
    float *v_compra;//valor de compra
    float *v_venda;//valor de venda

    printf("Quantos produtos serão cadastrados?\n");
    scanf("%i",&qtd);

    //alocação de vetores dinamicos com type casting
    // estoque = (int *) malloc(qtd * sizeof(int));
    // v_compra = (float *) malloc(qtd * sizeof(float));
    // v_venda = (float *) malloc(qtd * sizeof(float));

    //alocação de vetores dinamicos sem type casting
    estoque = malloc(qtd * sizeof(int));
    v_compra = malloc(qtd * sizeof(float));
    v_venda = malloc(qtd * sizeof(float));

    inserirInfo(estoque,v_compra,v_venda,qtd);
    imprimirInfo(estoque,v_compra,v_venda,qtd);

    //liberação de memória com FREE
    free(estoque);
    free(v_compra);
    free(v_venda);

    return 0;
}