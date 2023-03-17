/*****************************************************************//**
 * @file   Header.h
 * @brief  
 * 
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#pragma once
#include <stdbool.h>

typedef struct Nodo {
	int numero;
}Nodo;

typedef struct NodoLista {
	Nodo n;
	struct NodoLista* next;
}NodoLista;

NodoLista* InsereNodoLista(NodoLista* head, NodoLista* novo);
NodoLista* InsereNodoListaII(NodoLista* head, Nodo* novo);
void MostraLista(NodoLista* h);
bool ExisteValor(NodoLista* h, int valor);
NodoLista* ProcuraValor(NodoLista* h, int valor);
int GravaTudo(NodoLista* h, char fileName[]);
NodoLista* LerDados(char fileName[]);
bool DestroiLista(NodoLista* h);
