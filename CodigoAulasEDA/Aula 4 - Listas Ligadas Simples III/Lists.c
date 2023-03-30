/*****************************************************************//**
 * @file   Lists.c
 * @brief  
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Altera Lista e devolve resultado da operação
 * Cria memória e insere na lista
 * @param h
 * @param 
 * @return 
 * @author lufer
 *
 */
bool InsertNode(ClienteLista** h, Cliente* n){
	if (*h == NULL || n==NULL) return false;
	ClienteLista* aux = *h;
	ClienteLista* ant = NULL;
	//Carrega dados do registo novo
	ClienteLista* novo = (ClienteLista*)calloc(1,sizeof(ClienteLista));
	if (!novo) return false;
	novo->c = *n;
	novo->next = NULL;
	
	//Insere ordenado; admite repetidos!
	while (aux && aux->c.num < n->num) {
		ant = aux;
		aux = aux->next;
	}
	if (aux == *h)	//insere à cabeça
	{
		novo->next = *h;
		*h = novo;
	}
	else
	{
		ant->next = novo;
		novo->next = aux;
	}
	return true;
}

/**
 * @brief Altera Lista, devolve resultado
 * Segue padrão SOLID (S: "Single Responsability")
 * O método apenas gera a lista. O novo elemento entra criado
 * @param h
 * @param novo
 * @return 
 * @author lufer
 *
 */
bool InsertNodeII(ClienteLista** h, ClienteLista* n) {
	
	if (h == NULL || n==NULL) return false;
	ClienteLista* aux = *h;
	ClienteLista* ant = NULL;

	//Insere ordenado; admite repetidos!
	while (aux && aux->c.num < n->c.num) {
		ant = aux;
		aux = aux->next;
	}
	if (aux == *h)	//insere à cabeça
	{
		n->next = *h;
		*h = n;
	}
	else
	{
		ant->next = n;
		n->next = aux;
	}
	return true;
}

/**
 * @brief .
 * 
 * @param h
 * @author lufer
 *
 */
void MostraLista(ClienteLista* h) {
	if (h == NULL) printf("Vazia...");
	ClienteLista* aux = h;
	while (aux) {
		printf("Num: %d\n", aux->c.num);
		aux = aux->next;
	}
}
