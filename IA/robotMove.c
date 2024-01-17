/*
 * Exploração de Labirinto com Busca em Profundidade (DFS)
 * Cria um labirinto utilizando uma estrutura de dados 'Cell' e explora caminhos através de uma árvore.
 * A exploração é realizada usando o algoritmo de busca em profundidade (DFS).
 * O programa identifica caminhos do ponto de partida até a saída do labirinto.
 *
 * Autor: Ulisses Maffazioli
 */

#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 7

typedef struct{
    int row;   // linha
    int col;   // coluna
    int north; // conectividade Norte
    int east;  // conectividade Leste
    int south; // conectividade Sul
    int west;  // conectividade Oeste
    int type;  // Tipo de célula (0 para vazia, 1 para inicial, 2 para final)
}Cell;

typedef struct TreeNode {
    int id;
    int type;
    struct TreeNode *parent;
    struct TreeNode *children[4];
} TreeNode;

void printMatrix(int m[ROW][COL]){
    int i,j;
    //impressão indices coluna
    printf("   ");
    for(i=0;i<COL;i++){
        printf("[%i]",i);
    }
    printf("\n");
    //impressão indices linhas e respectivos valores do labirinto
    for(i=0;i<ROW;i++){
        printf("[%i] ",i);
        for(j=0;j<COL;j++){
            printf("%i  ",m[i][j]);
        }
        printf("\n");
    }
}

void createCells(int m[ROW][COL], Cell *cells){
    int i;
    for(i=0;i<ROW;i++){
        cells[i].row   = m[i][0];
        cells[i].col   = m[i][1];
        cells[i].north = m[i][2];
        cells[i].east  = m[i][3];
        cells[i].south = m[i][4];
        cells[i].west  = m[i][5];
        cells[i].type  = m[i][6];
    }  
}

void printCells(Cell *cells){
    int i;
    for(i=0;i<ROW;i++){
        printf("[%i] %i %i %i %i %i %i %i\n",i, cells[i].row, cells[i].col,
        cells[i].north, cells[i].east, cells[i].south, cells[i].west, cells[i].type);
    }
    
}

int numCell(Cell *cells, int row, int col){
    int i,j,num;

    //Define célula de start
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(cells[i].row==row && cells[i].col==col){
                num=i;
            }
        }
    }
    return num;
}

int endCell(Cell *cells){
    int i,j,num;

    //Define célula de start
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(cells[i].type==2){
                num=i;
            }
        }
    }
    return num;
}

void dfs(Cell *cells, int start, TreeNode *parent, int visited[ROW]) {
    visited[start] = 1;//marca o node start como visitado
    int t;
    for (int i = 0; i < 4; i++) {
        if (cells[start].north && i == 0) {
            int next_id = numCell(cells, cells[start].row - 1, cells[start].col);
            if (!visited[next_id]) {
                TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
                node->id = next_id;
                node->parent = parent;
                parent->children[0] = node;
                
                t=cells[next_id].type;
                node->type = cells[next_id].type;

                dfs(cells, next_id, node, visited);
            }
        } else if (cells[start].east && i == 1) {
            int next_id = numCell(cells, cells[start].row, cells[start].col + 1);
            if (!visited[next_id]) {
                TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
                node->id = next_id;
                node->parent = parent;
                parent->children[1] = node;

                t=cells[next_id].type;
                node->type = cells[next_id].type;

                dfs(cells, next_id, node, visited);
            }
        } else if (cells[start].south && i == 2) {
            int next_id = numCell(cells, cells[start].row + 1, cells[start].col);
            if (!visited[next_id]) {
                TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
                node->id = next_id;
                node->parent = parent;
                parent->children[2] = node;

                t=cells[next_id].type;
                node->type = cells[next_id].type;

                dfs(cells, next_id, node, visited);
            }
        } else if (cells[start].west && i == 3) {
            int next_id = numCell(cells, cells[start].row, cells[start].col - 1);
            if (!visited[next_id]) {
                TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
                node->id = next_id;
                node->parent = parent;
                parent->children[3] = node;

                t=cells[next_id].type;
                node->type = cells[next_id].type;

                dfs(cells, next_id, node, visited);
            }
        }
    }
}

void printTree(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    printf("\n%d", node->id);
    printTree(node->children[0]);
    printTree(node->children[1]);
    printTree(node->children[2]);
    printTree(node->children[3]);
}

void printExitTree(TreeNode *node, int *found_exit) {
    if (*found_exit || node == NULL) {
        return;
    }
    printf("\n%d", node->id);
    if (node->type == 2) {
        *found_exit = 1;
    }
    printExitTree(node->children[0], found_exit);
    printExitTree(node->children[1], found_exit);
    printExitTree(node->children[2], found_exit);
    printExitTree(node->children[3], found_exit);
}

void path(Cell *cells, int start){
    printf("Path:\n");
    int visited[ROW] = {0};//vetor que controla cell que foram visitadas na busca em profundidade
    int found_exit = 0; // Inicializa a variável found_exit com 0
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));//node iniciar da árvore
    root->id = start;//recebe ID start
    dfs(cells, start, root, visited);
    printf("\nMostrar toda árvore:");
    printTree(root);

    printf("\nMostrar até destino:");
    printExitTree(root, &found_exit);
    printf("\n");
}

int main(){
    //{ROW, COL, NORTH, EAST, SOUTH, WEST, TYPE(0=empty;1=start;2=target)}
    int maze[ROW][COL]={
    //   r  c  n  l  s  o  t
        {0, 0, 0, 1, 0, 0, 1},//0
        {0, 1, 0, 1, 1, 1, 0},//1
        {0, 2, 0, 0, 0, 1, 0},//2

        {1, 0, 0, 1, 1, 0, 0},//3
        {1, 1, 1, 1, 1, 1, 0},//4
        {1, 2, 0, 0, 0, 1, 0},//5

        {2, 0, 1, 0, 0, 0 ,0},//6
        {2, 1, 1, 1, 0, 0, 0},//7
        {2, 2, 0, 0, 0, 1, 2} //8
    };
    
    Cell cells[ROW];
    //Define inicio
    int sel_row=0;
    int sel_col=0;
    int start,end;

    printf("\nImpressão do Labirinto:\n");
    printMatrix(maze);

    createCells(maze,cells);
    printf("\nImpressão do Células:\n");
    printCells(cells);
    
    start=numCell(cells,sel_row,sel_col);
    printf("\nCélula Start:%i\n",start);

    path(cells,start);
    
    return 0;
}