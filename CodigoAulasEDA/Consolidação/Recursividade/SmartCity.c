/*****************************************************************//**
 * @file   SmartCity.c
 * @brief  Recursividade: Consolidação
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/

#include "Dados.h"
#include <conio.h>
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese");

	char nomeCidade[N];

	Cidade* smartCity = NULL;

	if (argc > 0) {
		strcpy(nomeCidade, argv[1]);	//argv[0] tem o nome do programa
	}

	Cidade* nova = CriaCidade(nomeCidade);

	bool aux = RegistaCidade(&smartCity, nova);

	MostraCidades(smartCity);

	nova = CriaCidade("Braga");
	smartCity = RegistaCidadeRecursiva(smartCity, nova, &aux);
	aux = false;

	nova = CriaCidade("Famalicão");
	smartCity = RegistaCidadeRecursiva(smartCity, nova, &aux);

	MostraCidades(smartCity);

	return (0);
}