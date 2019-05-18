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

void StackInit(Stack * pstack);		// 스택 초기화
int SIsEmpty(Stack * pstack);		// 스택이 비었는지 확인

void SPush(Stack * pstack, Data data);		// 스택의 push 연산
Data SPop(Stack * pstack);		// 스택의 pop 연산
Data SPeek(Stack * pstack);		// 스택의 마지막 값 반환, no 삭제

#endif // !_CLL_BASE_STACK_H__

