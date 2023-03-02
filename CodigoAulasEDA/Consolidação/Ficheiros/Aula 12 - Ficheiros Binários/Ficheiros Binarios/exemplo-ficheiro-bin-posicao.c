/*
	Name:  exemplo ficheiro bin�rio: mover o indicador de posi��o do ficheiro
	Author: ESI-LP1-1718
	Date: 2020
	Description:  exemplo que permite aceder ao quinto valor das temperaturas
*/

#include <stdio.h>
#pragma warning (disable: 4996)

int main3() {
	FILE* af;
	char* nomeFicheiro = "temperaturas.dat";
	double valor;

	af = fopen(nomeFicheiro, "rb");
	if (af == NULL)
		printf("Erro na abertura do ficheiro %s.\n", nomeFicheiro);
	else if (fseek(af, 4 * sizeof(double), SEEK_SET) != 0) {
		printf("Erro na colocacao no ficheiro %s.\n", nomeFicheiro);
	}
	else if (fread(&valor, sizeof(double), 1, af) == 1) {
		printf("O quinto valor do ficheiro: %.2f\n.", valor);
	}
	else {
		printf("Erro ao ler o quinto valor do ficheiro %s\n.",
			nomeFicheiro);
	}
	return 0;
}
