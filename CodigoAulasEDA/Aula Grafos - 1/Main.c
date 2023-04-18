/*****************************************************************//**
 * @file   Main.c
 * @brief  Gere Grafos
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/
#include "Grafo.h"

int main() {

	//Vertices
	Vertice vertices[MAXVERTICES];

	//Vertice *vertices1[MAXVERTICES];

	//Matriz de Adjacencias
	float ma[MAXVERTICES][MAXVERTICES];

	//Total de vertices
	int totalVertices = 0;

	bool aux = CriaGrafo(vertices, 5);

	Vertice novo;
	strcpy(novo.cidade, "Barcelos");
	novo.id = totalVertices;

	aux = AddVertGraph(vertices, novo, &totalVertices);

	strcpy(novo.cidade, "Porto");
	novo.id = totalVertices;
	aux = AddVertGraph(vertices, novo, &totalVertices);

	strcpy(novo.cidade, "Braga");
	novo.id = totalVertices;
	aux = AddVertGraph(vertices, novo, &totalVertices);


	aux = AddArestVertices(vertices, totalVertices, ma, "Braga", "Porto", 45);
	aux = AddArestVertices(vertices, totalVertices, ma, "Porto", "Barcelos", 50);
}
