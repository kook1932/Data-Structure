#ifndef _CLL_BASE_STACK_H__
#define _CLL_BASE_STACK_H__
#include"CLinkedList.h"

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _cllstack
{
	List * clist;
	int topIndex;
} CllStack;

typedef CllStack Stack;

void StackInit(Stack * pstack);		// ���� �ʱ�ȭ
int SIsEmpty(Stack * pstack);		// ������ ������� Ȯ��

void SPush(Stack * pstack, Data data);		// ������ push ����
Data SPop(Stack * pstack);		// ������ pop ����
Data SPeek(Stack * pstack);		// ������ ������ �� ��ȯ, no ����

#endif // !_CLL_BASE_STACK_H__

