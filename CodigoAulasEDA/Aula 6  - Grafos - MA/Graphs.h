/**
*
* lufer
*
* Grafos N�o Orientados | Orientados
*
* Procura em Profundidade:	Stack
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
//"Lista" de v�rtices 
Vertice* lstVertices[MAX];


//auxiliar: ATEN��O: passar para vari�vel locale par�metro!!!
int vertCount;

//Matriz de Adjac�ncias
bool InitAdj(int m[][MAX], int tot);
void AddEdge(int m[][MAX], int start, int end);
//Pesos s�o "int"
void AddEdgeWeight(int m[][MAX], int start, int end, int peso);


//Vertices
//int AddVertice(char label, int c);
bool AddVertice(Vertice* gr[], char label, int *count);
//void ProcessaVertice(int vertIndex);
void ProcessaVertice(Vertice *lstVertices[], int vertIndex);
//int GetVertAdjunNaoVisitado(int vertIndex);
int GetVertAdjunNaoVisitado(int m[][MAX], Vertice *lstVertices[], int vertIndex);

#endif // 

