
/*****************************************************************//**
 * @file   Cidades.c
 * @brief  
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#include "Dados.h"
#include <stdlib.h>


Cidade* CriaCidade(char* nome) {
	Cidade* nova = (Cidade*)calloc(1, sizeof(Cidade));
	if (nova == NULL) return NULL;
	strcpy(nova->nome, nome);
	nova->next = NULL;
	return nova;
}

/**
 * Regista nova Cidade
 */
bool RegistaCidade(Cidade** c, Cidade* nova) {
	if (*c == NULL)
	{
		*c = nova;
		return true;
	}
	else
	{
		Cidade* aux = *c;
		Cidade* ant = aux;
		while (strcmp(aux->nome, nova->nome) > 0) {
			ant = aux;
			aux = aux->next;
		}
		if (ant == aux) {
			nova->next = *c;
			*c = nova;
		}
		else
		{
			nova->next = aux;
			ant->next = nova;
		}
		return true;
	}
}

Cidade* RegistaCidadeRecursiva(Cidade* h, Cidade* nova, bool *res) {

	if (h == NULL) {
		*res = true;
		h = nova;
		return h;
	}
	else
	{
		if (strcmp(h->nome, nova->nome) >= 0) {
			//insere
			nova->next = h;
			h = nova;
			*res = true;
		}
		else
			h->next = RegistaCidadeRecursiva(h->next, nova, res);
	}
	return h;
}


void MostraCidades(Cidade* c) {
	if (c == NULL) return;
	printf("Cidade: %s\n", c->nome);
	MostraCidades(c->next);
}


