/*****************************************************************//**
 * @file   Grafo.h
 * @brief  Descrição de Grafo...
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/
#pragma once

#include <stdbool.h>

#define N 20

typedef struct Vertice {
	char cidade[N];
	int id;
}Vertice;

#define MAXVERTICES 10

bool CriaGrafo(Vertice g[], int numeroVertices);

bool AddVertGraph(Vertice g[],Vertice novo, int *posicao);

bool AddArestVertices(Vertice v[], int numVertices, float ma[][MAXVERTICES], char origem[], char destino[], float peso);
