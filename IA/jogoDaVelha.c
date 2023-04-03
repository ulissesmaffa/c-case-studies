/*
Faça um programa para gerar todas as possibilidades para uma partida de jogo da velha.
Escolha uma estrutura de dados para armazenar estas possibilidades.
Represente cada tabuleiro que está armazenado em uma posição da estrutura como um vetor de 9 posições, 
onde são representadas as linhas do tabuleiro conforme a figura {1,2,3,4,5,6,7,8,9}.
Em cada posição pode ter ‘O’, ’X’ ou ‘ ‘ (espaço).
Na estrutura de dados deve ser possível localizar para um determinado estado do tabuleiro 
quais são os possíveis próximos estados.
Deve ser possível acompanhar os movimentos na estrutura indicando-se manualmente a próxima jogada.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_V 9

void resultadoSemPrint(int jogador, int *v, int size, bool *jogo){
    int i,k=0;
    // printf("[Sistema] Estou dentro da função resultado\n");
    // printf("[Sistema] Variáveis que recebi\nJogador: %i\nJogo: %d\nSize: %i\n",jogador,*jogo,size);
    //verifica linhas
    for(i=0;i<size;i+=3){
        // printf("Linha %i: [%i]=%i [%i]=%i [%i]=%i\n",i,i,v[i],i+1,v[i+1],i+2,v[i+2]);
        if (v[i] == jogador && v[i+1] == jogador && v[i+2] == jogador) {
            // printf("Jogador %i venceu completando a LINHA %i\n",jogador,i);
            *jogo=false;
        }
    }
    // Verificar colunas
    for (i = 0; i < 3; i++) {
        // printf("Coluna %i: [%i]=%i [%i]=%i [%i]=%i\n",i,i,v[i],i+1,v[i+1],i+2,v[i+2]);
        if (v[i] == jogador && v[i+3] == jogador && v[i+6] == jogador) {
            // printf("Jogador %i venceu completando a COLUNA %i\n",jogador,i);
            *jogo=false;
        }
    }

    // Verificar diagonal principal
    if (v[0] == jogador && v[4] == jogador && v[8] == jogador) {
        // printf("Jogador %i venceu completando a DIAGONAL PRINCIPAL\n",jogador);
        *jogo=false;
    }

    // Verificar diagonal secundária
    if (v[2] == jogador && v[4] == jogador && v[6] == jogador) {
        // printf("Jogador %i venceu completando a DIAGONAL SECUNDARIA\n",jogador);
        *jogo=false;
    }
    // Resultado empate
    for(i=0;i<size;i++){
        if(v[i]==1||v[i]==2){
            k++;
        }
    }
    if(k>=9){
        // printf("Jogo empatado\n");
        *jogo=false;
    }
}

void resultadoComPrint(int jogador, int *v, int size, bool *jogo){
    int i,k=0;
    // printf("[Sistema] Estou dentro da função resultado\n");
    // printf("[Sistema] Variáveis que recebi\nJogador: %i\nJogo: %d\nSize: %i\n",jogador,*jogo,size);
    //verifica linhas
    for(i=0;i<size;i+=3){
        // printf("Linha %i: [%i]=%i [%i]=%i [%i]=%i\n",i,i,v[i],i+1,v[i+1],i+2,v[i+2]);
        if (v[i] == jogador && v[i+1] == jogador && v[i+2] == jogador) {
            printf("Jogador %i venceu completando a LINHA %i\n",jogador,i);
            *jogo=false;
        }
    }
    // Verificar colunas
    for (i = 0; i < 3; i++) {
        // printf("Coluna %i: [%i]=%i [%i]=%i [%i]=%i\n",i,i,v[i],i+1,v[i+1],i+2,v[i+2]);
        if (v[i] == jogador && v[i+3] == jogador && v[i+6] == jogador) {
            printf("Jogador %i venceu completando a COLUNA %i\n",jogador,i);
            *jogo=false;
        }
    }

    // Verificar diagonal principal
    if (v[0] == jogador && v[4] == jogador && v[8] == jogador) {
        printf("Jogador %i venceu completando a DIAGONAL PRINCIPAL\n",jogador);
        *jogo=false;
    }

    // Verificar diagonal secundária
    if (v[2] == jogador && v[4] == jogador && v[6] == jogador) {
        printf("Jogador %i venceu completando a DIAGONAL SECUNDARIA\n",jogador);
        *jogo=false;
    }
    // Resultado empate
    for(i=0;i<size;i++){
        if(v[i]==1||v[i]==2){
            k++;
        }
    }
    if(k>=9){
        printf("Jogo empatado\n");
        *jogo=false;
    }
}

int possibilidades_recursivo(int *v, int size, int jogador) {
    int i, k = 0;
    bool jogo = true;
    for (i = 0; i < size; i++) {
        if (v[i] == 0) {
            int v_temp[size];
            memcpy(v_temp, v, sizeof(int) * size);
            v_temp[i] = jogador;
            bool jogo_temp = true;
            resultadoSemPrint(jogador, v_temp, size, &jogo_temp);
            if (jogo_temp) {
                int num_possibilidades = possibilidades_recursivo(v_temp, size, jogador == 1 ? 2 : 1);
                k += num_possibilidades;
            }
        }
    }
    if (k == 0) k = 1;
    return k;
}

void possibilidades(int *v, int size){
    int i, k = 0;
    for (i=0;i<size;i++){
        if (v[i]==0) {
            int v_temp[size];
            memcpy(v_temp, v, sizeof(int) * size);
            v_temp[i] = 1;
            bool jogo_temp = true;
            resultadoSemPrint(1, v_temp, size, &jogo_temp);
            if (jogo_temp) {
                k += possibilidades_recursivo(v_temp, size, 2);
            }
        }
    }
    printf("Total de possibilidades: %i\n", k);
}

void impressaoTabuleiro(int *v, int size){
    //0 = livre
    //1 = X
    //2 = O
    int i,k=0;
    printf("\n");
    printf("Impressão do Tabuleiro:\n");
    for(i=0;i<size;i++){
        switch (v[i])
        {
        case 0:
            printf("%i  ",i);//impressao da posição
            break;
        case 1:
            printf("X  ");//impressao X
            break;
        case 2:
            printf("O  ");//impressao bola
            break;
        default:
            printf("%i ",v[i]);
            break;
        }
        k++;
        if(k==3){
            printf("\n");
            k=0;
        }
    }
    printf("\n");
}

void jogar(int jogador, int *v, int size, bool *jogo){
    int pos, i;
    bool erro=false;
    printf("Sou o jogador: %i\n",jogador);
    printf("Escolha uma posição para jogar: ");
    
    do{
        scanf("%i",&pos);
        if(pos<0||pos>8){
            printf("Posição inválida [1], escolha novamente: ");
            erro=true;
        }else{
            if(v[pos]==0){
                printf("Posição válida\n");
                if(jogador==1){
                    v[pos]=1;
                }else{
                    v[pos]=2;
                }
                impressaoTabuleiro(v,size);
                erro=false;
                // printf("[Sistema] Vou verificar o resultado\n");
            }else{
                printf("Posição inválida [2], escolha novamente: ");
                erro=true;
            }
        }
    }while(erro);
}

int main(){
    int v[SIZE_V]={0,0,0,0,0,0,0,0,0};
    bool jogo=true;
    int jogador=1;
    int numJogada=0;
    impressaoTabuleiro(v,SIZE_V);
    do{
        // impressaoTabuleiro(v,SIZE_V);
        if(numJogada<=8){//verifica numero de jogadas
            possibilidades(v,SIZE_V);
            jogar(jogador,v,SIZE_V,&jogo);
            resultadoComPrint(jogador,v,SIZE_V,&jogo);
            jogador = (jogador==1) ? 2 : 1; // alterna entre os jogadores 1 e 2
            numJogada++;
        }else{
            jogo=false;
            printf("O jogo acabou empatado\n");
        }

    }while(jogo);


    return 0;
}