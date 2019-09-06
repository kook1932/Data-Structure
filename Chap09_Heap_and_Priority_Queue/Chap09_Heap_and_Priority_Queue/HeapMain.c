#include <stdio.h>
#include"Heap.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2- ch1;
}

int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'a');
	HInsert(&heap, 'b');
	HInsert(&heap, 'c');
	HInsert(&heap, 'd');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	HInsert(&heap, 'D');
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}