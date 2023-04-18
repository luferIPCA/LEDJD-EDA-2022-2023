/*****************************************************************//**
 * @file   Grafo.c
 * @brief  Implementação de Grafo não orientado, pesado
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#include "Grafo.h"
/**
 * @brief .
 * 
 * @param g
 * @param numVert
 * @return 
 * @author lufer
 *
 */
bool CriaGrafo(Vertice g[], int numVert) {
	if (numVert > MAXVERTICES) return false;
	for (int i = 0; i <= numVert; i++) {
		g[i].id = i;
		strcpy(g[i].cidade,"");
	}
	return true;
}

bool AddVertGraph(Vertice g[], Vertice novo, int *posicao) {
	if ((*posicao > MAXVERTICES) || *posicao < 0) return false;
	strcpy(g[*posicao].cidade,novo.cidade);
	g[*posicao].id=novo.id;
	(*posicao)++;
	return true;
}

bool AddArestVertices(Vertice v[], int numVertices, float ma[][MAXVERTICES], char origem[], char destino[], float peso) {
	
	int verticeOrigem=-1;
	int verticeDestino=-1;
	//procurar vertices correspondentes à origem e destino
	for (int i = 0; i < numVertices; i++) {

		if (strcmp(v[i].cidade, origem) == 0) {
			verticeOrigem = i;
			continue;
		}
		if (strcmp(v[i].cidade, destino) == 0) {
			verticeDestino = i;
			continue;
		}
	}

	//Se vertices não existem
	if (verticeDestino < 0 || verticeOrigem < 0) return false;
	ma[verticeOrigem][verticeDestino] = peso;
	ma[verticeDestino][verticeOrigem] = peso;
	return true;
}
