/*
 * Nome do Programa: Manipulação de Arquivos em C
 * Descrição: 
 *    Este programa demonstra várias operações de leitura e escrita em arquivos usando C.
 *    As operações incluem escrever em um arquivo, ler de um arquivo, contar o número de
 *    linhas em um arquivo, somar números de cada linha do arquivo e imprimir o conteúdo 
 *    do arquivo na tela. Cada operação é realizada de maneira segura, verificando se o 
 *    arquivo foi aberto corretamente.
 * 
 * Autor: Ulisses Maffazioli
 * 
 * Notas:
 *    - O programa utiliza a biblioteca stdio.h para as operações de arquivo.
 *    - As operações de arquivo incluem:
 *        - Escrita de inteiros em um arquivo.
 *        - Leitura de inteiros de um arquivo.
 *        - Contagem de linhas em um arquivo.
 *        - Soma de números presentes em cada linha do arquivo.
 *        - Impressão do conteúdo do arquivo usando fgetc.
 *    - O programa trata erros de abertura de arquivo, garantindo a segurança na execução.
 */


#include <stdio.h>

int main(){
    FILE *pt_arq;
    int i;
    //ESCREVER EM UM ARQUIVO
    // pt_arq=fopen("arq.txt","a+");
    // if(pt_arq==NULL){
    //     printf("Erro, algo deu errado!\n");
    //     return 1;
    // }
    // for(i=0;i<5;i++){
    //     fprintf(pt_arq,"%i\n",i);
    // }
    // fclose(pt_arq);

    // LER EM UM ARQUIVO
    pt_arq=fopen("arq.txt","r");
    if(pt_arq==NULL){
        printf("Erro, algo deu errado!\n");
        return 1;
    }
    while (fscanf(pt_arq,"%i",&i)==1)//caso a leitura seja bem sucessida, fscanf retorna 1
    printf("%d ", i);
    printf("\n");
    fclose(pt_arq);

    //CONTAGEM DE LINHAS NO ARQUIVO
    pt_arq=fopen("arq.txt","r");
    if(pt_arq==NULL){
        printf("Erro, algo deu errado!\n");
        return 1;
    }
    int num=0;
    char ch;
    while( (ch=fgetc(pt_arq))!= EOF )
    if(ch == '\n')
    num++;
    printf("Numero de linhas:%i\n",num);
    fclose(pt_arq);

    //Soma das linhas
    int soma[3];
    pt_arq=fopen("arq.txt","r");
    if(pt_arq==NULL){
        printf("Erro, algo deu errado!\n");
        return 1;
    }
    while( (fscanf(pt_arq,"%i %i %i\n",&soma[0],&soma[1],&soma[2]))!=EOF )
    printf("Soma: %i\n",soma[0]+soma[1]+soma[2]);
    fclose(pt_arq);

    //IMPRESSÃO COM FGETC
    pt_arq=fopen("arq.txt","r");
    while((ch=fgetc(pt_arq))!=EOF)
    printf("%c",ch);
    if(ch == '\n'){
        printf("\n");
    }
    printf("\n");
    fclose(pt_arq);

    return 0;
}