#pragma once

#include <stdbool.h>

#pragma region BASICO

void troca(int a, int b);
void trocaII(int *a, int *b);
int Maior(int *a, int *b);

int* MaiorII(int *a, int *b);		//?????

bool ShowArray(int v[], int n);
bool ShowArrayII(int *v, int n);


#pragma region AVANÇADO
//????
double XXXX(int arr[], int size);

/*
Calcula a média de um array
double GetAverage(int *arr, int size) {
*/
double YYYY(int *arr, int size);

/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArrayIII(int *v, int size);



/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArrayPtr(int v[], int size);

/*
Mostra o conteúdo de um array de inteiros em ordem inversa
*/
void ShowArrayPtrInv(int v[], int size);


// ------------------- Avançado --------------------------

/*
Função que devolve um array de inteiros
*/
int* getEvenNumbers(int N);

#pragma endregion