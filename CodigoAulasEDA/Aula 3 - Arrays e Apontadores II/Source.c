/*****************************************************************//**
 * @file   Source.c
 * @brief  Apontadores: Revisão
 *		Array de Apontadores
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/

#include "Header.h"
#include <stdio.h>
#include <stdlib.h>	//malloc

int main() {

#pragma region POINTERS

	Aluno a = { 12,"ola" };

	Aluno* p;
	p = &a;
	printf("Nome: %s\n", p->nome);

#pragma endregion

#pragma region ARRAYS

	Aluno turma[N];
	strcpy(turma[0].nome, "ola");
	turma[0].num = 2;
	printf("Nome: %s\n", turma[0].nome);

#pragma endregion

#pragma region ARRAYS_POINTERS

	Aluno* turmaDJ[N];
	turmaDJ[0] = &a;
	turmaDJ[0]->num++;

#pragma endregion

#pragma region ARRAYS_POINTERS_MALLOC

	turmaDJ[1] = (Aluno*)malloc(sizeof(Aluno));
	turmaDJ[1]->num=27;
	strcpy(turmaDJ[1]->nome, "ok");

#pragma endregion
	//inicialização de array apontadores
	turmaDJ[2] = NULL;

	//libertar memória alocada
	free(turmaDJ[1]);
}
