#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
}nodo;

int menuSistema(){
    int n;
    bool error=false;

    do{
        printf("===========================================================\n");
        printf("MENU INICIAL DO SISTEMA:\n");
        printf("===========================================================\n");
        printf("Digite [1] para INSERIR FINAL DA FILA\n");
        printf("Digite [2] para INSERIR INICIO DA FILA\n");
        printf("Digite [3] para INSERIR MEIO DA FILA\n");
        printf("Digite [4] para MOSTRAR FILA\n");
        printf("Digite [5] para EXCLUIR ITEM DA FILA\n");
        printf("Digite [9] para SAIR\n");
        scanf("%i",&n);
        printf("===========================================================\n");
        if(n==1||n==2||n==3||n==4||n==5||n==9){
            error=false;
        }else{
            printf("Erro! digite um número válido\n");
            error=true;
        }
    }while(error);

    return n;
}

int getValor(){
    bool error=false;
    int num;

    printf("Informe um valor:");
    scanf("%i",&num);

    return num;
}

nodo* aloca(){
    nodo *p;
    p=(nodo*)malloc(sizeof(nodo));

    if(p!=NULL){
        return p;
    }else{
        return NULL;
    }
}

void mostrarFila(nodo *inicio){
    bool continua=true;
    nodo *aux;
    aux=inicio;

    printf("MOSTRAR FILA\n");
    if(inicio==NULL){
        printf("A fila está vazia!\n");
    }else{
        while(continua){
            if(aux->prox==NULL){//esse é o ultimo cara - imprime e acaba o while
                printf("%i\n",aux->dado);
                continua=false;
            }else{
                printf("%i -> ",aux->dado);
                aux=aux->prox;
            }
        }
    }
}

void mostrarFilaIndex(nodo *inicio){

    bool continua=true;
    nodo *aux;
    aux=inicio;
    int i=0;

    printf("MOSTRAR FILA COM INDEX\n");

    while(continua){
        if(aux->prox==NULL){//esse é o ultimo cara - imprime e acaba o while
            printf(" [%i]%i\n",i,aux->dado);
            continua=false;
        }else{
            printf(" [%i]%i ->",i,aux->dado);
            aux=aux->prox;
            i++;
        }
    }
}

void insereFinal(nodo **inicio, nodo **pont, nodo **proximo){
    bool continua=true;
    printf("INSERE FINAL DA FILA\n");
    printf("Endereço de 'inicio'= %p - Valor do endereço que 'inicio' está apontando= %p\n",inicio,*inicio);
    printf("Endereço de 'pont'= %p - Valor do endereço que 'pont' está apontando= %p\n",pont,*pont);
    printf("Endereço de 'proximo'= %p - Valor do endereço que 'proximo' está apontando= %p\n",proximo,*proximo);
    
    //Novo endereço para pont
    *pont=(nodo *)malloc(sizeof(nodo));
    

    if(*pont!=NULL){
        printf("Endereço de 'pont'= %p - Recebe novo valor do endereço que 'pont'= %p\n",pont,*pont);
        //Verifica se inicio já existe, caso seja null, esse é o primeiro elemento da lista e será o inicio
        if(*inicio==NULL){
            printf("primeiro elemento da lista que será colocado no inicio\n");
            *inicio=*pont;//O valor do ponteiro incio recebe o valor de pont
            printf("Novo endereço de Inicio: %p\n",*inicio);
            (*inicio)->dado=getValor();//preenchimento do dado
            (*inicio)->prox=NULL;//prox de inicio é null, a partir do segundo elemento, esse valor passa a apontar para o segundo
        }else{//Caso onde já existe um inicio, ou seja, pode ser segundo, terceiro, etc...
            (*pont)->dado=getValor();//Novo elemento recebe dado
            (*pont)->prox=NULL;//Como é insere no fim, prox do novo elemento é NULL, ele será o último elemento da lista
            *proximo=*inicio;//próximo será resposável por percorrer a lista e verificar quem é o ATUAL ÚLTIMO elemento
            while(continua){
                if((*proximo)->prox==NULL){//verifica se o prox do próximo é NULL, ou seja, se é o último da lista
                    (*proximo)->prox=*pont;//se for o último, o seu prox que antes era NULL irá apontar para pont, que é o novo elemento
                    continua=false;//condição de parada do while
                }else{//caso proximo não seja o último da lista, atualiza o próximo pelo seu próprio valor de prox e continua o laço
                    *proximo=(*proximo)->prox;
                }
            }
        }
    }else{
        printf("Erro na alocação de memória para Pont\n");
    }
} 

void insereInicio(nodo **inicio, nodo **pont){
    printf("INSERE NO INICIO\n");

    *pont=aloca();
    if(*pont!=NULL){
        printf("Endereço de 'pont'= %p - Recebe novo valor do endereço que 'pont'= %p\n",pont,*pont);
        if(*inicio==NULL){
            printf("Será o primeiro elemento na lista\n");
            *inicio=*pont;
            (*inicio)->dado=getValor();
            (*inicio)->prox=NULL;
        }else{
            (*pont)->dado=getValor();
            (*pont)->prox=*inicio;
            *inicio=*pont;
        }
    }else{
        printf("Erro ao alocar! Tentar novamente\n");
    }
}

nodo* verificaIndex(int index, nodo *inicio){
    bool continua=true;
    nodo *aux;
    aux=inicio;
    int i=0;

    if(aux==NULL){
        printf("Nenhum elemento na lista!\n");
        return NULL;
    }else{
        do{
            if(index==i){
                printf("Index encontrado!\n");
                return aux;
            }
            if(aux->prox==NULL){
                continua=false;
            }else{
                aux=aux->prox;
                i++;
                continua=true;
            }
        }while(continua);
        printf("Nenhum index foi encontrado!\n");
        return NULL;
    }
}

void insereMeio(nodo **inicio, nodo **pont){
    bool continua=true;
    int index;
    nodo *aux;

    *pont=aloca();
    if(*pont!=NULL){
        if(*inicio==NULL){
            printf("Será o primeiro elemento na lista\n");
            *inicio=*pont;
            (*inicio)->dado=getValor();
            (*inicio)->prox=NULL;
        }else{
            do{
                mostrarFilaIndex(*inicio);
                printf("Escolha um elemento da lista para adicionar a sua direita: ");
                scanf("%i",&index);
                aux=verificaIndex(index,*inicio);
                if(aux!=NULL){
                    printf("O novo elemento será inserido a direita do index: %i\n",index);
                    (*pont)->dado=getValor();
                    (*pont)->prox=aux->prox;
                    aux->prox=*pont;
                    continua=false;
                }else{
                    continua=true;
                }
            }while(continua);
        }
    }else{
        printf("Erro ao alocar! Tentar novamente\n");
    }
}

void excluirFila(nodo **inicio){
    bool continua=true;
    int index;
    nodo *aux, *anterior;
    if(*inicio==NULL){
        printf("A fila está vazia!\n");
    }else{
        do{
            mostrarFilaIndex(*inicio);
            printf("Escolha um elemento para excluir: ");
            scanf("%i",&index);
            aux=verificaIndex(index,*inicio);
            if(aux!=NULL){
                printf("O novo elemento %i será excluído\n",index);
                if(aux==*inicio){//se o elemento é o primeiro
                    if(aux->prox==NULL){//se existe apenas um
                        *inicio=NULL;
                        free(*inicio);
                    }else{//se o elemento é o primeiro
                        *inicio=(*inicio)->prox;
                        free(aux);
                    }
                }else{//se o elemento é o último ou o no meio 
                    if(aux->prox==NULL){//é o último
                        anterior=*inicio;
                        while(anterior->prox!=aux){
                            anterior=anterior->prox;
                        }
                        anterior->prox=NULL;
                        free(aux);
                    }else{//esta no meio
                        anterior=*inicio;
                        while(anterior->prox!=aux){
                            anterior=anterior->prox;
                        }
                        anterior->prox=aux->prox;
                        free(aux);
                    }
                }
                continua=false;
            }else{
                continua=true;
            }
        }while(continua);
    }
}

int main(){
    bool continua=true;
    int num;

    nodo *inicio = NULL;
    printf("Ponteiro 'inicio' criado com valor: %p - que tem endereço: %p\n",inicio,&inicio);
    nodo *pont;
    printf("Ponteiro 'pont' criado com valor: %p - que tem endereço: %p\n",pont,&pont);
    nodo *proximo;
    printf("Ponteiro 'proximo' criado com valor: %p - que tem endereço: %p\n",proximo,&proximo);    

    do{
        num=menuSistema();
        switch (num){
            case 1://insere no final
                insereFinal(&inicio,&pont,&proximo);
                break;
            case 2://insere no inicio
                insereInicio(&inicio,&pont);
                break;
            case 3://insere no meio
                insereMeio(&inicio,&pont);
                break;
            case 4://mostrar fila
                mostrarFila(inicio);
                break;
            case 5://excluir da fila
                excluirFila(&inicio);
                break;
            case 9:
                    continua=false;
                break;
        }
    }while(continua);

    return 0;
}