/*
//Grafos: Lista de Adjacências
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
//lufer
*/
#include <stdio.h>
#include <stdbool.h>
#include "LAGraph.h"
#include "assert.h"
// Lidar com "exceções"
// assert(x>=10) - stderror output caso x<10

//Ver: http://www.geeksforgeeks.org/graph-and-its-representations/
//Exercicio: 
//Analisar http://www.thecrazyprogrammer.com/2014/03/depth-first-search-dfs-traversal-of-a-graph.html

//=========================================================
//H1 - Grafo orientado, não pesado, matriz fixa (TOTALVERTICES)
//=========================================================


/*
Cria Grafo
Vertices: 0, 1, 2, 3...
Inicializa vertices com lista de adjacencias=NULL
*/
bool CriaGraph(ITEM *gr, int tot) {
	//se número de vertices não for válido
	if (tot <= 0 || tot > TOTALVERTICES) return false;
	//incializa
	for (int i = 0; i < tot; i++) {
		gr[i].valor = 0;
		gr[i].prox = NULL;
	}
	return true;
}
/*
Mostra Grafo
*/
void MostraGrafo(ITEM *lista) {
	int i;
	ITEM * tmp;
	for (i = 0; i < TOTALVERTICES; i++) {
		tmp = lista[i].prox;
		printf("Vertice %d: (%d) ==>", i, lista[i].valor);
		while (tmp != NULL) {
			printf("%d  ", tmp->valor);
			tmp = tmp->prox;
		}
		printf("\n");
	}
}

/*
Nova aresta, ordenando adjacências, grafo orientado
Vertice origem:a
Vertice destino:b
*/
void InsereAresta(ITEM *lista, int a, int b) {
	ITEM *destino;
	ITEM *tmp;

	//Novo vertice para o destino
	destino = (ITEM*)malloc((int)sizeof(ITEM));
	//assert(destion)
	destino->valor = b;
	destino->prox = NULL;

	lista[a].valor++;			// conta adjacentes!

	//Regista vertice destino como adjacente
	if (lista[a].prox == NULL)	// se lista vazia - é único adjacente	
		lista[a].prox = destino;
	else {						//insere vértices ordenados
		tmp = lista[a].prox;
		//insere inicio da lista
		if (tmp->valor > b) {	//insere inicio da lista
			destino->prox = tmp;
			lista[a].prox = destino;
		} 		          
		else if (tmp->prox == NULL) {
			destino->prox = tmp->prox;
			tmp->prox = destino;
		}
		else {
			while ((tmp->prox != NULL) && (tmp->prox->valor < b))
				tmp = tmp->prox;
			destino->prox = tmp->prox;
			tmp->prox = destino;
		}
	}
}

//=========================================================
//H2 - Grafo Não Orientado, pesado, Matriz calculada
//=========================================================

/*
Novo Nodo
*/
struct AdjListNode* newAdjListNode(int val)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	assert(newNode);		//lida com invariante ex: assert(x>10) - stderror output
	newNode->valor = val;
	newNode->next = NULL;
	newNode->peso = 0;		//grafo ponderado; (peso=0) por omissão!
	return newNode;
}

/*
Cria grafo preparado para conter "nVertices" 
*/
struct Graph* createGraph(int nVertices)
{
	//estrutura para guardar todo o grafo
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	assert(graph);
	graph->v = nVertices;

	//Cria array de lista de adjacencias de tamanho nVertices
	graph->array = (struct AdjList*) malloc(nVertices * sizeof(struct AdjList));

	// Inicializa cada lista de adjacencias
	int i;
	for (i = 0; i < nVertices; ++i)
		graph->array[i].head = NULL;

	return graph;
}

/*
Adiciona aresta em grafo não orientado e não pesado
*/
void addEdge(struct Graph* graph, int src, int dest)
{
	//novo nodo para vertice destino
	struct AdjListNode* newNode = newAdjListNode(dest);
	//Insere à cabeça da lista de adjacências
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// grafo não orientado => addEdgs (graph, dest,src) 
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}


/*
Insere aresta ponderada, ie, com um peso, em grafo não orientado
*/
void addEdgeWeight(struct Graph* graph, int src, int dest, float p)
{
	//novo nodo para vertice destino
	struct AdjListNode* vdest = newAdjListNode(dest);	
	vdest->peso = p;		//ponderação

	//Insere à cabeça da lista de adjacências
	vdest->next = graph->array[src].head;
	graph->array[src].head = vdest;

	// grafo não orientado => addEdgs (graph, dest,src) 
	struct AdjListNode* vsource = newAdjListNode(src);
	vsource->peso = p;		//ponderação
	vsource->next = graph->array[dest].head;
	graph->array[dest].head = vsource;
}

//Outra Abordagem
/*
void addEdgeII(struct Graph* graph, int src, int dest, float p)
{
//novo nodo para vertice destino
struct AdjListNode* newNode = newAdjListNode(dest);
//Insere à cabeça da lista de adjacências
newNode->next = graph->array[src].head;
newNode->peso = p;
graph->array[src].head = newNode;

addEdgeII(graph, dest, src, p);

}

void addEdgeWeightII(struct Graph* graph, int src, int dest, float p)
{
addEdgeII(graph, src, dest, p);
addEdgeII(graph, dest, src, p);
}
*/

/*
Mostra Grafo
*/
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->v; ++v)
	{
		struct AdjListNode* aux = graph->array[v].head;
		printf("\n Lista de Adjacencia do Vertice (%d)", v);
		while (aux)
		{
			printf("-> %d", aux->valor);
			aux = aux->next;
		}
		printf("\n");
	}
}

/*
Mostra grafo pesado ou não
*/
void printGraphWeight(struct Graph* graph, bool pesado)
{
	int v;
	for (v = 0; v < graph->v; ++v)
	{
		struct AdjListNode* aux = graph->array[v].head;
		printf("\n Lista de Adjacencia do Vertice (%d)", v);
		while (aux)
		{
			if(pesado==false)
				printf("-> %d", aux->valor);
			else
				printf("-> (%d): Peso= %2.0f", aux->valor, aux->peso);
			
			aux = aux->next;
		}
		printf("\n");
	}
}

/*
Menor distância saindo de um determinado verticce
*/
float ShorterDistance(struct Graph* graph, int v) {
	float menor = 0;
	//assert (v existe e é válido)
	struct AdjListNode* aux = graph->array[v].head;
	while (aux)
	{
		if ((aux->peso > menor) && (aux->peso != 0))
			menor = aux->peso;
		aux = aux->next;
	}
	return menor;
}

//=========================================================
//H3 - Estruturas Dinâmicas
//=========================================================

Adjacent AdjacentCreate(Node destiny)
{
	Adjacent adjacent;

	adjacent = (Adjacent)malloc(sizeof(struct adjacent));
	if (adjacent == NULL)
	{
		return NULL;
	}

	adjacent->Ptdestiny = destiny;
	adjacent->PtNext = NULL;

	return adjacent;
}

void AdjacentDestroy(Adjacent *ptAdjacent)
{
	free(*ptAdjacent);
	*ptAdjacent = NULL;
}

Node NodeCreate(int identifier, char name[])
{
	Node node;

	node = (Node)malloc(sizeof(struct node));
	if (node == NULL)
	{
		return NULL;
	}

	if ((node->PtIdentifier = (int *)malloc(sizeof(int))) == NULL)
	{
		free(node);
		return NULL;
	}

	if ((node->PtCity = (char *)malloc(strlen(name) + 1)) == NULL) {
		free(node->PtIdentifier);
		free(node);
		return NULL;
	}

	*node->PtIdentifier = identifier;
	strcpy(node->PtCity, name);
	node->PtAdjacent = NULL;
	node->PtNext = NULL;
	return node;
}

void NodeDestroy(Node *ptNode) {
	free((*ptNode)->PtIdentifier);
	free((*ptNode)->PtCity);
	free(*ptNode);
	*ptNode = NULL;
}

void CreateGraphTable(Node *graph, int position, char cityName[])
{
	Node Previous = NULL;
	Node Inserted = NULL;
	Node Current = *graph;

	if ((Inserted = NodeCreate(position, cityName)) == NULL)
	{
		return;
	}

	while (Current != NULL)
	{
		Previous = Current;
		Current = Current->PtNext;
	}

	if (Previous == NULL)
	{
		Inserted->PtNext = *graph;
		*graph = Inserted;
	}
	else
	{
		Previous->PtNext = Inserted;
	}
}

void ListGraph(Node graph) {
	Node Current = graph;
	while (Current != NULL) {
		printf("%d-", *Current->PtIdentifier);
		printf("%s\n", Current->PtCity);
		Adjacent CurrentAdjacent = Current->PtAdjacent;
		while (CurrentAdjacent != NULL)
		{
			printf("\t");
			printf("adjacent-%d\n", *CurrentAdjacent->Ptdestiny->PtIdentifier);
			CurrentAdjacent = CurrentAdjacent->PtNext;
		}
		Current = Current->PtNext;
	}
}

void CreateAdjacent(Node *graph, int origin, int destiny)
{
	Node originNode = NULL;
	Node destinyNode = NULL;
	Node current = *graph;

	while (current != NULL)
	{
		if (*current->PtIdentifier == origin)
		{
			originNode = current;
			current = current->PtNext;
			continue;
		}
		if (*current->PtIdentifier == destiny)
		{
			destinyNode = current;
		}

		current = current->PtNext;
	}

	if (originNode == NULL && destinyNode == NULL)
	{
		return;
	}

	Adjacent previous = NULL;
	Adjacent inserted = NULL;
	Adjacent currentAdjacent = originNode->PtAdjacent;
	if ((inserted = AdjacentCreate(destinyNode)) == NULL)
	{
		return;
	}

	while (currentAdjacent != NULL)
	{
		previous = currentAdjacent;
		currentAdjacent = currentAdjacent->PtNext;
	}

	if (previous == NULL)
	{
		inserted->PtNext = originNode->PtAdjacent;
		originNode->PtAdjacent = inserted;
	}
	else
	{
		previous->PtNext = inserted;
	}
}