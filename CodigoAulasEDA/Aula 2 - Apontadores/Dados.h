/*
* author: lufer
* email: lufer@ipca.pt
* date: 06.03.2022
* desc: Defini��o de Assinaturas, #defines, typedef
*/

//#pragma once
#ifndef X
#define X 1

#include <stdbool.h>

int* changeValue(const int* p);
int* Maior(int* p, int* q);
int get(int* ptr);
bool ExisteValorPosicao(int v[], int n, int valor, int* pos);

#define N 20
typedef struct Pessoa {
	int idade;
	char nome[N];
	struct Pessoa* primo;
}Pessoa;
#endif  // !X