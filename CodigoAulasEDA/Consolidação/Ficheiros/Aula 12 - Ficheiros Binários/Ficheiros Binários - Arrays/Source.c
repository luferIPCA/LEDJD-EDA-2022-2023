/*****************************************************************//**
 * @file   Source.c
 * @brief  
 * 
 * @author lufer
 * @date   November 2022
 *********************************************************************/

#include "Header.h"

/**
 * @brief Grava array de structs em ficheiro binário.
 * 
 * @param fp
 * @param p
 * @param n
 * @return 
 * @author lufer
 *
 */
bool SaveArray(FILE* fp, Pessoa p[], int n) {

	if (fp == NULL) return false;
	if (n <= 0) return false;

	for (int i = 0; i < n; i++) {
		fwrite(&p[i], 1, sizeof(Pessoa), fp);
	}
}

/**
 * @brief .
 * 
 * @param fp
 * @return 
 * @author lufer
 *
 */
bool ShowFile(FILE* fp) {
	Pessoa p;
	int count;
	if (fp == NULL) return false;
	while(!feof(fp)){
		count=fread(&p, 1, sizeof(Pessoa), fp);
		if(count>0) 
			printf("Nome: %s - Idade: %d\n", p.nome, p.idade);
	}
}
