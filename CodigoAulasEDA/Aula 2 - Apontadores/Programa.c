/*
* author: lufer
* email: lufer@ipca.pt
* desc: 
*	Aritmética de Apontadores
*	Alocação dinâmica de memória
*/

//#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Dados.h"

void main() {

#pragma region Aritmetica_Pointers

	int x = 10, y = x * 2;
	int* p = &x;

	printf("&x = %p\n", &x);
	printf("*p = %d\n", *p);

	//printf("*p++ = %d\n", *p++);	//CUIDADO
	printf("++(*p) = %d\n", ++(*p));
	printf("(*p)++ = %d\n", (*p)++);
	printf("++*p = %d\n", ++ * p);


	printf("ChangeValor: %d\n", *changeValue(p));
	printf("Maior valor entre %d e %d = %d\n", x, y, *Maior(&x, &y));
	//p = Maior(&x, &y);

#pragma endregion

	getche();			//wait until keypressed

#pragma region Data

	Data *d = (Data*)malloc(sizeof(Data));
	//ou
	//DataPtr d = (DataPtr)malloc(sizeof(Data));
	if (d) {
		d->ano = 12;
		d->dia = 13;
		d->ano = 2023;
	}

#pragma endregion

#pragma region Point
	Point z;
	z.x = 200;
	z.y = 2 * x;

	Point* k = (Point*)malloc(sizeof(Point));
	k->x = z.x;
	k->y = z.y;
	//equivalente a 
	k = &z;
	printf("x: %f - y: %f", k->x, k->y);

#pragma endregion

#pragma region MyObject

	int* tmp = NULL;
	MyObject* my1 = (MyObject*)malloc(sizeof(MyObject));

	my1->valid = 12;
	my1->data = tmp;
	my1->size = sizeof tmp;

#pragma endregion

#pragma region Arrays_Pointers

	//arrays e pointers
	//https://www.programiz.com/c-programming/c-pointers-arrays
	int valores[] = { 1,2,3,4 };
	int* ptr;

	ptr = valores;	//nome do array é o mesmo que &array[0]
	//ou
	//ptr = &valores[0]	
	//*ptr == valores[0]

	//&x[i] é equivalente a x + i
	//x[i] é equivalente a *(x + i).

	printf("p[0]=%d\n", *ptr);
	//printf("p[1]=%d\n", *(ptr + 1));

	for (int i = 0; i < 4; i++) {
		printf("p[%d]=%d\n", i, *(ptr + i));
	}

#pragma endregion

#pragma region Parametros_Pointers

	int pos;
	bool aux = ExisteValorPosicao(valores, 4, 12, &pos);

	int novo = get(&pos);
	printf("pos= %d\n", pos);

#pragma endregion

#pragma region Structs_Pointers

	Pessoa q;
	q.idade = 12;
	strcpy(q.nome, "Julio");

	Pessoa* pq;
	pq = &q;
	//(*pq).idade = 12;
	//ou
	pq->idade = 12;
	strcpy(pq->nome, "Paulo");

	Pessoa z;
	z.idade = 13;
	strcpy(z.nome, "Maria");

	//Definir Maria como prima de Julio
	q.primo = &z;

	printf("Nome Primo: %s", q.primo->nome);


#pragma endregion

	getche();			//wait until keypressed
}