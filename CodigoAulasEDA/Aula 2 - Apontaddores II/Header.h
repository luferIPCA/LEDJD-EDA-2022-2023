/*****************************************************************//**
 * @file   Header.h
 * @brief  Assinatura...
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#pragma once
#include <stdbool.h>
#include <stdio.h>

#define N 20

typedef struct Pessoa{
	int idade;
	char nome[N];
}Pessoa, *PessoaPtr;

bool InicializaArray(Pessoa* p[], int t);
bool InserePessoa(Pessoa* p[], int *t, Pessoa nova);
int InserePessoaII(Pessoa* p[], int t, Pessoa n);
