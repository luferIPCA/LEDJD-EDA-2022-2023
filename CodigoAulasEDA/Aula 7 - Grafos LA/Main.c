/*****************************************************************//**
 * @file	Main.c
 * @brief	Grafos - Algoritmos de manipulação
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#include "Grafo.h"
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese");	//para escrever caracteres portugueses

	static int tot = 0;					//total de vertices
	bool res;

#pragma region GRAFOS

	Vertice *graf = CriaGrafo();

	Vertice* novoVertice = CriaVertice("Braga",tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Porto",tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Famalicão",tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Lisboa", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Faro", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	MostraGrafo(graf);		//recursivo

	//Adjacencias
	//Criar ligação "Braga" a "Porto"
	graf = InsereAdjacenteVertice(graf, "Braga", "Porto", 35, &res);
	graf = InsereAdjacenteVertice(graf, "Braga", "Famalicão", 15, &res);
	graf = InsereAdjacenteVertice(graf, "Famalicão", "Porto", 22, &res);
	graf = InsereAdjacenteVertice(graf, "Porto", "Lisboa", 250, &res);

	MostraGrafo(graf);		//recursivo
	
	int pathCount = 0;
	int x = CountPaths(graf, 0, 2, pathCount);

	int contaPath = 0;
	x = CountPathsVerticesName(graf, "Braga", "Porto", contaPath);
	x = CountPathsVerticesName(graf, "Braga", "Famalicão", contaPath);

	x = CountPaths(graf, 0, 1, 0);

	printf("\nExiste Path?\n");
	bool existe = DepthFirstSearchRec(graf, 0, 3);
	printf(" Existe Path entre %d e %d: %s\n", 0,3,(existe == true ? "Sim" : "Não"));


	graf = ResetVerticesVisitados(graf);

	existe = DepthFirstSearchNamesRec(graf, "Braga", "Porto");
	printf(" Existe Path entre %s e %s: %s\n", "Braga", "Porto",(existe == true ? "Sim" : "Não"));

#pragma endregion

}
