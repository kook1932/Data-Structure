#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"ListBaseStack.h"

// 연산자의 우선순위를 파악하는 함수
int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case'+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}

// 두 연산자의 우선순위를 비교하는 함수
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

// Infix 수식을 Postfix로 변환하는 함수
void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen + 1);		// 변환된 수식을 담을 공간 마련

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1);	// 할단된 배열을 0으로 초기화
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];		// exp로 전달된 수식을 한 문자씩 tok에 저장
		if (isdigit(tok))		// tok에 저장된 문자가 숫자인지 확인
		{
			convExp[idx++] = tok;	// 숫자이면 배열 convExp에 저장
		}
		else			// 연산자라면
		{
			switch (tok)
			{
			case '(':		// '('는 바로 스택에 push
				SPush(&stack, tok);
				break;
			case ')':		// ')'라면
				while (1)
				{
					popOp = SPop(&stack);		// 스택에서 연산자를 꺼내어
					if (popOp == '(')			// 연산자 '('를 만날때까지
						break;
					convExp[idx++] = popOp;		// 배열 convExp에 저장한다
				}
				break;
			case '+': case '-':					// 연산자라면 스택에 있는 연산자와 tok연산자의 우선순위를 비교하여
			case '*': case '/':					// tok이 스택에 바로 push될지 스택에 있는 연산자를 pop한 뒤에 push할지 결정
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))				// 스택에 남아 있는 모든 연산자를
		convExp[idx++] = SPop(&stack);		// 배열 convExp로 이동

	strcpy(exp, convExp);					// 변환된 수식을 exp에 복사
	free(convExp);

}