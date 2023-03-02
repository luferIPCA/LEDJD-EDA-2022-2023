/*****************************************************************//**
 * @file   FazTudo.c
 * @brief  Programa principal...
 * 
 * @author lufer
 * @date   February 2023
 *********************************************************************/
#include "Funcoes.h"
#include "Outro.h"
#include <stdio.h>

int main() {

#pragma region UM

	int v[] = { 1,2,3 };

	int x = Sum(2, 3);
	printf("Soma= %d\n",x);

#pragma endregion

#pragma region DOIS

	bool aux = ExisteValorArray(v, 2);

#pragma endregion
}
