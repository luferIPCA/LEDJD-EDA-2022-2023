/*
Grafos: Travessia em Profundidade com Matriz de Adjacências

Procura em Profundidade: Stack
Procura em Largura:		Queue
lufer
Analisar
--------
Descrição: http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
Aplicação: http://www.geeksforgeeks.org/applications-of-depth-first-search/
*/
#include<stdio.h>
#include <stdbool.h>
#include "Graphs.h"
#include "DFT.h"


//inicia variáveis
top = -1;
//vertexCount = 0;

#pragma region STACK
//======================================================
//Stack Functions
//======================================================
void push(int item) {  
   stack[++top] = item;  
}  
 
int pop() {  
   return stack[top--];  
}  
 
int peek() { 
   return stack[top]; 
} 
 
bool isStackEmpty() { 
   return top == -1; 
} 

#pragma endregion

//======================================================
//Depth First Algorithm
//  DFT: Depth First Traversal
//  DFS: Depth First Search
//======================================================

/*
DFT
Percorre todo o grafo em profundidade
*/
void DFT(int adjMatrix[][MAX],Vertice *lstVertices[], int totVertices) {
   int i; 
   int uv; //unvisitedVertice

   //marca vertice como visitado 
   lstVertices[0]->visitado = true; 
   //processa vertice
   ProcessaVertice(lstVertices,0);
   //insere 1º vertice na stack
   push(0); 
   while(!isStackEmpty()) { 	  
	  //encontra vertice não visitado adjacente ao que está no topo da stack      
	  uv = GetVertAdjunNaoVisitado(adjMatrix,lstVertices,peek());
      //se não tem adjacentes, retira da stack 
      if(uv == -1) { 
         pop(); 
      }else { 
		 //marca
         lstVertices[uv]->visitado = true; 
		 //processa
         ProcessaVertice(lstVertices,uv);
		 //insere na stack
         push(uv); 
      } 
   } 
 
   //no fim a stack está vazia, repõe o estado de cada vertice         
   for(i = 0;i < totVertices;i++) {
      lstVertices[i]->visitado = false; 
   }         
}

/**
 * DFT: Percorre todo o grafo a partir de um determinado vertice
 */
void DFTRecursivo(int adjMatrix[][MAX], Vertice* lstVertices[], int totVertices, int origem) {
    int j;

    lstVertices[origem]->visitado = 1;
    printf(" Vertice: %c : %d\n", lstVertices[origem]->nome, lstVertices[origem]->visitado);

    for (j = 0; j < totVertices; j++)
    {
        if (adjMatrix[origem][j] > 0 && lstVertices[j]->visitado == 0)
            DFTRecursivo(adjMatrix, lstVertices, totVertices, j);
    }
}

/**
 * @brief Depth First Search.
 * 
 * @param adjMatrix
 * @param lstVertices
 * @param totVertices
 * @param origem
 * @param dest
 * @return 
 * @author lufer
 *
 */
bool DepthFirstSearchRec(int adjMatrix[][MAX],  Vertice* lstVertices[], int totVertices,  int origem, int dest)
{
    int j;
    bool existe = false;

    lstVertices[origem]->visitado=1;
    printf("\tVertice: %c : %d\n", lstVertices[origem]->nome, origem);

    if (origem == dest) return true;

    for (j = 0; j < totVertices; j++)
    {
        if (adjMatrix[origem][j] >0 && lstVertices[j]->visitado == 0)
            return DepthFirstSearchRec(adjMatrix, lstVertices, totVertices, j, dest);
    }
    //return existe;
}
//==================================================
/* Exercício
Grafo Pesado com distâncias entre vértices (cidades)

Devolver a cidade que se encontra mais perto....e não foi visitada!!
*/
//==================================================