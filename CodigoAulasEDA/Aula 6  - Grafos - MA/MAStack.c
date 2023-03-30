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
//======================================================

/*
DFS
Percorre o grafo em profundidade
*/
void depthFirstSearch(Vertice *lstVertices[]) {
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
	  uv = GetVertAdjunNaoVisitado(lstVertices,peek());
      //se não tem adjacentes 
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
 
   //stack está vazia, repõe o estado de cada vertice         
   for(i = 0;i < vertCount;i++) { 
      lstVertices[i]->visitado = false; 
   }         
}

//==================================================
/* Exercício
Grafo Pesado com distâncias entre vértices (cidades)

Devolver a cidade que se encontra mais perto....e não foi visitada!!
*/
//==================================================