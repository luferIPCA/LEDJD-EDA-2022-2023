/*****************************************************************//**
 * @file   Grafos.h
 * @brief  Grafos com matrizes de adjacências
 * 
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/
#pragma once

#include <stdbool.h>
#define MAX 10
#define N 20

typedef struct Vertice {
	int valor;
	char nome[N];
}Vertice;


bool CriaGrafo(int numVertices, float mat[][MAX]);
bool InsereVertice(Vertice v[], int *numVert, char* cidade);
bool InsereAresta(float mat[][MAX], int numVertices, Vertice v[], int totV, char* origem, char* destino, float p);
