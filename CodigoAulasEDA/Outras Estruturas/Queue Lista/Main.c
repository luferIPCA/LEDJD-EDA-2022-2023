/*
Queue manipulation
lufer
2020
*/

#include <stdio.h>
#include "Queue.h"

int main() {
	Control *ht = Create();

	ht = Enqueue(ht, 2);
	ht = Enqueue(ht, 4);
	ht = Enqueue(ht, -1);
	printf("\nQueue:\n");
	ShowQueue(ht);
	ht = Dequeue(ht);
	ht = Enqueue(ht, 10);
	printf("\nQueue:\n");
	ShowQueue(ht);

	system("pause");
	return 0;
}