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

// typedef struct{
//     int id;
//     struct Node *north;
//     struct Node *east;
//     struct Node *south;
//     struct Node *west;
// }Node;

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

void path(Cell *cells, int start){
    int i,s_row,s_col,num;
    i=start;
    printf("\nPath:\n");
    for(i=start;i<ROW;i++){
        if(cells[i].north==1){
            s_row=cells[i].row - 1;//linha de cima
            s_col=cells[i].col;//mesma coluna
            num=numCell(cells,s_row,s_col);
            printf("CN:%i -> %i\n",i,num);
        }
        if(cells[i].east==1){
            s_row=cells[i].row;//mesma linha
            s_col=cells[i].col + 1;//coluna do lado direito
            num=numCell(cells,s_row,s_col);
            printf("CL:%i -> %i\n",i,num);
        }
        if(cells[i].south==1){
            s_row=cells[i].row+1;//linha de baixo
            s_col=cells[i].col;//mesma coluna
            num=numCell(cells,s_row,s_col);
            printf("CS:%i -> %i\n",i,num);
        }
        if(cells[i].west==1){
            s_row=cells[i].row;//mesma linha
            s_col=cells[i].col - 1;//coluna do lado esquerdo
            num=numCell(cells,s_row,s_col);
            printf("CO:%i -> %i\n",i,num);
        }
        printf("\n");
    }
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
    int start;

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