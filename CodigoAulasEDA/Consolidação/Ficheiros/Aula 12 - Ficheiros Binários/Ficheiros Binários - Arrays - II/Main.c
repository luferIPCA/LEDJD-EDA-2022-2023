/*****************************************************************//**
 * @file   Main.c
 * @brief  Programa que grava um array de pessoas
 * 
 * @author lufer
 * @date   November 2022
 *********************************************************************/

#include "Header.h"

int main() {

	Pessoa turma[N] = { {"Ana",20},{"Pedro",23},{"Joaquim",20} };
	int sizeTurma = 3;

	Pessoa p1;
	strcpy(p1.nome, "Ana");
	p1.idade = 20;

	sizeTurma = InserePessoa(turma, sizeTurma, p1);
	MostraTurma(turma, sizeTurma);
	bool r = GravaTurma(turma, sizeTurma, "c:\\temp\\turma.dat");
	printf("\nMOSTRA FICHEIRO\n");
	MostraFicheiro("c:\\temp\\turma.dat");
	
}
