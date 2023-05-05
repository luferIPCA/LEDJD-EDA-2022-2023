/*
Grafos: Fundamentos com MATRIZ DE ADJACENCIAS
lufer

Consultar:
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET
#include <stdlib.h>
#include "Graphs.h"

//======================================================
//graph functions 
//======================================================

/*
Inicializa a matriz de adjacências
*/
bool InitAdj(int m[][MAX], int tot) {
	if (tot <= 0 || tot > MAX) return false;
	for (int i = 0; i<tot; i++)  
	{
		for (int j = 0; j<tot; j++) // matrix to 0 
			m[i][j] = 0;
	}
	return true;
}

/*
Insere vertice no grafo
*/
bool AddVertice(Vertice* gr[], char label, int *count) {
	if (*count <0 || *count>MAX) return false;
	//insere
	struct Vertice* novoVert = (struct Vertice*) malloc(sizeof(struct Vertice));
	novoVert->nome = label;
	novoVert->visitado = false;
	gr[(*count)++] = novoVert;
	return true;
}

/*
Adicionar aresta ao conjunto de arestas. Grafo não orientado!
*/
void AddEdge(int adjMatrix[][MAX],int start, int end) {
	//testes...
	adjMatrix[start][end] = 1;
	adjMatrix[end][start] = 1;
}

void AddEdgeWeight(int adjMatrix[][MAX], int start, int end, int peso) {
	//testes...
	adjMatrix[start][end] = peso;
	adjMatrix[end][start] = peso;
}

//display the vertex 
void ProcessaVertice(Vertice *lstVertices[], int vertIndex) {
	printf("\nVertice %c (%d) \n ", lstVertices[vertIndex]->nome, vertIndex);
}

//get the adjacent unvisited vertex 
int GetVertAdjunNaoVisitado(int adjMatrix[][MAX], Vertice *lstVertices[], int vertIndex) {
	int i;

	for (i = 0; i<vertCount; i++) {
		//if (adjMatrix[vertIndex][i] == 1 && lstVertices[i]->visitado == false)
		if (adjMatrix[vertIndex][i] >0 && lstVertices[i]->visitado == false)
			return i;
	}
	return -1;
}
