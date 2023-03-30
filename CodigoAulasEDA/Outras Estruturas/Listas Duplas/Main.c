
#include <stdio.h>
#include "Duplas.h"
#include <time.h>
#include <stdint.h>

int main() {

	//int x = 100;
	//int *xx;
	//xx = &x;

	NodoPtr head = NULL;
	/*Nodo n = { 23,NULL,NULL };
	head = &n;*/
	//n.v
	//head->v
	head = Inicia(head);

	NodoPtr n = NovoNodo(12);
	//printf("Valor=%d\n", n->v);
	head = InsereNodo(head, n);
	NodoPtr n1 = NovoNodo(-1);
	head = InsereNodo(head, n1);
	NodoPtr n2 = NovoNodo(32);
	head = InsereNodo(head, n2);
	NodoPtr n3 = NovoNodo(15);
	head = InsereNodo(head, n3);
	n3 = NovoNodo(15);
	head = InsereNodo(head, n3);
	n1 = NovoNodo(-1);
	head = InsereNodo(head, n1);
	
	printf("Lista de Nodos:\n");
	ShowAll(head);

	//Testar Ficheiros
	Boolean a = Save(head);
	head = NULL;
	head = Load();
	printf("\nLista de Nodos do Ficheiro:\n");
	ShowAll(head);

	//Testar Search
	NodoPtr aux = Search(head, n2);
	printf("\nNodo Encontrado (I):\n");
	ShowNode(aux);

	aux = SearchII(head, n2->v);
	printf("\nNodo Encontrado (II):\n");
	ShowNode(aux);

	//Testar sub-lista
	printf("\nLista de Nodos entre -3 e 15:\n");
	aux = SubLista(head, -3, 15);
	ShowAll(aux);
	
	//Testar Remover
	printf("\nLista de Nodos após remover 32 (I):\n");
	aux = Remove(aux, 32);
	ShowAll(aux);

	/*printf("\nLista de Nodos após remover 12 (II):\n");
	Boolean x = RemoveII(&head, 12);
	ShowAll(head);*/

#pragma region DATES
	//Manipular Datas e Time


		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		printf("%s\n", asctime(tm));

		time_t result = time(NULL);
		if (result != -1)
		printf("The current time is %s(%ju seconds since the Epoch)\n",
				asctime(gmtime(&result)), (uintmax_t)result);
		
#pragma endregion





	getche();


	//printf("Valor=%d\n", n->v);

	//NodoPtr novo = NovoNodo(12);
	//head = InsereNodo(head,novo)
}

