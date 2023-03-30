/*
Grafos: Fundamentos
lufer
Consultar:
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET
#include "LAGraph.h"
 

//Grafo
ITEM lista[TOTALVERTICES + 1];

int main() {
	setlocale(LC_ALL, "Portuguese");

#pragma region LISTA_ADJACENCIAS
	  //==========================
	  // Lista de Adjacencias
	  //==========================

	  //======================================
	  //H1 - Estrutura de Vértices Fixa
	  //======================================
	  int i, a, b;

	  // Inicialização da lista de vertices
	  // Vertices: 0, 1, 2, 3...
	  //for (i = 0; i < TOTALVERTICES; i++) {
		 // lista[i].valor = 0;
		 // lista[i].prox = NULL;
	  //}

	  bool aux = CriaGraph(lista, TOTALVERTICES);

	  MostraGrafo(lista);

	  InsereAresta(lista, 7, 1);
	  InsereAresta(lista, 0, 1);
	  InsereAresta(lista, 0, 2);
	  InsereAresta(lista, 2, 3);
	  InsereAresta(lista, 3, 1);

	  printf("\nGrafo Orientado\n");
	  MostraGrafo(lista);

	  //======================================
	  //H2 - Grafo não orientado e pesado
	  //======================================
	  
	  int v = 5;
	  struct Graph* g = createGraph(v);
	  addEdge(g, 0, 1);	//sem peso
	  addEdge(g, 0, 4);
	  addEdge(g, 1, 2);
	  addEdge(g, 1, 3);
	  addEdge(g, 1, 4);
	  addEdgeWeight(g, 2, 3,4.2);
	  addEdgeWeight(g, 3, 4, (float)7);

	  //Mostra Grafo
	  printf("\nGrafo Não Orientado\n");
	  printGraph(g);
	  printf("\nGrafo Não Orientado\n");
	  // mostra a lista de adjacências
	  printGraphWeight(g, true);

	  //Menor Distância saindo de um Vertice v

	  printf("\nMenor Distância saindo de (%d) = %2.0f\n", 2, ShorterDistance(g, 2));


	  //======================================
	  //H3
	  //======================================
	  Node gr = NULL;

	  CreateGraphTable(&gr, 0, "Lisboa");
	  CreateGraphTable(&gr, 1, "Porto");
	  CreateGraphTable(&gr, 2, "Braga");
	  CreateGraphTable(&gr, 3, "Barcelos");
	  CreateGraphTable(&gr, 4, "Coimbra");

	  CreateAdjacent(&gr, 0, 1);
	  CreateAdjacent(&gr, 0, 4);

	  CreateAdjacent(&gr, 1, 0);
	  CreateAdjacent(&gr, 1, 2);
	  CreateAdjacent(&gr, 1, 3);
	  CreateAdjacent(&gr, 1, 4);

	  CreateAdjacent(&gr, 2, 1);
	  CreateAdjacent(&gr, 2, 3);

	  CreateAdjacent(&gr, 3, 1);
	  CreateAdjacent(&gr, 3, 2);
	  CreateAdjacent(&gr, 3, 4);

	  CreateAdjacent(&gr, 4, 0);
	  CreateAdjacent(&gr, 4, 1);
	  CreateAdjacent(&gr, 4, 3);

	  ListGraph(gr);

#pragma endregion

	  system("pause");
	  return 0;
} 
