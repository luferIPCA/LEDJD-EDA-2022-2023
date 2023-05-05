/*
PP1

autor: lufer
Desc:Apontadores em C


Notas:
&p	- endere�o da variavel
p	- valor da variavel
*p	- apontado pela vari�vel


Pointers:
	- Fundamentos
	- Passagem de par�metros por refer�ncia (vari�vel)
	- aloca��o de mem�ria din�mica
	- Estruturas de Dados (structs)

Ver:
http://generalnote.com/C-Programm/Programs-on-Pointer/index.php

*/

#pragma warning (disable: 4996)

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>




void main() {

	setlocale(LC_ALL, "Portuguese");
	int c = 10;
	int d = 7;
	int *p;
	int v[] = {-2, 3, 15, 0, 2};

	p = &c;


	printf("Valor de c: %d  - Endere�o de c: %p\n", c, &c);
	printf("Valor de p == Endere�o de c: %p\n",  p);
	printf("Valor de *p: %d  - Endere�o de p: %p\n", *p, &p);

	printf("Antes: C= %d - D=%d\n", c, d);

	/*int* p = (int*)malloc(sizeof(int) * 10);
		
	printf("%d",sizeof(*p));*/


	//Uso de parametros por valor
	//troca(c, d);

	//printf("Depois: C= %d - D=%d\n", c, d);

	//----------------------------------------

	//printf("Antes II: C= %d - D=%d\n", c, d);
	//Uso de parametros por refer�ncia
	//trocaII(&c, &d);

	//printf("Depois II: C= %d - D=%d\n", c, d);

	//int a = Maior(2, 3);
	//int a = Maior(c, d);
	//int a = Maior(&c, &d);


	//int* b = MaiorII(&c, &d);

	//bool x = ShowArray(v, sizeof(v) / sizeof(v[0]));

	//x = ShowArrayII(v, sizeof(v) / sizeof(v[0]));



	//double avg = YYYY(v, sizeof(v) / sizeof(v[0]));

	//avg = XXXX(v, sizeof(v) / sizeof(v[0]));


	int *valores = getEvenNumbers(10);


	bool x = ShowArrayIII(valores, 10);

	getche();

}

