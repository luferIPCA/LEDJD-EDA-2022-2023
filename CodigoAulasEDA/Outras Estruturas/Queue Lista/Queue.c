/*
Queues implementada em Listas simples
lufer
2020
*/

#include "Queue.h"

/*
Devolve Próximo da Fila de Espera
*/
int FrontElement(Control *h) {
	if (!Empty(h)) return h->head->valor;
};

/*
Insere na Fila de Espera
*/
Control *Enqueue(Control *ht, int data)
{
	//Necessário verificar se já existe...
	Queue *temp;	
	temp = (Queue *)malloc(1 * sizeof(Queue));
	temp->next = NULL;
	temp->valor = data;
	if (ht->head == NULL) {
		ht->head = temp;
		ht->tail = temp;
	}
	else {		//insere no final
			ht->tail->next = temp;
			ht->tail = temp;
	}	
	return ht;
}

/*
Verifica se Fila de Espera está vazia
*/
bool Empty(Control *h) {
	return (h->head == NULL);
}

/*
Mostra Fila de Espera
*/
void ShowQueue(Control *ht) {
	int c = 0;
	Queue *aux = ht->head;
	while (aux) {
		printf("%d\n", aux->valor);
		aux = aux->next;
	}
}


/*
Cria uma Lista de Espera
*/
Control* Create() {
	Control *ht = (Control*) malloc(sizeof(Control) * 1);
	ht->head = NULL;
	ht->tail = NULL;
	return (ht);
}

/*
Devolve o número de elementos da FIla de Espera
*/
int QueueSize(Control *ht) {
	int c = 0;
	Queue *aux = ht->head;
	while (aux) {
		aux = aux->next;
		c++;
	}
	return c;
}

/*
Atende o próximo da Fila de Espera
*/
Control *Dequeue(Control*ht) {
	Queue *auxHead = ht->head;
	if (ht->head != NULL) 
	{
		//auxHead = ht->head;
		ht->head = auxHead->next;
		auxHead->next = NULL;
		free(auxHead);
	}
	return ht;
}
