/*
	Name:  exemplo ficheiro binário: mover o indicador de posição do ficheiro
	Author: ESI-LP1-1718
	Date: 2020
	Description:  exemplo calcular o tamanho ocupado pelo ficheiro
*/

#include <stdio.h>
#pragma warning (disable: 4996)
int main4() {
	FILE* af;
	char* nomeFicheiro = "temperaturas.dat";
	long int tamanho;

	af = fopen(nomeFicheiro, "rb");
	if (af == NULL)
		printf("Erro na abertura do ficheiro %s.\n", nomeFicheiro);
	else if (fseek(af, 0, SEEK_END) != 0) {
		printf("Erro na colocacao no final do ficheiro %s.\n",
			nomeFicheiro);
	}
	else {
		tamanho = ftell(af);
		printf("O ficheiro ocupa %ld bytes com %ld valores\n",
			tamanho, tamanho / sizeof(double));
	}
	return 0;
}
