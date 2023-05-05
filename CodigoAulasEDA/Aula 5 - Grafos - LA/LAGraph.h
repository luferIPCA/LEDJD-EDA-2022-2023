/*
//Grafos: Lista de Adjacências
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
//lufer
*/
#pragma once

#ifndef GRF
#define GRF

//=========================================================
//H1 : grafo orientado, não pesado, com Matriz Fixa
//=========================================================
#define TOTALVERTICES 8

//Vertice
typedef struct item {
	int valor;			//número de adjacentes ou valor do vertice
	struct item* prox;	//lista de adjacentes
}ITEM;



bool CriaGraph(ITEM *gr, int tot);
void MostraGrafo(ITEM *lista);
bool InsereAresta(ITEM *lista, int a, int b);



//=========================================================
//H2 - Grafo orientado e pesado - Matriz calculada
//=========================================================

// nodo da Lista de Adjacências
struct AdjListNode
{
	int valor;			//1 ou 0
	float peso;			//grafo pesado
	struct AdjListNode* next;
};

// Lista de Adjacências
struct AdjList
{
	struct AdjListNode *head;  // head da Lista
};

// Um Grafo. Um array de Lista de Adjacências!!!
// Array = numero de vértices do Grafo
struct Graph
{
	int v;				//total de vertices
	struct AdjList* array;	//"lista" de adjacencias
};

//prototipos funções

struct Graph* createGraph(int nVertices);
//Insere em grafo não orientado e pesado
bool addEdgeWeight(struct Graph* graph, int src, int dest, float p);
//insere em grafo não orientado e não pesado
bool addEdge(struct Graph* graph, int src, int dest);
//Menor Distância
float ShorterDistance(struct Graph* graph, int v);

//=========================================================
//H3
//Só estruturas dinâmicas
////=========================================================

typedef struct adjacent *Adjacent;
typedef struct node *Node;

struct adjacent {
	Node Ptdestiny;
	Adjacent PtNext;
};

struct node
{
	int *PtIdentifier;
	char *PtCity;
	Adjacent PtAdjacent;
	Node PtNext;
};

#endif // !GRF

