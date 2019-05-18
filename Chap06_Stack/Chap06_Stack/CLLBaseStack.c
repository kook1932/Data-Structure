#include<stdio.h>
#include<stdlib.h>
#include"CLLBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->clist = (List*)malloc(sizeof(List));
	ListInit(pstack->clist);
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->clist->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	LInsertFront(pstack->clist, data);
}

Data SPop(Stack * pstack)
{
	Data data;
	LFirst(pstack->clist, &data);
	LRemove(pstack->clist);
	return data;
}

Data SPeek(Stack * pstack)
{
	Data data;
	LFirst(pstack->clist,&data);
	return data;
}
