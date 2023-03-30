//-----------------------------------------------------------------------
// <copyright file="stack.h" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2020</date>
// <author>lufer</author>
// <email>lufer@ipca.pt</email>
// <version></version>
// <desc>Manipulação de Queue com Listas</desc>
//-----------------------------------------------------------------------


#include <stdio.h>
#include <stdbool.h>

#ifndef QUEUE
#define QUEUE

//Elemento da Queue
typedef struct Node
{
	int valor;
	struct Node *next;
}Queue, *QueuePtr;

//preservar o inicio e fim da fila
typedef struct Control {
	struct Node *head;		//inicio da fila
	struct Node *tail;		//fim da fila
}Control;

//Assinaturas
int FrontElement(Control*h);
Control *Dequeue(Control *h);
Control *Enqueue(Control *ht, int data);
bool Empty(Control *h);
void ShowQueue(Control *h);
Control *Create();
int QueueSize(Control *h);

#endif