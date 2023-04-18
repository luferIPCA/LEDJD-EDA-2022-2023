/*****************************************************************//**
 * @file   Main.c
 * @brief  Gere Grafos
 * 
 * @author lufer
 * @date   April 2023
 * Grafo = set(V) + set(A)
 *********************************************************************/

#include "Grafos.h"

#define VERT 5

int main() {

	//Set de vertices
	Vertice vertices[MAX];

	//Matris de Adj
	float ma[MAX][MAX];

	bool aux = CriaGrafo(VERT, ma);

	//numero corrente de vertices
	int totVertices = 0;

	aux = InsereVertice(vertices, &totVertices, "Braga");
	aux = InsereVertice(vertices, &totVertices, "Porto");
	aux = InsereVertice(vertices, &totVertices, "Paris");
	aux = InsereVertice(vertices, &totVertices, "Famalicão");

	//Criar o grafo
	aux = InsereAresta(ma, VERT, vertices, totVertices, "Braga", "Porto", 40);
	aux = InsereAresta(ma, 5, vertices, totVertices, "Famalicão", "Porto", 30);
	aux = InsereAresta(ma, 5, vertices, totVertices, "Famalicão", "Braga", 20);

}
