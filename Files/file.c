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