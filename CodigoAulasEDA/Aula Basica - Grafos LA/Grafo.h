#pragma once

#include <stdio.h>
#include <stdbool.h>

#define N 20

#pragma warning (disable: 4996)
/**
 * Estrutura de uma Adjac�ncia.
 */
typedef struct Adj {
	int cod;		/*!< C�digo da Adjac�ncia */
	float dist;		/*!< Peso */
	struct Adj *next;
}Adj;

/**
 * Descri��o de um V�rtice do grafo.
 */
typedef struct Vertice {
	int cod;					/*!< C�digo do V�rtice */
	char cidade[N];				/*!< Nome da Cidade */
	struct Vertice* next;		/*!< Lista de V�rtices */
	struct Adj* adjacentes;		/*!< Lista de Adjac�ncias */
} Vertice;

#pragma region GRAFO

Vertice* CriaGrafo();
Vertice* InsereVertice(Vertice* g, Vertice* novo, bool*res);
Vertice* CriaVertice(char* cidade, int tot);
void MostraGrafo(Vertice* g);
int ProcuraCodVertice(Vertice* g, char* cidade);
Vertice* ProcuraVertice(Vertice* g, char* cidade);

#pragma endregion

#pragma region ADJACENCIAS

Vertice* InsereAdjacenteVertice(Vertice* g, char* origem, char* dest, float peso, bool* res);

#pragma region LISTA_ADJACENCIAS

Adj* CriaAdj(int cod, float peso);
Adj* InsereAdj(Adj* h, Adj* novo, bool* res);
bool ProcuraAdj(Adj* h, int cod);
void MostraAdjacencias(Adj* h);

#pragma endregion
#pragma endregion
