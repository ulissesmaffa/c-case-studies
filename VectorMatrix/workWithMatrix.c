#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 4
#define COL 4

void printDivider(){
    printf("========================\n");
}

void printMatrix(int row, int col, int m[row][col], int id){
    int i,j;    
    
    printf("Impressão da Matriz: %i\n",id);
    for(i=0;i<row;i++){
        printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }
    printDivider();
}

//funcao que troca o valor que tem no ponteiro 1 para o valor que tem no ponteiro 2
void swapTwoValue(int *p1, int *p2){
    int aux;

    aux=(*p1);
    (*p1)=(*p2);
    (*p2)=aux;
}

//percorre toda a matriz e vai comparado o primeiro com o próximo
void bubbleSortMatrix(int row, int col, int m[row][col]){
    int i,j,aux,num1,num2;
    bool newline=false;
    for(i=0;i<row;){
        for(j=0;j<col;){
            num1=m[i][j];
            if(j==col-1){
                num2=m[i+1][0];//pega primeiro da próxima coluna
                newline=true;
                if(i==col-1){
                    break;
                }
            }else{
                num2=m[i][j+1];
                newline=false;
            }
            
            //compara dois números
            if(num1>num2){
                if(newline){
                    swapTwoValue(&m[i][j],&m[i+1][0]);
                }else{
                    swapTwoValue(&m[i][j],&m[i][j+1]);
                }
                i=0;
                j=0;
            }else{
                j++;
            }         
        }
        i++;    
    }
}

void printVector(int *v, int size){
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf("%i ",v[i]);
    }
    printf("\n\n");
}

//método 2 para testar desempenho - com vetor aux
void bubbleSortMatrix2(int row, int col, int m[row][col]){
    int i,j,k=0,aux;
    int sizev=row*col;
    int v[sizev];
    
    //transfere matriz para vetor
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            v[k]=m[i][j];
            k++;
        }
    }

    //ordena vetor
    for(i=0;i<sizev-1;i++){
        if(v[i]>v[i+1]){
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
            i=-1;
        }
    }
    printVector(v,sizev);

    //transfere vetor para matriz
    k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=v[k];
            k++;
        }
    }
}

//método 3 para testar desempenho - com vetor aux e bubble sort correto
void bubbleSortMatrix3(int row, int col, int m[row][col]){
    //animação para entender bubblesort: https://www.youtube.com/watch?v=cB0oY1oZzng
    int i,j,k=0,aux;
    int sizev=row*col;
    int v[sizev];
    
    //transfere matriz para vetor
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            v[k]=m[i][j];
            k++;
        }
    }

    //ordena vetor
    for(i=0;i<sizev-1;i++){
        for(j=0;j<sizev-i-1;j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
    printVector(v,sizev);

    //transfere vetor para matriz
    k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=v[k];
            k++;
        }
    }

}

void randomMatrix(int row, int col, int m[row][col]){
    int i,j;    
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=rand()%100;
        }
    }
}

void createMatrix(int row, int col, int m[row][col]){
    int i,j;
    int temp[ROW][COL] = {
        {7,49,73,58},
        {30,72,44,78},
        {23,9,40,65},
        {92,42,87,3}
    };
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=temp[i][j];
        }
    }
}

int main(){
    int id=0;
    int m1[ROW][COL];
    int i,j;

    //método 1
    clock_t start1 = clock();
    printf("\nMétodo 1 - ordenando diretamente na matriz\n");
    // randomMatrix(ROW,COL,m1);
    createMatrix(ROW,COL,m1);
    printMatrix(ROW,COL,m1,id=1);
    bubbleSortMatrix(ROW,COL,m1);
    printMatrix(ROW,COL,m1,id=1);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    //método 2
    clock_t start2 = clock();
    printf("\nMétodo 2 - ordenando com vetor auxiliar\n");
    // randomMatrix(ROW,COL,m1);
    createMatrix(ROW,COL,m1);
    printMatrix(ROW,COL,m1,id=1);
    bubbleSortMatrix2(ROW,COL,m1);
    printMatrix(ROW,COL,m1,id=1);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    
    //método 3
    clock_t start3 = clock();
    printf("\nMétodo 3 - ordenando com vetor auxiliar e fazendo o bubble sort correto\n");
    // randomMatrix(ROW,COL,m1);
    createMatrix(ROW,COL,m1);
    printMatrix(ROW,COL,m1,id=1);
    bubbleSortMatrix3(ROW,COL,m1);
    printMatrix(ROW,COL,m1,id=1);
    clock_t end3 = clock();
    double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execução do método 1: %lf segundos\n", time1);
    printf("Tempo de execução do método 2: %lf segundos\n", time2);
    printf("Tempo de execução do método 3: %lf segundos\n\n", time3);

    return 0;
}