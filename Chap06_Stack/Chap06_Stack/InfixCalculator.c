#include<string.h>
#include<stdlib.h>
#include"InfixToPostfix.h"		// Infix�� postfix�� ��ȯ
#include"PostCalculator.h"		// ��ȯ�� postfix�� ���

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);		// ���ڿ� ���� ����
	strcpy(expcpy, exp);		// exp�� expcpy�� ����

	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);

	free(expcpy);
	return ret;
}