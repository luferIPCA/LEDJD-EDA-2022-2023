#include "menu.h"
#include "inscricao.h"

// defini��o das fun��es
char apresentaMenu(){
    char opcao;
    printf("-- menu --   \n");
    printf("1. inscrever\n");
    printf("2. listar todas as inscri��es \n");
    printf("3. listar uma determinada inscri��o \n");
    printf("4. Ler Dados\n");
    printf("5. sair \n");
    do {
        printf("opcao? ");
        opcao = getchar();
        // limpar texto at� ao \n no buffer do teclado
        while (getchar()!='\n');
    } while (!(opcao>='1' && opcao <='5'));
    return opcao;
}

int F() {
	return 0;
}
