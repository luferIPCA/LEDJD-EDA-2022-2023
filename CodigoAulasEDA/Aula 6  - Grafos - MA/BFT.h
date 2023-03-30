
/*
//Grafos Não Orientados | Orientados
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
//lufer

*/

#include "Graphs.h"

#ifndef BFT
#define BFT 

#define MAXDISTANCE 9999

//Auxiliar ao Dijkstra
typedef struct Best {
	int distance[MAX];
	int anteriores[MAX];
}Best;

// =====================================================
// Breadth First Algorithm
// =====================================================

//assinaturas
//queue functions
void insertQueue(int data);
int nextQueue();
bool isQueueEmpty();

//graphs functions
void breadthFirstSearch(Vertice *gr[], int vertice);
Best bestPath(int adjMatrix[MAX][MAX], int n, int v);

//auxiliar
void ShowAllPath(Best b, int n, int v);
#endif // !BFT