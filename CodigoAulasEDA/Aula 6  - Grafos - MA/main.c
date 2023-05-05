/*
Grafos: Fundamentos com MATRIZ DE ADJACENCIAS
lufer
Consultar:
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET
#include "Graphs.h"
#include "BFT.h"
#include "DFT.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i;
	bool aux;
	vertCount = 0;

	//
	//Matriz de adjacências
	int adjMatrix[MAX][MAX];
	//

	aux = InitAdj(adjMatrix, MAX);
    
	//Constroi grafo
	aux = AddVertice(lstVertices, 'S', &vertCount);   // 0 
	aux = AddVertice(lstVertices, 'A', &vertCount);   // 1 
	aux = AddVertice(lstVertices, 'B', &vertCount);   // 2 
	aux = AddVertice(lstVertices, 'C', &vertCount);   // 3 
	aux = AddVertice(lstVertices, 'D', &vertCount);   // 4 
	aux = AddVertice(lstVertices, 'E', &vertCount);   // 5
  
	//AddEdge(0, 1, 7);    // S - A 
	//AddEdge(0, 2, 12);    // S - B 
	//AddEdge(0, 3, 9);    // S - C 
	//AddEdge(1, 4, 3);    // A - D 
	//AddEdge(2, 4, 7);    // B - D 
	//AddEdge(3, 4, 1);    // C - D 

	//Define Grafo com MA

	AddEdgeWeight(adjMatrix,0, 1, 8);    // S - A 
	AddEdgeWeight(adjMatrix, 0, 2, 12);    // S - B 
	AddEdgeWeight(adjMatrix, 0, 3, 9);    // S - C 
	AddEdgeWeight(adjMatrix, 1, 4, 3);    // A - D 
	AddEdgeWeight(adjMatrix, 2, 4, 7);    // B - D 
	AddEdgeWeight(adjMatrix, 3, 4, 1);    // C - D 
	AddEdgeWeight(adjMatrix, 3, 5, 2);    // C - E 
   
	//Mostra um determinado vertice
	ProcessaVertice(lstVertices,3);

	printf("\nTravessia Depth First:\n");    
	DFT(adjMatrix, lstVertices, vertCount);

	printf("\nTravessia Depth First Recursiva:\n");
	DFTRecursivo(adjMatrix, lstVertices, vertCount, 0);

	// reset de vertices visitados
	for (int i = 0; i < vertCount; i++) 
		lstVertices[i]->visitado = false;

	printf("\nPesquisa com Depth First Recursiva:\n");
	bool existe = DepthFirstSearchRec(adjMatrix, lstVertices, vertCount, 0,4);
	printf(" Existe Path entre %d e %d: %s\n", 0,4,(existe == true ? "Sim" : "Não"));

	printf("\nTravessia Breadth First:\n");
	BFT(adjMatrix, lstVertices, 0);

	Best b = BestPath(adjMatrix, MAX, 0);
	
	ShowAllPath(b, MAX, 0);

	system("pause");
	return 0;
} 

/*
Exercício: Gestão de Caminhos

struct vertex{
int ID;
string name;
int district;
bool visited;
int distance;
vector<adjVertex> adj;
};

*/
