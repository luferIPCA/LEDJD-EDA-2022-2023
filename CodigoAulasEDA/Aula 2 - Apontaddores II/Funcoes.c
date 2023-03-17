/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  Funções para gerir arrays de apontadores
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include "Header.h"

/**
 * @brief .
 * 
 * @param p
 * @param t
 * @return 
 * @author lufer
 *
 */
bool InicializaArray(Pessoa* p[], int t) {
	if (t <= 0) return false;
	for (int i = 0; i < t; i++) {
		p[i] = NULL;
	}
	return true;
}

/**
 * @brief Insere nova pessoa
 * 
 * @param p
 * @param t - valor corrente de pessoas
 * @param nova
 * @return true: inseriu ; false: não inseriu
 * @author lufer
 *
 */
bool InserePessoa(Pessoa* p[], int *t, Pessoa n) {
	//Verificar se existe espaço?
	//Verificar se não existe
	p[*t] = &n;
	(*t)++;
	return true;
}

/// @brief Insere nova pessoa e devolve o novo tamaho do array
/// @param p 
/// @param t tamanho atual do array 
/// @param n 
/// @return novo tamanho do array 
int InserePessoaII(Pessoa* p[], int t, Pessoa n) {
	//Existe espaço?
	//Se não existe
	//p[*t] = &n;
	p[t] = (Pessoa*)malloc(sizeof(Pessoa));
	p[t]->idade = n.idade;
	strcpy(p[t]->nome, n.nome);
	t++;
	return t;
}




