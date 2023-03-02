/*
	Name:  FicheiroTextoC-Exercício01_a.c
	Author:
	Date: 2020
	Description: percorrer o ficheiro caracter a caracter e apresentar no ecran o conteúdo do ficheiro
	             com o prefixo do número de cada linha
*/
#include <stdio.h>
 
// declaração ou assinatura das funções locais

// função principal
int main2() {
	// declaração e inicialização de variáveis

    FILE *af; // apontador para descritor de ficheiro
    char c ;
    int nLinhas = 1;
    // abrir  ficheiro em modo leitura (r)
    af = fopen("a.txt", "r") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro a.txt!\n");
    else {
        printf("Sucesso na abertura do ficheiro a.txt! \n");
        // leitura do ficheiro caracter a caracter
        c = fgetc(af); // le o primeiro
        printf("%d: ", nLinhas);

		//com while()
		while (c != EOF) {
				
			printf("%c", c); // escreve na consola				
			if (c == '\n') {					
				nLinhas = nLinhas + 1;
				printf("%d: ", nLinhas);
				}		
            c = fgetc(af); // avanca com a leitura
        }

		//ou com do..while
		/*do {
			c = fgetc(af);
			printf("%c", c);
			if (c == '\n') {
				nLinhas = nLinhas + 1;
				printf("%d: ", nLinhas);
			}
		} while (c != EOF);*/


		//ou com for(;;)
		/*for (nLinhas=1; ;) {

			c = fgetc(af);
			if (c == EOF) break;

			printf("%c", c);
			if (c == '\n') {
				nLinhas = nLinhas + 1;
				printf("%d: ", nLinhas);
			}
		}*/
        fclose(af); // fechar o descritor de ficheiro
    }
	getche();
	return 0;
}


