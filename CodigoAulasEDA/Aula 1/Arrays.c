/**
* Author: lufer
* Email: lufer@ipca.pt
* Date: 
* Desc: M�dulo para Gerir Arrays
* 		Consolia��o de C
*/

#include<stdbool.h>
#include "Globais.h"

#pragma region Arrays

/**
* Encontra o maior valor de um array
*/
int FindMaxArray(int v[], int n) {
	int maior = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] > maior) maior = v[i];
	}
	return maior;
}

/**
*/
bool ExisteValorArray(Carro v[], int n) {
	return false;

}

/**
* a) Calcula a m�dia....
*/
float AvgDistObject(Objeto v[], int n) {
	float totDist = 0;

	for (int i = 0; i < n; i++) {
		totDist += v[i].distancia;
	}
	return(totDist / n);
}

#pragma endregion
