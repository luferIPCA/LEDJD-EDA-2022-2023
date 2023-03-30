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

	AddEdgeWeight(0, 1, 8);    // S - A 
	AddEdgeWeight(0, 2, 12);    // S - B 
	AddEdgeWeight(0, 3, 9);    // S - C 
	AddEdgeWeight(1, 4, 3);    // A - D 
	AddEdgeWeight(2, 4, 7);    // B - D 
	AddEdgeWeight(3, 4, 1);    // C - D 
	AddEdgeWeight(3, 5, 2);    // C - E 
   
	//Mostra um determinado vertice
	ProcessaVertice(lstVertices,3);

	printf("\nTravessia Depth First:\n");    
	depthFirstSearch(lstVertices);

	printf("\nTravessia Breadth First:\n");
	breadthFirstSearch(lstVertices, 0);  

	Best b = bestPath(adjMatrix, MAX, 0);
	
	ShowAllPath(b, MAX, 0);

	printf("\n");
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
