/*****************************************************************//**
 * @file   Grafos.c
 * @brief  Implementar Grafo...com matrizes de adjacências
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/
#include "Grafos.h"


/**
 * @brief Cria....
 * 
 * @param numVertices
 * @param mat
 * @return 
 * @author lufer
 *
 */
bool CriaGrafo(int numVertices, float mat[][MAX]) {
	if (numVertices > MAX || numVertices < 0) return false;
	for(int i=0; i<numVertices;i++)
		for (int j = 0; j < numVertices; j++)
		{
			mat[i][j] = -1;
		}
	return true;
}

/**
 * @brief .
 * 
 * @param v
 * @param numVert
 * @param cidade
 * @return 
 * @author lufer
 *
 */
bool InsereVertice(Vertice v[], int *numVert, char* cidade){
	if (*numVert > MAX) 
		return false;
	v[*numVert].valor = *numVert;
	strcpy(v[*numVert].nome, cidade);
	(*numVert)++;
	return true;
}

/**
 * @brief .
 * 
 * @param ma
 * @param totVertices
 * @param v
 * @param numVertices
 * @param origem
 * @param destino
 * @param p
 * @return 
 * @author lufer
 *
 */
bool InsereAresta(float ma[][MAX], int totVertices, Vertice v[], int numVertices, char *origem, char *destino, float p) {

	int vOrigem = -1;
	int vDestino = -1;

	//procurar o vertice origem
	for (int i = 0; i < numVertices; i++) {
		if (strcmp(v[i].nome, origem) == 0) {
			vOrigem = i;
			continue;
		}

		if (strcmp(v[i].nome, destino) == 0) {
			vDestino = i;
			continue;
		}
	}
	if (vOrigem == -1 || vDestino == -1) return false;

	//Registar pesos
	ma[vOrigem][vDestino] = p;
	ma[vDestino][vOrigem] = p;
	return true;
}
