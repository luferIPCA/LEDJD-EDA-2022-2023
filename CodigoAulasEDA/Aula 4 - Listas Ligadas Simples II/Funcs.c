/*****************************************************************//**
 * @file   Funcs.c
 * @brief  
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include "Header.h"
#include <stdio.h>


/**
 * @brief COMLETAR!!!!
 * 
 * @param head
 * @param novo
 * @return 
 * @author lufer
 *
 */
NodoLista* InsereNodoLista(NodoLista* head, NodoLista* novo) {

	//Lista é vazia
	if (head == NULL)
	{
		head = novo;
		return head;
	}
}

/**
 * @brief .
 * 
 * @param head
 * @param novo
 * @return 
 * @author lufer
 *
 */
NodoLista* InsereNodoListaII(NodoLista* head, Nodo* novo) {

	//Cria nodo da lista
	//Copiar novo para nodo da lista
	NodoLista* aux = (NodoLista*)malloc(sizeof(NodoLista));
	aux->next = NULL;
	aux->n = *novo;

	//Lista é vazia
	if (head == NULL)
	{
		head = aux;
		return head;
	}
	else {
		//Inserir ordenado
		if (head->n.numero > aux->n.numero) {	//Insere no inicio
			aux->next = head;
			head = novo;
		}
		else {									//Inserir no meio ou no fim
			NodoLista* anterior = head;
			NodoLista* nodoAtual = head;
			//procurar posição onde inserir
			while (nodoAtual && nodoAtual->n.numero < aux->n.numero) {
				anterior = nodoAtual;
				nodoAtual = nodoAtual->next;
			}
			aux->next = nodoAtual;
			anterior->next = aux;
		}
	}
	return head;
}

/**
 * @brief Mostra conteudo da lista.
 * 
 * @param h
 * @author lufer
 *
 */
void MostraLista(NodoLista* h) {
	NodoLista* aux = h;
	while (aux != NULL) {
		printf("Valor: %d\n", aux->n.numero);
		aux = aux->next;
	}
}


/**
 * @brief .
 * 
 * @param h
 * @param valor
 * @return 
 * @author lufer
 *
 */
bool ExisteValor(NodoLista* h, int valor) {
	if (h == NULL) return false;
	NodoLista* aux = h;
	while (aux != NULL) {
		if (aux->n.numero == valor) return true;
		aux = aux->next;
	}
	return false;
}

/**
 * @brief .
 * 
 * @param h
 * @param valor
 * @return 
 * @author lufer
 *
 */
NodoLista* ProcuraValor(NodoLista* h, int valor) {
	if (h == NULL) return NULL;
	NodoLista* aux = h;
	while (aux != NULL) {
		if (aux->n.numero == valor) return aux;
		aux = aux->next;
	}
	return NULL;
}

/**
 * @brief .
 * 
 * @param h
 * @param fileName
 * @return 
 * @author lufer
 *
 */
int GravaTudo(NodoLista* h, char fileName[]) {
	if (h == NULL) return (-1);
	NodoLista* aux = h;

	//Ficheiro
	FILE* fp;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return (-2);
	//if (fp = fopen(fileName, "wb") == NULL) return -2;
	while (aux!=NULL) {
		fwrite(&aux->n, 1, sizeof(Nodo), fp);
		aux = aux->next;
	}
	fclose(fp);
	return 1;
}

NodoLista* LerDados(char fileName[]) {

	NodoLista* h=NULL;
	//Ficheiro
	FILE* fp;
	fp = fopen(fileName, "rb");
	if (fp == NULL) return (-2);
	//if (fp = fopen(fileName, "wb") == NULL) return -2;
	Nodo* aux;
	while (fread(&aux,1,sizeof(Nodo),fp)) {
		h = InsereNodoLista(h, &aux);
	}
	fclose(fp);
	return h;
}


bool DestroiLista(NodoLista* h) {
	if (h == NULL) return false;
	NodoLista* aux;
	while (h != NULL) {
		aux = h->next;
		free(h);
		h = aux;
	}
	return true;
}
