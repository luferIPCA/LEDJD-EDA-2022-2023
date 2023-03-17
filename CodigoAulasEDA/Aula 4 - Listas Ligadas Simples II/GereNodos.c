/*****************************************************************//**
 * @file   GereNodos.c
 * @brief  
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include "Header.h"
#include <stdio.h>	//NULL
#include <stdlib.h>	//malloc

int main() {

#pragma region APONTADORES

	NodoLista *inicio = LerDados("Dados.bin");
	if (inicio == NULL) {
		//LER dados de txt
	}

	//Criar um nodo
	Nodo x;
	x.numero = 7;

	//Criar um nodo da Lista
	NodoLista nl;
	nl.n = x;

	//Criar apontador para Nodo
	Nodo* p;
	p = &x;

	//Criar apontador para NodoLista
	NodoLista* l;
	l = &nl;
	l->n.numero = 234;

	//Criar um nodo com alocação de memória
	Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
	aux->numero = 10;

	//Criar um nodoLista com alocação dinamica
	NodoLista* auxLista = (NodoLista*)malloc(sizeof(NodoLista));
	auxLista->n = *aux;
	auxLista->next = NULL;

#pragma endregion

#pragma region LISTA
	//
	////Novo nodo a inserir na lista
	//NodoLista* novo = (NodoLista*)malloc(sizeof(NodoLista));
	//novo->n.numero = 23;
	//novo->next = NULL;
	//
	//NodoLista* inicio = NULL;	//Inicio da lista
	//
	//if (inicio == NULL)			//caso em que a lista é vazia
	//	inicio = novo;
	//else
	//{
	//	//h1: Inserir no início da lista
	//	//1ºpasso
	//	novo->next = inicio;
	//	inicio = novo;

	//	//h2: Inserir no fim da lista
	//	NodoLista* nodoAtual;	//auxiliar para percorrer a lista
	//	//encontro o fim da lista
	//	nodoAtual = inicio;
	//	while (nodoAtual->next != NULL)
	//		nodoAtual = nodoAtual->next;
	//	//insiro no fim da lista
	//	nodoAtual->next = novo;
	//	novo->next = NULL;

	//	//h3: Inserir entre Nodos - Inserção ordenada
	//	NodoLista* anterior;
	//	nodoAtual = inicio;
	//	while (nodoAtual->n.numero<novo->n.numero)// && nodoAtual->next != NULL) {
	//	{
	//		anterior = nodoAtual;
	//		nodoAtual = nodoAtual->next;
	//	}
	//	novo->next = nodoAtual;
	//	anterior->next = novo;
	//}
	NodoLista* inicio = NULL;

	inicio = InsereNodoLista(inicio, &x);

	bool b = ExisteValor(inicio, 5);
	if (b == true) {
		puts("Existe");
	}

	NodoLista* aux = ProcuraValor(inicio, 5);
	if (aux == NULL) {
		puts("Não Existe");
	}

	int g = GravaTudo(inicio, "Dados.bin");
	if (g == 1) {
		puts("Sucesso!!!");
	}

	DestroiLista(inicio);
	inicio = NULL;	//ATENCAO!!!

	


#pragma endregion
}
