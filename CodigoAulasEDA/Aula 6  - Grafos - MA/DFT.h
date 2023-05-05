/*
Grafos Não Orientados | Orientados

Procura em Profundidade: Stack
Procura em Largura:		Queue
lufer

Ver 
	http://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal_in_c.htm
	https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
	https://www.simplilearn.com/tutorials/data-structure-tutorial/bfs-algorithm
	*/

#include <stdio.h>
#include <stdbool.h>
#include "Graphs.h"

// =====================================================
//Depth First Algorithm : STACK
// =====================================================

#ifndef DFS
#define DFS

int stack[MAX];  
int top;  

//assinaturas
//Stack
void push(int item);
int pop();
int peek();
bool isStackEmpty();
//graph
void DFT(int adjMatrix[][MAX], Vertice *gr[], int totVertices);
//Traversai DFT recursiva
void DFTRecursivo(int adjMatrix[][MAX], Vertice* lstVertices[], int totVertices, int origem);
//DFT Search Recursivo
bool DepthFirstSearchRec(int adjMatrix[][MAX], Vertice* lstVertices[], int totVertices, int origem, int cod);

#endif // !DFS