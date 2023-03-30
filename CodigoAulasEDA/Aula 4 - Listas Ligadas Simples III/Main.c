/*****************************************************************//**
 * @file   Main.c
 * @brief	Revisões;
 *			Explorar apontadores duplos (**)
 * 
 * @author lufer
 * @date   March 2023
 *********************************************************************/
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
#pragma region Revisões_Pointers&Elements

	//struct
	Cliente c;
	c.num = 1;

	//struct pointer
	Cliente* p;
	p = &c;		//p fica a apontar para p!
	p->num++;	//c.num passa a 2

	//Qual o valor de *p? e de c?
	
	//alocar memória para *p
	p = (Cliente*)malloc(sizeof(Cliente));
	if (p == NULL) return 0;
	p->num = 2;
	//Qual o valor de *p?

	//struct list element
	ClienteLista a;
	a.c.num = 3;
	a.next = NULL;
	
	//struct list pointer
	ClienteLista* head;
	head = &a;			//head fica a apontar para a
	//qual o valor de a? e de *head? e de head?

	//struct pointer
	ClienteLista* outra = (ClienteLista*)malloc(sizeof(ClienteLista));
	(outra->c).num = 40;
	outra->next = NULL;

	//constroi lista
	head->next = outra;

	MostraLista(head);

#pragma endregion

#pragma region DoublePointers

bool aux = InsertNode(&head, p);
if (aux == true) {}

//aux = InsertNode(&k, p);	//testa se admite repetidos
//if (aux == false) {}

MostraLista(head);

Cliente q = { 39 };

aux = InsertNode(&head, &q);
MostraLista(head);

ClienteLista* outra3 = (ClienteLista*)malloc(sizeof(ClienteLista));
(outra3->c).num = 40;
outra3->next = NULL;

aux = InsertNodeII(&head, outra3); //Não está a funcionar!!!
printf("\n%s\n", (aux == true) ? "Inseriu" : "Não Inseriu");

MostraLista(head);	

#pragma endregion

}
