/*
Trabalho para apresentar na aula do dia 13/06:
Desenvolver um programa como menu para manipulação de dados de clientes. O estabelecimento pode ter vários clientes 
e pode incluir mais dados cada vez que manipula o menu ou toda que executa o programa.
A estrutura de dados servirá para armazenar o cadastro dos clientes de uma loja: 
    nome [30], 
    CPF (tamanho 11), 
    endereço [30], 
    bairro, 
    data de nascimento,  
    data da última compra, 
    valor acumulado comprado.
    Endereço: rua e número.

USAR ARQUIVO PARA ARMAZENAR OS DADOS.

Autor: Ulisses Maffazioli

Menu:
1 - Cadastrar cliente
2 - Listar cliente que fez a última compra em uma data informada pelo teclado (informar CPF, nome e endereço)
3 - Contar quantos clientes moram em um bairro informado pelo teclado
4 - Listar o nome do cliente que tem o maior valor acumulado de compras
5 - Fim
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define S_NOME 30
#define S_END 30
#define S_BAIRRO 30
#define S_CPF 12

typedef struct{
    char nome[S_NOME];
    char cpf[S_CPF];
    char endereco[S_END];
    char bairro[S_BAIRRO];
    int dataNascimento[3];
    int dataUltimaCompra[3];
    float valorTotalAcumulado;
}Cliente;

int menuSistema(){
    int n;
    bool error=false;

    do{
        printf("===========================================================\n");
        printf("MENU INICIAL DO SISTEMA:\n");
        printf("===========================================================\n");
        printf("Digite [1] para CADASTRAR UM CLIENTE\n");
        printf("Digite [2] para LISTAR CLIENTES QUE FIZERAM ÚLTIMA COMPRA EM DETERMINADA DATA\n");
        printf("Digite [3] para QUANTIDADE DE CLIENTES POR BAIRRO\n");
        printf("Digite [4] para MOSTRAR CLIENTE COM MAIOR VALOR ACUMULADO\n");
        printf("Digite [9] para SAIR\n");
        scanf("%i",&n);
        printf("===========================================================\n");
        
        if(n==1||n==2||n==3||n==4||n==9){
            error=false;
        }else{
            printf("Erro! digite um número válido\n");
            error=true;
        }
    }while(error);

    return n;
}

bool validarCPF(const char *cpf) {
    int i;
    int digitoVerificador1,digitoVerificador2;
    int soma1=0,soma2=0;

    // Verificar se o CPF possui 11 dígitos
    if (strlen(cpf)!=11) {
        return false;
    }
    // Verificar se todos os caracteres são dígitos
    for (i=0;i<11;i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }
    // Verificar se todos os dígitos são iguais
    bool todosDigitosIguais=true;
    for (i=1;i<11;i++) {
        if (cpf[i]!=cpf[0]) {
            todosDigitosIguais=false;
            break;
        }
    }
    if (todosDigitosIguais) {
        return false;
    }

    // Calculando o primeiro dígito verificador
    for (i=0;i<9;i++) {
        soma1+=(cpf[i]-'0')*(10-i);
    }
    digitoVerificador1=(soma1*10)%11;
    if (digitoVerificador1==10) {
        digitoVerificador1=0;
    }
    if (cpf[9]-'0'!=digitoVerificador1) {
        return false;
    }

    // Calculando o segundo dígito verificador
    for (i=0;i<10;i++) {
        soma2+=(cpf[i]-'0')*(11-i);
    }
    digitoVerificador2 = (soma2 * 10) % 11;
    if (digitoVerificador2 == 10) {
        digitoVerificador2 = 0;
    }
    if (cpf[10]-'0'!= digitoVerificador2) {
        return false;
    }
    return true;
}

bool validarData(int dia, int mes, int ano) {
    // Verificar se o ano é bissexto
    bool bissexto = false;
    if ((ano%4==0 && ano%100!=0) || ano % 400 == 0) {
        bissexto = true;
    }
    // Verificar o intervalo válido para o mês
    if (mes < 1 || mes > 12) {
        return false;
    }
    // Verificar o intervalo válido para o dia, considerando os meses com 31 dias
    if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) {
        return false;
    }
    // Verificar o intervalo válido para o dia, considerando os meses com 30 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) {
        return false;
    }
    // Verificar o intervalo válido para o dia, considerando o mês de fevereiro
    if (mes==2) {
        if (bissexto && (dia<1||dia > 29)) {
            return false;
        } else if (!bissexto && (dia < 1 || dia > 28)) {
            return false;
        }
    }
    // Verificar se a data é futura (maior do que a data atual)
    // Obter a data atual
    time_t tempoAtual = time(NULL);
    struct tm *dataAtual = localtime(&tempoAtual);
    int anoAtual = dataAtual->tm_year + 1900;
    int mesAtual = dataAtual->tm_mon + 1;
    int diaAtual = dataAtual->tm_mday;
    // Comparar a data com a data atual
    if(ano>anoAtual) {
        return false;
    } else if (ano==anoAtual&&mes>mesAtual) {
        return false;
    } else if (ano==anoAtual && mes==mesAtual && dia>diaAtual) {
        return false;
    }

    return true;
}

void cadastroCliente(Cliente *c){
    bool error=false;
    FILE *pt_arq;
    printf("\nCADASTRO CLIENTE\n");

    do{
        //Informar Nome
        do{
            fflush(stdin);
            printf("Digite o NOME: ");
            fgets(c->nome,S_NOME,stdin);
            c->nome[strcspn(c->nome, "\n")] = '\0';
            if(strlen(c->nome)==0){
                printf("Erro ao preencher NOME. Faça novamente!\n");
                error=true;
            }else{
                error=false;
            }
        }while(error);

        //Informar CPF
        do{
            fflush(stdin);
            printf("Digite o CPF: ");
            fgets(c->cpf,S_CPF,stdin);
            c->cpf[strcspn(c->cpf, "\n")] = '\0';
            if(!validarCPF(c->cpf)){
                printf("Erro ao preencher CPF. Faça novamente!\n");
                error=true;
            }else{
                error=false;
            }
        }while(error);

        //Informa endereço
        do{
            fflush(stdin);
            printf("Digite o ENDEREÇO: ");
            fgets(c->endereco,S_END,stdin);
            c->endereco[strcspn(c->endereco, "\n")] = '\0';
            if(strlen(c->endereco)==0){
                printf("Erro ao preencher ENDEREÇO. Faça novamente!\n");
                error=true;
            }else{
                error=false;
            }
        }while(error);

        //Informa Bairro
        do{
            fflush(stdin);
            printf("Digite o BAIRRO: ");
            fgets(c->bairro,S_BAIRRO,stdin);
            c->bairro[strcspn(c->bairro, "\n")] = '\0';
            if(strlen(c->bairro)==0){
                printf("Erro ao preencher BAIRRO. Faça novamente!\n");
                error=true;
            }else{
                error=false;
            }
        }while(error);

        //Informar data de nascimento
        do{
            printf("Digite a DATA DE NASCIMENTO (DIA + MÊS + ANO):\n");
            printf("DIA: ");
            scanf("%i",&c->dataNascimento[0]);
            printf("MÊS: ");
            scanf("%i",&c->dataNascimento[1]);
            printf("ANO: ");
            scanf("%i",&c->dataNascimento[2]);
            if(!validarData(c->dataNascimento[0],c->dataNascimento[1],c->dataNascimento[2])){
                error=true;
                printf("Erro ao preencher DATA NASCIMENTO. Faça novamente!\n");
            }else{
                error=false;
            }
        }while(error);

        //Informar data de última compra
        do{ 
            printf("Digite a DATA DA ÚLTIMA COMPRA (DIA + MÊS + ANO):\n");
            printf("DIA: ");
            scanf("%i",&c->dataUltimaCompra[0]);
            printf("MÊS: ");
            scanf("%i",&c->dataUltimaCompra[1]);
            printf("ANO: ");
            scanf("%i",&c->dataUltimaCompra[2]);
            if(!validarData(c->dataUltimaCompra[0],c->dataUltimaCompra[1],c->dataUltimaCompra[2])){
                printf("Erro ao preencher DATA ÚLTIMA COMPRA. Faça novamente!\n");
                error=true;
            }else{
                error=false;
            }
        }while(error);
        
        //Informar valor total acumulado
        do{
            printf("Digite o VALOR TOTAL ACUMULADO: ");
            scanf("%f",&c->valorTotalAcumulado);
            if(c->valorTotalAcumulado<=0){
                printf("Erro ao preencher VALOR TOTAL ACUMULADO. Faça novamente!\n");
                error=true;
            }else{
                error=false;
            }
        }while(error);
    }while(error);

    pt_arq=fopen("clientes.txt","a");
    if(pt_arq==NULL){
        printf("Erro na abertura do arquivo!\n");
    }else{
        fprintf(pt_arq,"%s;%s;%s;%s;%i/%i/%i;%i/%i/%i;%.2f;\n",c->nome,c->cpf,c->endereco,c->bairro,c->dataNascimento[0],c->dataNascimento[1],c->dataNascimento[2],c->dataUltimaCompra[0],c->dataUltimaCompra[1],c->dataUltimaCompra[2],c->valorTotalAcumulado);
    }
    fclose(pt_arq);
}

void compraUltimoCliente(){
    //OBTEM FILTRO A SER PESQUISADO NO ARQUIVO
    int data[3];
    printf("\nLISTA DE CLIENTES QUE FIZERAM ÚLTIMA COMPRA EM DETERMINADA DATA\n");
    printf("informe o DIA: ");
    scanf("%i",&data[0]);
    printf("informe o MÊS: ");
    scanf("%i",&data[1]);
    printf("informe o ANO: ");
    scanf("%i",&data[2]);

    //ABRE ARQUIVO PARA LEITURA
    FILE *pt_arq;
    pt_arq = fopen("clientes.txt", "r");
    if (pt_arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    //PROCESSO DE BUSCA
    char linha[200];
    bool nenhumClienteEncontrado = true;
    printf("\n");
    while (fgets(linha, sizeof(linha), pt_arq) != NULL) {
        char *token = strtok(linha, ";");
        char nome[S_NOME];
        char cpf[S_CPF];
        char endereco[S_END];
        char bairro[S_BAIRRO];
        int dataNascimento[3];
        int dataUltimaCompra[3];
        float valorTotalAcumulado;

        strcpy(nome, token);
        token = strtok(NULL, ";");
        strcpy(cpf, token);
        token = strtok(NULL, ";");
        strcpy(endereco, token);
        token = strtok(NULL, ";");
        strcpy(bairro, token);
        token = strtok(NULL, ";");
        sscanf(token, "%d/%d/%d", &dataNascimento[0], &dataNascimento[1], &dataNascimento[2]);
        token = strtok(NULL, ";");
        sscanf(token, "%d/%d/%d", &dataUltimaCompra[0], &dataUltimaCompra[1], &dataUltimaCompra[2]);
        token = strtok(NULL, ";");
        sscanf(token, "%f", &valorTotalAcumulado);

        if (dataUltimaCompra[0] == data[0] && dataUltimaCompra[1] == data[1] && dataUltimaCompra[2] == data[2]) {
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Endereço: %s\n", endereco);
            printf("-----------------------------------------------------------\n");
            nenhumClienteEncontrado = false;
        }
    }

    if(nenhumClienteEncontrado) {
        printf("-----------------------------------------------------------\n");
        printf("Nenhum cliente foi encontrato pela Data:%i/%i/%i informada\n",data[0],data[1],data[2]);
        printf("-----------------------------------------------------------\n");
    }

    fclose(pt_arq);
}

void clientesPorBairro(){
    printf("\nCLIENTES POR BAIRRO\n");
    char bairroPesquisado[S_BAIRRO];
    printf("Informe o bairro: ");
    fflush(stdin);
    fgets(bairroPesquisado, S_BAIRRO, stdin);
    bairroPesquisado[strcspn(bairroPesquisado, "\n")] = '\0';

    FILE *pt_arq;
    pt_arq = fopen("clientes.txt", "r");
    if (pt_arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    char linha[200];
    int contador = 0;

    while (fgets(linha, sizeof(linha), pt_arq) != NULL) {
        char *token = strtok(linha, ";");
        // Pular os tokens até o campo do bairro
        for (int i = 0; i < 3; i++) {
            token = strtok(NULL, ";");
        }
        char bairro[S_BAIRRO];
        strcpy(bairro, token);

        if (strcmp(bairro, bairroPesquisado) == 0) {
            contador++;
        }
    }

    printf("Número de clientes que moram no bairro %s: %d\n", bairroPesquisado, contador);

    fclose(pt_arq);
}

void clienteMaiorValorAcumulado(){
    printf("\nCLIENTE COM MAIOR VALOR ACUMULADO\n");

    FILE *pt_arq;
    pt_arq = fopen("clientes.txt", "r");
    if (pt_arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    char linha[200];
    float maiorValor = 0;
    char nomeCliente[S_NOME];

    while (fgets(linha, sizeof(linha), pt_arq) != NULL) {
        char *token = strtok(linha, ";");
        // Pular os tokens até o campo do valor acumulado
        for (int i = 0; i < 6; i++) {
            token = strtok(NULL, ";");
        }
        float valorAcumulado = atof(token);
        // Comparar o valor acumulado com o maior valor atual
        if (valorAcumulado > maiorValor) {
            maiorValor = valorAcumulado;
            // Obter o nome do cliente
            token = strtok(NULL, ";");
            strcpy(nomeCliente, token);
        }
    }
    if (maiorValor > 0) {
        printf("Nome do cliente com maior valor acumulado de compras: %s\n", nomeCliente);
        printf("Valor acumulado: %.2f\n", maiorValor);
    } else {
        printf("Não foram encontrados clientes cadastrados.\n");
    }
    fclose(pt_arq);
}

int main(){
    Cliente cliente;
    bool ligado=true;
    int num;
    
    do{
        num=menuSistema();
        switch (num){
        case 1:
            cadastroCliente(&cliente);
            break;
        case 2:
            compraUltimoCliente();
            break;
        case 3:
            clientesPorBairro();
            break;
        case 4:
            clienteMaiorValorAcumulado();
            break;
        case 9:
            ligado=false;
            break;
        }

    }while(ligado);

    return 0;
}