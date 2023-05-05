/*
PP1
autor: lufer
Desc: Apontadores em C

Ver:
http://generalnote.com/C-Programm/Programs-on-Pointer/index.php
http://www.cs.dartmouth.edu/~campbell/cs50/ccontinued.html
https://www.tutorialspoint.com/cprogramming/c_arrays.htm
*/

#include "Funcoes.h"
#include <stdio.h>


#pragma region 
/*
Tenta trocar dois valores: NÃO CONSEGUE!!!
*/
void troca(int a, int b) {
	int t = a;
	a = b;
	b = t;
}

void trocaII(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//Exercício
//Calcular o maior
//Calcular o máximo

//Mostrar um array

//int Maior(int a, int b) {
//	if (a > b) return a;
//	return b;
//
//}

int Maior(int *a, int *b) {
	if (*a > *b) return *a;
	return *b;

}

int* MaiorII(int *a, int *b) {
	if (*a > *b) return *a;	//return *a;			  
	return *b;				//return *b;
}


//Mostra conteúdo de um array
bool ShowArray(int v[], int n) {
	if (n < 0) return false;
	for (int i = 0; i < n; i++) printf("v[%d]=%d\n", i, v[i]);
	return true;
}

//Mostra conteúdo de um array
bool ShowArrayII(int *v, int n) {
	for (int i = 0; i < n; i++) 
		printf("v[%d]=%d\n", i, v[i]);
}

/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArrayIII(int *v, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("*(v+%d)=%d\n", i, *(v + i));
	}
}



/*
Calcula a média de um array
Versão I
double getAverage(int arr[], int size) {
*/
double XXXX(int arr[], int size) {
	int i;
	double avg;
	double sum = 0;

	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	avg = sum/size;
	return avg;
}

/*
Calcula a média de um array
double GetAverage(int *arr, int size) {
*/
double YYYY(int *arr, int size) {
	int  i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i) {
		sum += *(arr+i);//arr[i];		//*arr
	}
	avg = (double)sum / size;
	return avg;
}

#pragma endregion

#pragma region
/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArrayPtr(int v[], int size) {
	int *pt = &v[0];	//pt=v;
	int i;
	for (i = 0; i < size; i++) {
		//printf("*(p+%d)=%d\n", i, *(v + i));
		printf("Endereço de v[%d] = %p\n", i, pt);
		printf("Valor de v[%d] = %d\n", i, *pt);
		pt++;
	}
}

/*
Mostra o conteúdo de um array de inteiros em ordem inversa
*/
void ShowArrayPtrInv(int v[], int size) {

	int *pt = &v[size - 1];
	int i;

	for (i = size; i >0; i--) {
		//printf("*(p+%d)=%d\n", i, *(v + i));
		printf("Endereço de v[%d] = %p\n", i - 1, pt);
		printf("Valor de v[%d] = %d\n", i - 1, *pt);
		pt--;
	}
}


// ------------------- Avançado --------------------------

/*
Função que devolve um array de inteiros
*/
int* getEvenNumbers(int n) {
	/* declarar como static a variável local */
	//static int evenNumberArray[100];
	int sum=0;
	int* evenNumberArray = (int*) malloc(sizeof(int) * n);
	int  evenNumberArray[20];

	for (int i = 0; i < 50; i++) {
		evenNumberArray[i] = 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		scanf_s("%d", &evenNumberArray + i);
		sum += *(evenNumberArray + i);
	}

	int i, aux = 2;
	//h1
	//inicia o array
	for (i = 0; i<n; i++) {
		*(evenNumberArray+i) = aux;

		printf("%d - ", aux);
		aux += 2;
	}
	/* Devolve o endereço da primeira posição do array*/
	return evenNumberArray;

	{
		//h2
		//static int * valores;
		//valores = (int *)malloc(sizeof(int)*n);

		//for (i = 0; i<N; i++) {
		//	//valores[i] = aux;
		//	*(valores + i) = aux;
		//	aux += 2;
		//}
		//return valores;
	}

}

#pragma endregion AVANÇADO