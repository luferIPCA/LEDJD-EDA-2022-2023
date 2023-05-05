/*
Apontadores em C
lufer

&p	- endere�o da variavel
p	- valor da variavel
*p	- apontado pela vari�vel

*/

#include <stdio.h>


void troca(int a, int b);
void trocaII(int *a, int *b);

void main() {

	int c = 10;
	int d = 7;

	int *p;

	p = &c;


	//printf("C= %d - *P=%d\n", c,*p);


	printf("Antes: C= %d - D=%d\n", c, d);

	//Uso de parametros por valor
	troca(c, d);

	printf("Depois: C= %d - D=%d\n", c, d);

	//----------------------------------------

	printf("Antes II: C= %d - D=%d\n", c, d);
	//Uso de parametros por refer�ncia
	trocaII(&c, &d);

	printf("Depois II: C= %d - D=%d\n", c, d);

	getche();

}

/*
Tenta trocar dois valores: N�O CONSEGUE!!!
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