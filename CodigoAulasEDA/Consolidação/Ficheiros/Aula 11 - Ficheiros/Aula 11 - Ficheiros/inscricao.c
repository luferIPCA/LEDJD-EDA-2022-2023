#include <stdio.h>
#include "inscricao.h"

#pragma warning (disable: 4996)
/* -------------------------------------------
   assinatura das fun��es auxiliares (apenas utilizadas em inscricao.c)
   ---------------------------------------------   */
void escreverCabecalho();
void escreverInscricao(char nome[], int dia, int mes, int ano);
int calcularIdade(int dia, int mes, int ano);
void listarInscricaoN(FILE *af, int nInscricao);
void lerLinhaN(char *nomeFicheiro, int linha, char conteudo[] );


/* ----------------------------------------
   implementa��o das fun��es principais (assinatura colocada em inscricao.h)
   ----------------------------------------   */
void inserirInscricoes(char *nomeFicheiro) {
    FILE *af;
    char frase[TAM] ;
    int dia, mes, ano;
    // abrir  ficheiro em modo acrescentar ( a )
    af = fopen(nomeFicheiro, "a") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("\n--- inscri��o (FIM para terminar) --\n");
        // ler o primeiro nome
        printf("nome? ");
        fgets(frase,TAM,stdin);
        frase[strlen(frase)-1] = '\0';


        while (strcmp(frase,"FIM")!=0) { // frase diferente de FIM
            // ler a data: dia, mes e ano
            printf("data nascimento? (dd/mm/aaaa)  ");
            scanf("%d/%d/%d", &dia, &mes, &ano );
            getchar(); // limpar \n
             // acrescentar uma inscri��o ao ficheiro
            fprintf(af, "%s\n", frase); // escrever o nome lido no ficheiro
            fprintf(af, "%d/%d/%d\n", dia, mes, ano ); // escrever o nome lido no ficheiro

            // ler o segundo nome e seguintes
            printf("nome?");
            fgets(frase,TAM,stdin);
            frase[strlen(frase)-1] = '\0';
        }
        printf("--- FIM das inscri��es  -- \n\n");
        fclose(af); // fechar o descritor de ficheiro
    }

}

/*
Lista todas as inscri��es existentesno ficheiro
*/
void listarInscricoes(char *nomeFicheiro) {
    FILE *af; // apontador para descritor de ficheiro
    char nome[TAM] ;
    int dia, mes, ano ;
    // abrir  ficheiro em modo leitura (r)
    af = fopen(nomeFicheiro, "r") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("\n--  lista de inscri��es: \n\n");
        escreverCabecalho();
        // leitura do ficheiro linha a linha
        while (fgets(nome, TAM, af) != NULL){
            nome[strlen(nome)-1] = '\0'; // limpar \n
            // ler data de nascimento
            fscanf(af, "%d/%d/%d\n", &dia, &mes, &ano);
            // escrever valores lidos
           escreverInscricao(nome, dia,mes, ano);
        }
        printf("--------------------------------  \n\n");
        fclose(af); // fechar o descritor de ficheiro
    }
}

/*
Mostra apenas uma inscri��o em particular
*/
void listarUmaInscricao(char *nomeFicheiro){
    FILE *af; // apontador para descritor de ficheiro

    int n = 0;
    // abrir  ficheiro em modo leitura (r)
    af = fopen(nomeFicheiro, "r") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("Qual a inscri��o que pretende ler? ");
        scanf("%d", &n);
        while (getchar()!='\n'); // limpa o buffer do teclado

        listarInscricaoN(af, n);

        fclose(af); // fechar o descritor de ficheiro
    }
}


/* -------------------------------------------
 implementa��o das fun��es auxiliares (apenas utilizadas em inscricao.c)
   ---------------------------------------------   */

void listarInscricaoN(FILE *af, int nInscricao) {
    char nome[TAM];
    int dia, mes, ano;
    int contaInscricoes= 0;
    while ((contaInscricoes < nInscricao) && (fgets(nome, TAM, af) != NULL) ) {
            nome[strlen(nome)-1] = '\0'; // limpar \n
            fscanf(af, "%d/%d/%d\n", &dia, &mes, &ano);
            escreverInscricao(nome, dia, mes, ano);
            contaInscricoes += 1;
    }

   if (contaInscricoes < nInscricao)
   {
       printf("inscri��o %d n�o existe (existem apenas %d inscri��es)...\n", nInscricao, contaInscricoes);
   } else {
       printf("------------------------------\ninscri��o %d:   \n", nInscricao);
       escreverCabecalho();
       escreverInscricao(nome, dia, mes, ano);
       printf("--------------------------------  \n\n");
    }
}

void escreverCabecalho() {
    char tituloNome[5] = "Nome";
    char tituloDN[11] = "Data Nasc.";
    char tituloIdade[6] = "Idade";
    printf("%-30s\t%-10s\t%s\n", tituloNome, tituloDN, tituloIdade);
}

void escreverInscricao(char nome[], int dia, int mes, int ano) {
            printf("%-30s\t", nome);
            printf("%d/%d/%d\t", dia, mes, ano);
            printf("%3d\n", calcularIdade(dia, mes, ano));
}

int calcularIdade(int dia, int mes, int ano) {
    int resultado;
    resultado = 2017 - ano; // se nasc. antes (ou em) 30.10.2017
    if (mes > 10 )
        resultado = resultado -1;
    else if (mes == 10) {
        if (dia > 30) {
                resultado = resultado -1;
        }
    }
    return resultado;
}


#pragma region JESSICA
typedef struct Linha {
    int numero;
    char d1[12];
    char d2[12];
    int temp;
    int codigo;
    char estado[100];
    char tipo[100];
}Linha ;

void LerDados(char* nomeFicheiro) {
    FILE* af; 

    af = fopen("c:\\temp\\Dados.txt", "r");

    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        Linha aux;

        while (fscanf(af, "%d;%s;%[^;];%d;%[^;];%[^\n] ", &aux.numero, aux.d1, aux.d2, &aux.codigo, aux.estado, aux.tipo) != NULL) {
            if (aux.estado[strlen(aux.estado) - 1] == '\n') aux.estado[strlen(aux.estado) - 1] = '\0'; // limpar \n
            if (aux.tipo[strlen(aux.tipo) - 1]=='\n') aux.tipo[strlen(aux.tipo) - 1] = '\0';
            printf("%s\n", aux.estado);
            printf("%s\n", aux.tipo);
        }
    }
}

//fgets()
//strtok()

#pragma endregion

