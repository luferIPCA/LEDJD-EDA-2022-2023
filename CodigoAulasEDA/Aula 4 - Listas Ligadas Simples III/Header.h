/*****************************************************************//**
 * @file   Header.h
 * @brief  
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#pragma once
#include <stdbool.h>

typedef struct Cliente{
	int num;
}Cliente;


typedef struct ClienteLista {
	Cliente c;
	struct ClienteLista* next;
}ClienteLista;
/**
 * Altera Lista e devolve resultado da opera��o.
 * Recebe um apontador para struct
 */
bool InsertNode(ClienteLista** h, Cliente* novo);

/**
 * Altera Lista, devolve resultado
 * Segue padr�o SOLID (S: "Single Responsability")
 * O m�todo apenas gera a lista. O novo elemento entra criado.
 * Recebe um apontador para struct da lista
 */
bool InsertNodeII(ClienteLista** h, ClienteLista* novo);

void MostraLista(ClienteLista* h);




