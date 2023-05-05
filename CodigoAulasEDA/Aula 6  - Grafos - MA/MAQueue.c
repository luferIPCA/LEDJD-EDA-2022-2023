/*
Grafos: Travessia em Largura com Matriz de Adjacências

 Procura em Profundidade: Stack
 Procura em Largura:		Queue
lufer
http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
http://www.geeksforgeeks.org/applications-of-breadth-first-traversal/
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
*/


#include <stdio.h>
#include "Graphs.h"
#include "BFT.h"

#pragma region Queue

//Queue
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

// Queue functions 
void insertQueue(int data) { 
   queue[++rear] = data; 
   queueItemCount++; 
} 
 
int nextQueue() { 
   queueItemCount--; 
   return queue[front++];  
} 
 
bool isQueueEmpty() { 
   return queueItemCount == 0; 
} 
 
#pragma endregion

//======================================================
// Breadth First Algorithm
//======================================================

/*
Travessia BSF
*/
void BFT(int adjMatrix[][MAX],Vertice *lstVertices[], int v) {
   int i; 
   int uv; // unvisited Vertice

   //marca vertice como visitado 
   lstVertices[v]->visitado = true; 
   //processa vertice: mostra e calcula distância
   ProcessaVertice(lstVertices,v);
   //insere vertice na queue
   insertQueue(v); 
  
   while(!isQueueEmpty()) { 
	   //encontra vertice não visitado que está à frente da queue
      int tempVertex = nextQueue();    
 
      //para cada adjacente não visitado
      while((uv = GetVertAdjunNaoVisitado(adjMatrix, lstVertices,tempVertex)) != -1)
	  {
		//marca
         lstVertices[uv]->visitado = true; 
		 //processa
         ProcessaVertice(lstVertices,uv);
		 //insere na queue
         insertQueue(uv);                
      } 
   
   }    
 
   //no fim a queue está vazia, repõe o estado de cada vertice         
   for(i = 0;i<vertCount;i++) { 
      lstVertices[i]->visitado = false; 
   }     
} 

/**
 * @brief Dijkstra’s Algorithm.
 * 
 * @param adjMatrix
 * @param n
 * @param v
 * @return 
 * @author lufer
 *
 */
Best BestPath(int adjMatrix[MAX][MAX],int n, int v) {

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	//pred[] guarda o vertice anterior ao atual
	//count número de nodos visitados até ao momento
	//cria matriz de custos a partir da matriz de adjacencias
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (adjMatrix[i][j] == 0)
				cost[i][j] = MAXDISTANCE;
			else
				cost[i][j] = adjMatrix[i][j];

	//initializa pred[],distance[] and visited[]
	for (i = 0; i<n; i++)
	{
		distance[i] = cost[v][i];
		pred[i] = v;
		visited[i] = 0;
	}

	distance[v] = 0;
	visited[v] = 1;
	count = 1;
	while (count<n - 1)
	{
		mindistance = MAXDISTANCE;
		//nextnode é o vertice à menor distância do atual
		for (i = 0; i < n; i++) 
		{
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		}

		//Verifica se existe um melhor caminho
		visited[nextnode] = 1;
		for (i = 0; i < n; i++) {
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		}
		count++;
	}
	//Devolve resultados
	Best b;
	for (int i = 0; i < n; i++) {
		b.anteriores[i] = pred[i];
		b.distance[i] = distance[i];
	}
	return b;
}

/*
Auxiliar
*/
void ShowAllPath(Best b, int n, int v) {
	int j;
	for (int i = 0; i<n; i++)
		if (i != v)
		{
			printf("\nDistancia até ao vertice %d = %d", i, b.distance[i]);
			printf("\nPath = %d", i);

			j = i;
			do
			{
				j = b.anteriores[j];
				printf(" <- %d", j);
			} while (j != v);
		}
}

 