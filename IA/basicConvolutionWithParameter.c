#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

void printMatrix(int row, int col, int m[row][col]){
    int i,j;    
    for(i=0;i<row;i++){
        // printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }
}

void convolution(
                    int m_row, int m_col, int m[m_row][m_col],
                    int fm,
                    int k_row, int k_col, int k[fm][k_row][k_col], 
                    int out[fm][m_row-k_row+1][m_col-k_col+1]
                ){
    int i,j,x,y,w;
    int calc=0;
    printf("Inicio Convolução 2d\n");
    for(w=0;w<fm;w++){//feature map 1, 2, 3 .... fm
        for(x=0;x<m_row-k_row+1;x++){//percorre linha da matriz pela linha do kernel
            for(y=0;y<m_col-k_col+1;y++){//percorre coluna da matriz pela coluna do kernel
                for(i=0;i<k_row;i++){//percorre linha do kernel para calcular na matriz
                    for(j=0;j<k_col;j++){//percorre coluna do kernel para calcular na matriz
                        calc=calc+m[i+x][j+y]*k[w][i][j];
                    }
                }
                out[w][x][y]=calc;
                calc=0;
            }
        }
    }
    printf("Convolução 2d Concluída\n");
}

void inputRandomMatrix(int row, int col, int m[row][col]){
    int i,j;    
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j]=rand()%10;
        }
    }
}

void inputRandomMatrix_3(int fm, int row, int col, int m[fm][row][col]){
    int i,j,k;    
    
    for(k=0;k<fm;k++){
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                m[k][i][j]=rand()%100;
            }
        }
    }
}


void maxPooling(int fm, int in_row, int in_col, int in[fm][in_row][in_col], int out_row, int out_col, int out[fm][out_row][out_col]){
    printf("Inicio Max Pooling\n");
    for(int w = 0; w < fm; w++){
        for(int i = 0; i < out_row; i++){
            for(int j = 0; j < out_col; j++){
                int max = in[w][i*2][j*2];
                for(int x = 0; x < 2; x++){
                    for(int y = 0; y < 2; y++){
                        int val = in[w][i*2 + x][j*2 + y];
                        if(val > max){
                            max = val;
                        }
                    }
                }
                out[w][i][j] = max;
            }
        }
    }
    printf("Fim Max Pooling\n");
}

void aggregate(int fm, int row, int col, int m[fm][row][col], int m2[row][col]){
    int i,j,k;  
    printf("Inicio Agregate\n");     
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m2[i][j]=0;
        }
    }  
    
    for(k=0;k<fm;k++){
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                m2[i][j]=m2[i][j]+m[k][i][j];
            }
        }
    }
    printf("Fim Agregate\n");     
}

void printMatrix_3(int fm, int row, int col, int m[fm][row][col]){
    int i,j,k;    
    
    for(k=0;k<fm;k++){
        printf("k:%i\n",k);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf("%i ",m[k][i][j]);;
            }
            printf("\n");
        }
        printf("\n");
    }
}

void inputRandomMatrix4(int fm, int depth, int row, int col, int m[fm][depth][row][col]){
    for(int k = 0; k < fm; k++){
        for(int l = 0; l < depth; l++){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    m[k][l][i][j] = rand() % 100;
                }
            }
        }
    }
}

void convolution3d(
        int fm2, int o_row, int o_col, int out[fm2][o_row][o_col], //out
        int fm1, int k_row, int k_col, int kernel[fm2][fm1][k_row][k_col], //kernel
        int i_row, int i_col, int in[fm1][i_row][i_col]  //in
        
        ){
    //saída do layer 1 tem 10 features maps out_pooling_1[10][12][12]
    //processar 5 kernels 3x3 em 10 features maps kernel_2[5][10][3][3]
    //saída da convolução 3d será uma matriz [5][10][10]

    int i,j,k,l,m,n;

    printf("Inicio Convolução 3d\n");

    //Zera valores de out
    for(k=0;k<fm2;k++){
        for(i=0;i<o_row;i++){
            for(j=0;j<o_col;j++){
                out[k][i][j]=0;
            }
        }
    }

    int calc=0;

    //the fuck convolution 3d
    for(k=0;k<fm2;k++){//FEATURE MAP DO SEGUNDO LAYER = 5
        
        for(m=0;m<o_row;m++){//PERCORRER LINHA MATRIZ DE ENTRADA
            for(n=0;n<o_col;n++){//PERCORRER COLUNA MATRIZ DE ENTRADA
                calc=0;
                for(l=0;l<fm1;l++){//PROFUNDIDADE DE CADA KERNEL = 10
                    for(i=0;i<k_row;i++){ //PERCORRER LINHA DO KERNEL
                        for(j=0;j<k_col;j++){ //PERCORRER COLUNA DO KERNEL
                            calc=calc+(kernel[k][l][i][j]*in[l][m+i][n+j]);
                        }
                    }
                }
                out[k][m][n] = calc; //NO FINAL DE 10 DA PROFUNDIDADE DO KERNEL, SOMA O RESULTADO FINAL
            }
        }
    }   

    printf("Fim Convolução 3d\n");

}

void flatten(int fm, int row, int col, int in[fm][row][col], int fs, int out[fs]){
    int index = 0;
    for(int k = 0; k < fm; k++){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                out[index++] = in[k][i][j];
            }
        }
    }
}

int main(){
    //FALTA NORMALIZAR MATRIZES
    //PRIMEIRA CONVOLUÇÃO
    printf("Inicio da primeira convolução\n\n");
    int sm1=28;
    int matrix_1[sm1][sm1];
    inputRandomMatrix(sm1,sm1,matrix_1);
    printf("Matriz[%i][%i]\n",sm1,sm1);

    int fm1=10,sk1=5;
    int kernel_1[fm1][sk1][sk1];
    inputRandomMatrix_3(fm1,sk1,sk1,kernel_1);
    printf("Kernel[%i][%i][%i]\n",fm1,sk1,sk1);
    
    int so1=sm1-sk1+1;
    int out_1[fm1][so1][so1];
    convolution(sm1,sm1,matrix_1,fm1,sk1,sk1,kernel_1,out_1);
    printf("out_convolution[%i][%i][%i]\n",fm1,so1,so1);

    int sp1=(sm1-sk1+1)/2;
    int out_pooling_1[fm1][sp1][sp1];
    maxPooling(fm1, so1, so1, out_1, sp1, sp1, out_pooling_1);
    printf("out_pooling[%i][%i][%i]\n",fm1,sp1,sp1);
    // printMatrix_3(fm1,sp1,sp1,out_pooling_1);
    printf("\n");

    //SEGUNDA CONVOLUÇÃO
    printf("Inicio da Segunda convolução\n\n");
    int fm2=5,sk2=3;
    int depth = fm1; // Profundidade dos kernels na Layer 2, que é o mesmo que o número de feature maps da Layer 1
    int kernel_2[fm2][depth][sk2][sk2];
    inputRandomMatrix4(fm2,depth,sk2,sk2,kernel_2);
    
    int so2=sp1-sk2+1;
    int out_2[fm2][so2][so2];
    convolution3d(
        fm2,so2,so2,out_2,
        fm1,sk2,sk2,kernel_2,
        sp1,sp1,out_pooling_1
    );

    int fs=500; // 5 feature maps * 10 * 10
    int flattened_output[fs];
    flatten(fm2, so2, so2, out_2, fs, flattened_output);

    //falta implementar camada densa


    return 0;
}