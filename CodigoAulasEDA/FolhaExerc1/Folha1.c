/*****************************************************************//**
 * @file   Folha2.c
 * @brief  Implementação da Folha de Exercícios 2
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/

#include <stdio.h>
#include "Header.h"

int main(){
	//int a = Soma(2, 3);
	//printf("%d + %d = %d\n", 2, 3, a);
	//ou
	printf("%d + %d = %d\n", 2, 3, Soma(2, 3));

#pragma region PARAMETROS_APONTADORES

	int x = 2;
	int y = 3;
	int a = SomaApontadores(&x, &y);
	printf("%d + %d = %d\n", x, y, a);

	SomaApontadoresII(&x, &y, &a);
	printf("%d + %d = %d\n", x, y, a);

	a = MaiorII(&x, &y);

	int r;
	bool b = MaiorIII(&x, &y, &r);

#pragma endregion

#pragma region Arrays

	int valores[] = { 2,3,-4,123 };
	MostraArray(valores, 4);

	MostraArrayII(valores, 4);

#pragma endregion

}
