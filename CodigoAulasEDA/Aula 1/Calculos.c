/**
* Author: lufer
* Email: lufer@ipca.pt
* Date: 
* Desc: M�dulo para Fun��es de Calculo
*/

#include "Globais.h"

#pragma region Calculos

/**
* Calcula a soma de dois valores inteiros
*/
int Soma(int x, int y) {
	return (x + y);
}


/**
* Calcula o valor absoluto de um n�mero
*/
int Abs(int n) {
	if (n < 0) return (-1 * n);
	return (n);

	//return ((n < 0)? (-1) * n : n);
}


#pragma endregion
