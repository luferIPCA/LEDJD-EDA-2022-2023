/**
* Author: lufer
* Email: lufer@ipca.pt
* Date: 
* Desc: Organização de projetos
* 
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Globais.h"

#pragma warning (disable: 4996)

/**
* Programa Principal
*/
int main() {

	Carro y;
	
	int x = Soma(12, 34);
	printf("Soma: %d\n", x);

	strcpy(objetos[0].designacao,"Porto");
	objetos[0].distancia = 70;

	strcpy(objetos[1].designacao, "Lisboa");
	objetos[1].distancia = 350;

	float media = AvgDistObject(objetos, 2);

	printf("Media: %0.2f\n", media);

	_getche();
}