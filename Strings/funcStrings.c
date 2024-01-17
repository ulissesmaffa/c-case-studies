/*
 * Funções de Manipulação de Strings em C
 * Este programa inclui várias funções para manipular strings, como converter para maiúsculas ou minúsculas,
 * contar o número de ocorrências de um caractere, apagar todas as ocorrências de um caractere,
 * identificar caracteres repetidos, excluir caracteres repetidos e duplicar caracteres da string.
 *
 * Autor: Ulisses Maffazioli
 *
 * Notas sobre a Implementação:
 * - As funções operam diretamente na string passada como parâmetro.
 * - A função `procurar` retorna o número de ocorrências de um caractere específico na string.
 * - `apagar` remove todas as ocorrências de um caractere específico.
 * - `repetidos` e `excluirRepetidos` lidam com caracteres repetidos na string.
 * - `duplicar` cria uma nova string com cada caractere da string original duplicado.
 * - O programa demonstra o uso de funções padrão da biblioteca `ctype.h` para manipulação de caracteres.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maiusculo(char *str){
    int i=0;
    while (str[i] != '\0') { // percorre a string até o fim
        str[i] = toupper(str[i]); // transforma o caractere atual em maiúsculo
        i++; // incrementa o índice
    }
}

void minusculo(char *str){
    int i=0;
    while(str[i]!='\0') { // percorre a string até o fim
        str[i] = tolower(str[i]); // transforma o caractere atual em maiúsculo
        i++; // incrementa o índice
    }
}

int procurar(char *str, char p){    
    int i=0,qtd=0;
    while(str[i]!='\0'){
        if(str[i]==p){
            qtd++;
        }
        i++; // incrementa o índice
    }
    return qtd;
}

void apagar(char *str, char p){
    int i=0;
    int aux;
    while(str[i]!='\0'){
        if(str[i]==p){
            aux=i;
            while(str[aux]!='\0'){
                str[aux]=str[aux+1];
                aux++;
            }
        }
        i++;
    }
}

void repetidos(char *str, int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(str[i]==str[j]){
                printf("%c é repetido\n",str[j]);
            }
        }
    }
}

void excluirRepetidos(char *str, int size){
    int i,j,aux;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(str[i]==str[j]){
                aux=j;
                while(str[aux]!='\0'){
                    str[aux]=str[aux+1];
                    aux++;
                }
            }
        }
    }
}

void duplicar(char *str){
    int i,j=0;
    int size = strlen(str);
    int size2 = size*2;
    char str2[size2];

    for(i=0;i<size;i++){        
        str2[j]=str[i];
        str2[j+1]=str[i];
        j=j+2;
    }
    printf("duplicado_str:  %s\n",str2);
}

int main(){
    char str[]="Ulisses Maffazioli";
    printf("original_str:  %s\n",str);

    maiusculo(str);
    printf("maiusculo_str: %s\n",str);

    minusculo(str);
    printf("minusculo_str: %s\n",str);

    char valor={'i'};

    printf("qtd de '%c': %i\n",valor,procurar(str,valor));

    // printf("tamanho str antes de apagar:  %lu\n",strlen(str));
    // apagar(str,valor);
    // printf("apagar_str:  %s\n",str);
    // printf("tamanho str depois de apagar:  %lu\n",strlen(str));

    // repetidos(str,strlen(str));

    // excluirRepetidos(str,strlen(str));
    // printf("apagar_repetidos_str:  %s\n",str);

    duplicar(str);

    return 0;
}