/*****************************************************************//**
 * @file   Veiculos.c
 * @brief  
 * 
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#include "Dados.h"


Veiculo* NovoVei(int i) {
	Veiculo *n = (Veiculo*)calloc(1, sizeof(Veiculo));
	if (n == NULL) return NULL;
	n->cod = i;
	n->next = NULL;
}

Veiculo* InsereVei(Veiculo* h, Veiculo* novo, bool *res) {
	if (h == NULL) {
		h = novo;
		*res = true;
		return h;
	}
	else {
		Veiculo* aux = h;
		Veiculo* ant = aux;
		while (aux->cod < novo->cod) {
			ant = aux;
			aux = aux->next;
		}
		if (aux == h) {
			novo->next = h;
			h = novo;
		}
		else {
			novo->next = aux;
			ant->next = novo;
		}
		*res = true;
	}
	return h;
}


Veiculo* InsereVeiRecursivo(Veiculo* h, Veiculo* novo, bool* res) {
	if (h == NULL) {
		h = novo;
		*res = true;
		return h;
	}
	else
	{
		if (h->cod > novo->cod) {
			novo->next = h;
			h = novo;
			*res = true;
		}
		h->next = InsereVeiRecursivo(h->next, novo, res);
	}
	return h;
}

void MostraLista(Veiculo* h) {
	if (h == NULL) return;
	Veiculo* aux = h;
	while (aux) {
		printf("V: %d\n", aux->cod);
		aux = aux->next;
	}
}

void MostraListaRecursiva(Veiculo* h) {
	if (h == NULL) return;
	printf("V: %d\n", h->cod);
	MostraListaRecursiva(h->next);

}


