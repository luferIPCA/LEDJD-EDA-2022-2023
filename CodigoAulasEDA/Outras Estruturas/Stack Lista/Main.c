/*
Manipular Stacks
Implementadas em Listas
2020
lufer
*/

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "StackList.h"

int main() {

	struct Node* head = NULL;

	head = PushStack(head, 10);
	head = PushStack(head, 20);

	ShowStack(head);

	int aux;
	head = PopStack(head, &aux);
	
	ShowStack(head);

	getche();

}

//TPC: Implementar Stack de Jogos