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

typedef struct {
	int valid;
	int* data;
	size_t size;
} MyObject;

typedef struct Data
{
	int dia;
	char mes[10];
	int ano;
}Data, * DataPtr;

typedef struct Point {
	double x;
	double y;
}Point, * PointPtr;

#endif  // !X