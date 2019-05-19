#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"ListBaseStack.h"

// �������� �켱������ �ľ��ϴ� �Լ�
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

// �� �������� �켱������ ���ϴ� �Լ�
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

// Infix ������ Postfix�� ��ȯ�ϴ� �Լ�
void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen + 1);		// ��ȯ�� ������ ���� ���� ����

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1);	// �Ҵܵ� �迭�� 0���� �ʱ�ȭ
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];		// exp�� ���޵� ������ �� ���ھ� tok�� ����
		if (isdigit(tok))		// tok�� ����� ���ڰ� �������� Ȯ��
		{
			convExp[idx++] = tok;	// �����̸� �迭 convExp�� ����
		}
		else			// �����ڶ��
		{
			switch (tok)
			{
			case '(':		// '('�� �ٷ� ���ÿ� push
				SPush(&stack, tok);
				break;
			case ')':		// ')'���
				while (1)
				{
					popOp = SPop(&stack);		// ���ÿ��� �����ڸ� ������
					if (popOp == '(')			// ������ '('�� ����������
						break;
					convExp[idx++] = popOp;		// �迭 convExp�� �����Ѵ�
				}
				break;
			case '+': case '-':					// �����ڶ�� ���ÿ� �ִ� �����ڿ� tok�������� �켱������ ���Ͽ�
			case '*': case '/':					// tok�� ���ÿ� �ٷ� push���� ���ÿ� �ִ� �����ڸ� pop�� �ڿ� push���� ����
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))				// ���ÿ� ���� �ִ� ��� �����ڸ�
		convExp[idx++] = SPop(&stack);		// �迭 convExp�� �̵�

	strcpy(exp, convExp);					// ��ȯ�� ������ exp�� ����
	free(convExp);

}