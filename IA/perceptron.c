#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

#define LEARNING_RATE 0.3
#define ROW 4
#define COL 3

void mostrarMatriz(int row, int col, float m[row][col]){
    int i,j;    
    for(i=0;i<row;i++){
        printf("[%i] ",i);
        for(j=0;j<col;j++){
            printf("%.2f ",m[i][j]);
        }
        printf("\n");
    }
}

float funcaoSoma(float inputs[], float weights[]){
    int i;
    float soma=0;
    float calc=0;
    for (i=0; i<COL; i++) {
        calc = inputs[i] * weights[i];
        printf("%.3f * %.3f = %.3f\n",inputs[i],weights[i],calc);
        soma += calc;
    }
    return soma;
}

int funcaoAtivacao(float soma){
    if(soma>0){
        return 1;
    }else{
        return 0;
    }
}

void treinamento(float inputs[], float weights[], float desired_output,int ativa){
    int i;
    // Cálculo do erro
    float error = desired_output - ativa;
    printf("calc erro: %.3f =  %.3f - %i\n",error,desired_output,ativa);
    for(i=0;i<COL;i++){  
        printf("Novo Peso w[%i]= %.3f + (%.2f + %.2f * %.2f) -> ",i,weights[i],LEARNING_RATE,error,inputs[i]);
        weights[i]=weights[i]+ (LEARNING_RATE * error * inputs[i]);
        printf("w[%i] = %.3f\n",i,weights[i]);
    }
    // printf("\n");
}

void prever(float inputs[], float weights[]){
    float soma = funcaoSoma(inputs,weights);
    int ativa = funcaoAtivacao(soma);
    printf("Resultado da previsão: %i\n", ativa);
}

void mostrarInfo(float weights[]){
    printf("w[0]=%.4f\n",weights[0]);
    printf("w[1]=%.4f\n",weights[1]);
    printf("w[2]=%.4f\n",weights[2]);
}

float calcular_precisao(float inputs[][COL], float weights[], float desired_outputs[], int num_samples){
    int i;
    int num_correct = 0;

    for(i=0; i<num_samples; i++){
        float soma = funcaoSoma(inputs[i], weights);
        int ativa = funcaoAtivacao(soma);

        if(ativa == desired_outputs[i]){
            num_correct++;
        }
    }

    return (float)num_correct / num_samples;
}

int main(){
    float soma,inputs[3];
    int ativa,i,j,k=1,num,epocas;
    bool continua=true;

    float m_inputs[ROW][COL]={//inclusão do BIAS
        {0,0,1},
        {0,1,1},
        {1,0,1},
        {1,1,1}
    };

    float weights[3];
    srand(time(0));  // Use a hora atual como semente para o gerador de números aleatórios
    for(int i = 0; i < COL; i++){
        weights[i] = ((float)rand()/(float)(RAND_MAX)) - 0.5;
        printf("w[%i]=%.3f\n",i,weights[i]);
    }

    float desired_outputs[ROW] = {0, 0, 0, 1};

    do{
        printf("\n============================  MENU ============================\n");
        printf("Digite um número para:\n[1] Treinamento da Rede\n[2] Informar Entradas\n");
        printf("[3] Mostrar Informações\n");
        printf("[4] Calcular Precisão\n");
        printf("[9] Sair\n");
        printf("==============================================================\n");
        scanf("%i",&num);

        switch(num){
            case 1:
                printf("\n============  INICIO ÁREA DE TREINAMENTO ============ \n");
                printf("Informe quantas épocas:");
                scanf("%i",&epocas);
                
                for(j=0;j<epocas;j++){
                    for(i=0;i<ROW;i++){
                        printf("\n[%i] ",i);
                        soma=funcaoSoma(m_inputs[i],weights);
                        ativa=funcaoAtivacao(soma);
                        printf("Ativa:%i\n",ativa);
                        treinamento(m_inputs[i],weights,desired_outputs[i],ativa);
                        printf("w1=%.3f - w2=%.3f\n",weights[0],weights[1]);
                    }
                }
                printf("Treinamento concluído!\n");
                printf("=============  FIM ÁREA DE TREINAMENTO ============= \n");
            break;

            case 2:
                printf("\n============  INICIO ÁREA DE PREVISÃO ============ \n");
                printf("Digite dois valores de entrada:\n");
                scanf("%f %f",&inputs[0], &inputs[1]);
                inputs[2]=1;//garante inclusão do BIAS
                prever(inputs, weights);
                printf("=============  FIM ÁREA DE PREVISÃO ============= \n");
            break;

            case 3:
                printf("\n============  INICIO ÁREA DE INFO ============ \n");
                mostrarInfo(weights);
                printf("=============  FIM ÁREA DE INFO ============= \n");
            break;

            case 4:
                printf("\nCalculando a precisão do modelo...\n");
                float precisao = calcular_precisao(m_inputs, weights, desired_outputs, ROW);
                printf("Precisão: %.2f\n", precisao);
            break;
            case 9:
                continua=false;
            break;
        }
    }while(continua);

    return 0;
}