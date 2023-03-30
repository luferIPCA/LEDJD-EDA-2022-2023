/**
*
* lufer
*
* Grafos Não Orientados | Orientados
*
* Procura em Profundidade: Stack
* Procura em Largura:		Queue
* Consultar:
* https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/
*/

#include <stdio.h>
#include <stdbool.h>

#ifndef GRF
#define GRF

#define MAX 6 

//Vertice
typedef struct Vertice {
	char nome;
	bool visitado;
	int distance;
}Vertice;

//Estruturas para o Grafo 
//
//"Lista" de vértices 
Vertice* lstVertices[MAX];
//
//Matriz de adjacências
int adjMatrix[MAX][MAX];
//

//auxiliar
int vertCount;

bool InitAdj(int m[][MAX], int tot);
void AddEdge(int start, int end);
void AddEdgeWeight(int start, int end, int peso);
//int AddVertice(char label, int c);
bool AddVertice(Vertice* gr[], char label, int *count);
//void ProcessaVertice(int vertIndex);
void ProcessaVertice(Vertice *lstVertices[], int vertIndex);
//int GetVertAdjunNaoVisitado(int vertIndex);
int GetVertAdjunNaoVisitado(Vertice *lstVertices[], int vertIndex);

#endif // 

