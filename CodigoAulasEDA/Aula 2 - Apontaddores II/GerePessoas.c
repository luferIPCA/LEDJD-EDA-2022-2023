/*****************************************************************//**
 * @file   GerePessoas.c
 * @brief  Gere Arrays de Apontadores
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/

#include "Header.h"
#include <stdlib.h>		//malloc


int main() {

#pragma region Pointers
	Pessoa p;
	p.idade = 12;
	strcpy(p.nome, "Ola");

	Pessoa *k;
	k = &p;
	k->idade++;
	//ou
	printf("Size: %d\n", sizeof(Pessoa));
	k = (Pessoa*)malloc(sizeof(Pessoa));
	k->idade = p.idade + 2;
	free(k);
#pragma endregion

#pragma region ArraysPointers

	Pessoa pessoas[N];

	pessoas[0].idade = 12;

	Pessoa* turma[N];
	//turma[0] = (Pessoa*)malloc(sizeof(Pessoa));
	//turma[0]->idade = 12;

	bool aux = InicializaArray(turma, N);
	int total = 0;

	Pessoa nova;
	nova.idade = 34;
	strcpy(nova.nome, "ok");
	aux = InserePessoa(turma, &total, nova);

	total = InserePessoaII(turma, total, nova);

#pragma endregion

}
