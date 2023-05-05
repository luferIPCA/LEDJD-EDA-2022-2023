/*****************************************************************//**
 * @file   Main.c
 * @brief  Gera ficheiro binário com arrays e structs
 * 
 * @author lufer
 * @date   November 2022
 *********************************************************************/

#include "Header.h"
#include <string.h>

#pragma warning (disable: 4996)

int main(int argc, char**argv) {

	char fileName[N];

	if (argc <=1) 
		strcpy(fileName, "Dados.dat");
	else
		strcpy(fileName, argv[1]);
	
	Pessoa pessoas[] = { {12,"Ana"},{23,"Pedro"} };
	FILE* fp = fopen(fileName, "wb");
	bool aux = SaveArray(fp, pessoas, 2);
	fclose(fp);

	fp = fopen(fileName, "rb");
	bool r=ShowFile(fp);
	fclose(fp);
}
