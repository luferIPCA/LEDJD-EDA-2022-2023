#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "menu.h"
#include "inscricao.h"

// função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
	// declaração e inicialização de variáveis
	char op;
	char nomeFicheiro[20] = "inscricoesdata.txt";
	char texto[TAM];
    do {
       op = apresentaMenu();
        switch(op) {
            case '1':  inserirInscricoes(nomeFicheiro);
                       break;
             case '2': listarInscricoes(nomeFicheiro);
                       break;
            case '3':  listarUmaInscricao(nomeFicheiro);
                break;            
            case '4': LerDados("Dados.txt");                      
                break;
            case '5':  // Sair: nao faz nada
                break;
            default: printf("opção desconhecida!\n");
                      break;
        }
    } while(op != '5');

	return 0;
}
