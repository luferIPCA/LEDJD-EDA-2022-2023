/*****************************************************************//**
 * @file   Main.c
 * @brief	Recursividade (consolidação)
 *			Grafos
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#include "Dados.h"
#include "Grafo.h"
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese");	//para escrever caracteres portugueses

	static int tot = 0;

#pragma region RECURSIVIDADE

	Veiculo* novo;
	//analisar valores insridos pela linha de comando
	if (argc > 1) {
		 novo = NovoVei(atoi(argv[1]));
	}
	else {
		novo = NovoVei(2);
	}

	//gere lista de veiculos
	Veiculo* head = NULL;

	bool res;
	head = InsereVei(head, novo, &res);

	novo = NovoVei(3);
	head = InsereVei(head, novo, &res);

	novo = NovoVei(1);
	head = InsereVei(head, novo, &res);
	
	MostraLista(head);			//não recursiva

	MostraListaRecursiva(head);	//recursiva

#pragma endregion

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

	MostraGrafo(graf);		//recursivo

	//Adjacencias
	//Criar ligação "Braga" a "Porto"
	graf = InsereAdjacenteVertice(graf, "Braga", "Porto", 35, &res);
	graf = InsereAdjacenteVertice(graf, "Braga", "Famalicão", 15, &res);
	//graf = InsereAdjacenteVertice(graf, tot, "Braga", "Porto", 35, &res);

	MostraGrafo(graf);		//recursivo
	

#pragma endregion

}
