/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  Implementação de funções
 * 
 * @author lufer
 * @date   November 2022
 *********************************************************************/
#include "Header.h"
#include <stdio.h>


/**
 * @brief .
 * 
 * @param p
 * @param s
 * @param nova
 * @return 
 * @author lufer
 *
 */
int InserePessoa(Pessoa p[], int s, Pessoa nova) {
	//Verificar se existe espaço
	if (s >= N) return s;

	//Verificar se "nova" já existe
	for (int i = 0; i < s; i++) {
		//se existe, termina!
		if (strcmp(nova.nome, p[i].nome) == 0) return s;
	}
	//Se não existe
	p[s] = nova;
	s++;
	return s;
}

/**
 * @brief .
 * 
 * @param p
 * @param s
 * @author lufer
 *
 */
void MostraTurma(Pessoa p[], int s) {
	for (int i = 0; i < s; i++) {
		printf("Nome: %s - Idade: %d\n", p[i].nome, p[i].idade);
	}
}

/**
 * @brief Versão com apontadores!!!
 * 
 * @param p
 * @param s
 * @param nova
 * @return 
 * @author lufer
 *
 */
bool InserePessoaII(Pessoa p[], int* s, Pessoa nova) {
	//Verificar se existe espaço
	if (s >= N) return false;

	//Verificar se "nova" já existe
	for (int i = 0; i < *s; i++) {

		//if (nova.nome == p[i].nome) return false;

		if (strcmp(nova.nome, p[i].nome) == 0) return false;
	}
	//se não existe, insere!
	p[*s] = nova;
	*s++;
}


/**
 * @brief Gravar em ficheiro.
 * 
 * @param p
 * @param s
 * @param nome
 * @return 
 * @author lufer
 *
 */
bool GravaTurma(Pessoa p[], int s, char nomeFicheiro[]) {
	//abrir o ficheiro
	FILE* fp;
	fp = fopen(nomeFicheiro, "wb");
	if (fp == NULL) return false;
	for (int i = 0; i < s; i++) {
		fwrite(&p[i], 1, sizeof(p[i]), fp);
		//se fosse ficheiro de texto
		//fprintf("%s;%d", p[i].nome, p[i].idade, fp);
	}
	
	fclose(fp);
	return true;
}

/**
 * @brief Le e mostra ficheiro.
 * 
 * @param nomeFile
 * @return 
 * @author lufer
 *
 */
bool MostraFicheiro(char nomeFile[]) {
	FILE* fp;
	Pessoa p;
	int count = 0;

	//Tentar abrir o ficheiro
	fp = fopen(nomeFile, "rb");
	if (fp == NULL) {
		return false;
	}
	//Enquanto não chegar ao fim do ficheiro
	while (!feof(fp)) {
		count=fread(&p, 1, sizeof(Pessoa), fp);
		if(count>0) 
			printf("Nome: %s - Idade: %d\n", p.nome, p.idade);
	}

	fclose(fp);
}

