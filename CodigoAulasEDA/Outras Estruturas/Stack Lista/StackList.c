/*
Stacks implementada em Listas simples
lufer
2020
*/

#include "StackList.h"

struct Node* InitStack(struct Node* head)
{
	head = NULL;
	return head;
}

/*
*/
struct Node* PushStack(struct Node* head, int data)
{
	struct Node* tmp = (struct node*)malloc(sizeof(struct Node));
	if (tmp == NULL)
	{
		exit(0);
	}
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	return head;
}

/*
*/
struct Node* PopStack(struct Node *head, int *element)
{
	struct Node* tmp = head;
	*element = head->data;
	head = head->next;
	free(tmp);
	return head;
}

/*
*/
int EmptyStack(struct Node* head)
{
	return head == NULL ? 1 : 0;
}

/*
*/
void ShowStack(struct Node *top) {
	struct Node *aux=top;
	while (aux) {
		printf("Valor = %d\n", aux->data);
		aux = aux->next;
	}
}