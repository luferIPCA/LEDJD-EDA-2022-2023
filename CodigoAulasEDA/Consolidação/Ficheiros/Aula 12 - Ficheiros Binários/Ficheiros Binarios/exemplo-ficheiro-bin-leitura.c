/*
	Name:  exemplo ficheiro binário: leitura
	Author: ESI-LP1-1718
	Date: 2020
	Description:   leitura a partir de um ficheiro binário dos valores das temperaturas médias diárias nos últimos 7 dias
*/
#include <stdio.h>
#pragma warning (disable: 4996)

void main() {
	FILE* af;
	char* nomeFicheiro = "temperaturas.dat";
	int nlidos, i;
	double temperaturas[7];
	/* abertura do ficheiro em modo binario para leitura*/
	af = fopen(nomeFicheiro, "rb");
	if (af == NULL)
		printf("Erro na abertura do ficheiro %s.\n", nomeFicheiro);
	else {
		//nlidos = fread(&temperaturas[0], sizeof(double), 7, af);
		//ou
		nlidos = fread(temperaturas, sizeof(double), 7, af);
		if (nlidos == 0)
			printf("Nao foi lido nenhum elemento!\n");
		else {
			if (nlidos < 7)
				printf("Lidos apenas %d elementos!\n", nlidos);
			for (i = 0; i < nlidos; i++)
				printf("temperaturas[%d]=%.2f\n", i, temperaturas[i]);

		}
	}
	fclose(af);
	return 0;
}
