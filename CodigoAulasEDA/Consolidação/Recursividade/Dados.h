/*****************************************************************//**
 * @file   Dados.h
 * @brief  Recursividade
 * 
 * @author lufer
 * @date   April 2023
 *********************************************************************/
#pragma once
#pragma warning (disable: 4996)

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 20

typedef struct Cidade {
	char nome[N];
	struct Cidade* next;
}Cidade;

/**
 * Cria uma instância de cidade.
 */
Cidade* CriaCidade(char* nome);

/**
 * Regista nova Cidade.
 */
bool RegistaCidade(Cidade** c, Cidade* nova);

/**
 * Regista nova CIdade de forma Recursiva.
 */
Cidade* RegistaCidadeRecursiva(Cidade* h, Cidade* nova, bool* res);

/**
 * Mostra Cidades.
 */
void MostraCidades(Cidade* c);




