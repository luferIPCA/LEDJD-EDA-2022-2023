#pragma once

#include <stdio.h>
#include <stdbool.h>

#define N 20



#pragma warning (disable: 4996)
/**
 * Estrutura de uma Adjacência.
 */
typedef struct Adj {
	int cod;		/*!< Código da Adjacência */
	float dist;		/*!< Peso */
	struct Adj *next;
}Adj;

/**
 * Descrição de um Vértice do grafo.
 */
typedef struct Vertice {
	int cod;					/*!< Código do Vértice */
	char cidade[N];				/*!< Nome da Cidade */
	bool visitado;
	struct Vertice* next;		/*!< Lista de Vértices */
	struct Adj* adjacentes;		/*!< Lista de Adjacências */
} Vertice;

#pragma region GRAFO

Vertice* CriaGrafo();
Vertice* InsereVertice(Vertice* g, Vertice* novo, bool*res);
Vertice* CriaVertice(char* cidade, int tot);
void MostraGrafo(Vertice* g);
int ProcuraCodigoVertice(Vertice* g, char* cidade);
Vertice* ProcuraVertice(Vertice* g, char* cidade);
Vertice* ProcuraVerticeCod(Vertice* g, int cod);

#pragma endregion

#pragma region ADJACENCIAS

Vertice* InsereAdjacenteVertice(Vertice* g, char* origem, char* dest, float peso, bool* res);

#pragma region LISTA_ADJACENCIAS

Adj* CriaAdj(int cod, float peso);
Adj* InsereAdj(Adj* h, Adj* novo, bool* res);
bool ExisteAdjacentes(Adj* h, int cod);
void MostraAdjacencias(Adj* h);

#pragma endregion

#pragma endregion

#pragma region ALGORITMOS

int CountPaths(Vertice* g, int src, int dst, int pathCount);
int CountPathsVerticesName(Vertice* g, char* src, char* dest, int pathCount);

bool DepthFirstSearchRec(Vertice* g, int origem, int dest);
bool DepthFirstSearchNamesRec(Vertice* g, char* src, char* dest);

Vertice* ResetVerticesVisitados(Vertice* g);

#pragma endregion


