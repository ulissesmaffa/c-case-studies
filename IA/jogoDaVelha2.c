#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

//Estrutura de dados para tabuleiro
typedef struct node {
    int board[SIZE];
    struct node *next;
}Node;

void printNode(Node *n){
    int i;
    printf("Board:\n");
    for(i=0;i<SIZE;i+=3){
        printf("| %i | %i | %i\n",n->board[i],n->board[i+1],n->board[i+2]);
    }
    printf("Next: %p\n",n->next);
}

void initHead(Node *head){
    int i;
    for(i=0;i<SIZE;i++){
        head->board[i]=0;
    }
    head->next=NULL;
}

int result(Node *n, int player){
    int i,k=0;
    //Verifica linhas
    for(i=0;i<SIZE;i+=3){
        if (n->board[i]==player && n->board[i+1]==player && n->board[i+2]==player) {
            return 1;
        }
    }
    // Verificar colunas
    for (i = 0; i < 3; i++) {
        if (n->board[i]==player && n->board[i+3]==player && n->board[i+6]==player){
            return 2;
        }
    }
    // Verificar diagonal principal
    if (n->board[0] == player && n->board[4] == player && n->board[8] == player) {
        return 3;
    }
    // Verificar diagonal secundária
    if (n->board[2] == player && n->board[4] == player && n->board[6] == player) {
        return 4;
    }
    //Verifica se houve empate
    for(i=0;i<SIZE;i++){
        if(n->board[i]==1||n->board[i]==2){
            k++;
        }
    }
    if(k>=9){
        return 5; //empate
    }

    return 6; //não houve vencedor
}

void possiblePaths(Node *n, int player){
    int i,res;
    printNode(n);
    res=result(n,player);
    printf("Res: %i\n",res);
}

int main(){
    bool game=true; //variavel de controle do jogo
    int player=1; //variavel de indicacao de jogador - pode ser 1 ou 2s
    Node *head=(Node*)malloc(sizeof(Node));
    initHead(head);
    Node *current=head;
    printNode(current);

    do{
        possiblePaths(current,player);
        player = (player==1) ? 2 : 1; //alternancia entre jogadores 1 e 2
    }while(game);

    return 0;
}
