/*****************************************************************//**
 * @file   Header.h
 * @brief  
 * 
 * @author lufer
 * @date   November 2022
 *********************************************************************/
#pragma once
#include <stdbool.h>

#define N 20

#pragma warning (disable: 4996)

/*
Estrutura que descreve uma pessoa
*/
typedef struct Pessoa {
	char nome[N];
	int idade;
}Pessoa;

int InserePessoa(Pessoa p[], int s, Pessoa nova);
void MostraTurma(Pessoa p[], int s);
bool GravaTurma(Pessoa p[], int s, char nome[]);
bool MostraFicheiro(char nomeFile[]);

Pessoa MaisVelhoTurma(Pessoa p[], int s);
int OndeEstaMaisVelhoTurma(Pessoa p[], int s);

typedef struct Coisa {
	Pessoa p;
	int pos;
}Coisa;

Coisa PessoaPosicao(Pessoa p[], int s);


