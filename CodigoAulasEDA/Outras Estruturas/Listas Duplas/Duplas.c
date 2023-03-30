//-----------------------------------------------------------------------
// <copyright file="Duplas.c" company="IPCA">
//     Copyright IPCA. All rights reserved.
//
// </copyright>
// <date>2020</date>
// <author>lufer</author>
// <email>lufer@ipca.pt</email>
// <version>1</version>
// <desc>Manipular Listas Duplamente Ligadas</desc>
// <obs> Ver http ://btechsmartclass.com/DS/U1_T12.html </desc>
//-----------------------------------------------------------------------

#include "Duplas.h"
#include <stdio.h>

/*
Inicia a Lista
*/
NodoPtr Inicia(NodoPtr h) {
	h = NULL;
	return h;
}

/*
Cria um novo nodo
*/
NodoPtr NovoNodo(int x) {
	NodoPtr nova = (NodoPtr)malloc(sizeof(Nodo));
	if (nova != NULL)		//se consegue alocar memoria...
	{
		nova->v = x;
		nova->next = NULL;
		nova->prev = NULL;
	}		
	return nova;
}


/*
FAZER
*/
//NodoPtr InsereNodoII(NodoPtr h, Nodo n) {
//	NodoPtr aux = h;
//	if (h == NULL) //se a lista estiver vazia
//	{
//		//n->next = NULL;
//		//n->prev = NULL;
//		h = &n;
//	}
//	else
//	{
//		while (aux->next != NULL && aux->v < n.v)  //procura onde inserir			
//		{
//			aux = aux->next;
//		}
//		if (aux == h)				//inserir no inicio
//		{
//			n.next = aux;
//			aux->prev = &n;
//			h = &n;
//		}
//		else
//			if (aux->next == NULL)
//			{
//				if (aux->v > n->v) {	//insere na penúltima posição
//					n->next = aux;
//					n->prev = aux->prev;
//					aux->prev->next = n;
//					aux->prev = n;
//				}
//				else {					//inserir no fim
//					aux->next = n;
//					n->prev = aux;
//				}
//			}
//			else						//insere no meio
//			{
//				n->next = aux;
//				n->prev = aux->prev;
//				aux->prev->next = n;
//				aux->prev = n;
//			}
//	}
//	return h;
//}

/*
Insere nodo de forma ordenada!
*/
Nodo* InsereNodo(Nodo* h, Nodo *n) { //Nodo * é o mesmo que NodoPtr
	NodoPtr aux = h;
	if (h == NULL) //se a lista estiver vazia
	{
		h = n;
	}
	else
	{
		//ver se insere logo à cabeça da lista
		if (h->v >= n->v) {
			n->next = aux;
			aux->prev = n;
			h = n;
		}
		else
		{
			//procura onde inserir
			while (aux->next != NULL && aux->v < n->v)
			{
				aux = aux->next;
			}
			if (aux->v >= n->v) {	//insere entre células
				n->next = aux;
				n->prev = aux->prev;
				aux->prev->next = n;
				aux->prev = n;
			}
			else					//inserir no fim
			{
				aux->next = n;
				n->prev = aux;
			}			
		}
	}
	return h;
}

#pragma region SEARCH
/*
Procura e devolve apontador (I)
*/
Nodo* Search(Nodo *h, Nodo *n)
{	
	if (!h)	 return NULL;	//if(h==NULL)
	NodoPtr aux = h;

	while (aux && (aux->v != n->v))
		{
			aux = aux->next;
		}
	return aux;	
}

/*
Procura e devolve apontador (II)
Parâmetro: apenas o valor
*/
NodoPtr SearchII(Nodo *h, int valor)
{
	NodoPtr aux = h;
	if (!h)
	{
		aux = h;
	}
	else
	{
		while (aux && (aux->v != valor))
		{
			aux = aux->next;
		}
	}
	return aux;
}


Nodo SearchV(Nodo *h, Nodo *valor) {
	if (!h) {
		Nodo aux = { -2,NULL,NULL };	//Nodo "virtual" para controlar
		return aux;	//????
	}
	Nodo* aux = h;

	while (aux && (aux->v != valor->v))
	{
		aux = aux->next;
	}
	return *aux;
}


Boolean SearchVII(Nodo *h, Nodo valor) {
	if (h == NULL) return false;
	Nodo* aux = h;
	while (aux != NULL && aux->v != valor.v) aux = aux->next;
	//if (aux) 
	//	return true;
	//else
	//	return false;
	return (aux != NULL);
}
#pragma endregion


#pragma region REMOVE
/*
Remove elemento em Lista Dupla (I)
Lista não ordenada
*/
NodoPtr Remove(Nodo *h, int num) {
	
	if (h == NULL) return h;		//lista vazia
	
	//Localizar nodo a remover
	Nodo *aux = h;
	while (aux && aux->v != num) {	//Quando será suficiente "<"?
		aux = aux->next;
	}

	//Se aux é NULL não existe nodo a remover
	if (aux != NULL) {				//significa que existe o nodo para remover
		if (aux == h) {				//remove no início
			h = h->next;
			aux->next->prev = NULL;
			free(aux);
		}
		else {						//remover no meio e fim
			aux->prev->next = aux->next;
			if (aux->next) {		//remove no fim!!!
				aux->next->prev = aux->prev;
			}
			free(aux);
		}
	}
	return h;
}


/*
Remove elemento em Lista Dupla (II)
Lista ordenada...pode não ser necessário percorrer a lista toda!
*/
NodoPtr RemoveII(Nodo *h, int num) {
	if (h == NULL) return h;
	//localizar
	Nodo *aux = h;
	while (aux && aux->v < num) {	
		aux = aux->next;
	}
	if (aux->v == num) {			//significa que existe o nodo para remover
		if (aux == h) {				//remove no início
			h = h->next;
			aux->next->prev = NULL;
			//free(aux);
		}
		else {
			aux->prev->next = aux->next;
			if(aux->next)
				aux->next->prev = aux->prev;
			//free(aux);
		}
		free(aux);
	}
	return h;
}


/*
Remove elemento em Lista Dupla (III)
*/
Boolean RemoveIII(Nodo **h, int num) {
	if (h == NULL) return false;
	Nodo *aux = *h;

	while (aux && aux->v != num) {
		aux = aux->next;
	}

	if (aux != NULL) {
		//no início
		if (aux == *h) {
			*h = (*h)->next;
			aux->next->prev = NULL;
			free(aux);
		}
		else {			
			if (aux->next == NULL) {	//remove última posição
				aux->prev->next = NULL;
				aux->prev = NULL;
			}
			else
			{
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;				
			}
			free(aux);
			//no meio...
		}
		return true;
	}
	return false;
}

#pragma endregion

/*
Devolve sub-lista de nodos
Lista Ordenada
*/
NodoPtr SubLista(NodoPtr h, int vIni, int vFim) {
	NodoPtr newHead = NULL;
	NodoPtr aux = h;
	if (!h)			//se está vazia
	{
		newHead = h;
	}
	else
	{
		while (aux && (aux->v <= vFim && aux->v >= vIni))
		{
			NodoPtr aux2 = NovoNodo(aux->v);	//Não poderia ser aux2=aux?
			newHead = InsereNodo(newHead, aux2);
			aux = aux->next;
		}
	}
	return newHead;
}


#pragma region OUTPUT
/*======================================================
Output
=======================================================*/

/*
Mostra toda a Lista Duplamente Ligada
*/
void ShowAll(Nodo *h) {
	Nodo *aux = h;
	if (aux != NULL)
	{
		printf("Valor: %d\n", aux->v);
		ShowAll(aux->next);
	}
}

/*
Mostra nodo
*/
void ShowNode(Nodo *n) {
	if (n != NULL) {
		printf("Valor= %d\n", n->v);
	}
}
#pragma endregion

#pragma region FICHEIROS

/* 
======================================================
Ficheiros
=======================================================
*/

/*
Preservar dados em ficheiro binário
*/
Boolean Save(Nodo *h) {
	FILE *fp; 
	if (h == NULL) return false;

	if ((fp = fopen("data.bin", "wb")) == NULL)
	{
		return false;
	}

	Nodo *current = h;
	Nodo *holdNext;
	while (current != NULL) {
		holdNext = current->next;
		if (holdNext) holdNext->prev = NULL;
		current->next = NULL;
		current->prev = NULL;
		//fseek(fp, 0, SEEK_END);
		fwrite(current, sizeof(Nodo), 1, fp);	//testar se gravou bem!!!
		current = holdNext;
		holdNext = NULL;
	}

	fclose(fp);
	fp = NULL;
	return true;
}

/*
Preserva alguns registos para ficheiros
COMPLETAR
*/
Boolean SaveSome(Nodo *h, int vIni, int vFim) { return true; }

/*
Carrega dados do ficheiro
*/
Nodo *Load(Nodo *h) {
	FILE *fp;
	fp = fopen("data.bin", "rb");
	if (fp == NULL) return false;

	//limpar lista
	//if(h!=NULL) DeleteAll(h);
	h = NULL;

	//ler e construir lista	
	Nodo *aux;
	aux = (Nodo*)malloc(sizeof(Nodo));
	while (fread(aux, sizeof(Nodo), 1, fp) != 0) {
		aux->next = NULL;
		aux->prev = NULL;
		h = InsereNodo(h,aux);
		aux = (Nodo*)malloc(sizeof(Nodo));
	}

	fclose(fp);
	fp = NULL;

	return h;
}


/*
Carrega alguns dados do ficheiro
COMPLETAR
*/
Boolean LoadSome(Nodo *h, int vIni, int vFim) { return true; }

#pragma endregion