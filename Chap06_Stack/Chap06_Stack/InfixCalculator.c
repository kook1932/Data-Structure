#include<string.h>
#include<stdlib.h>
#include"InfixToPostfix.h"		// Infix를 postfix로 변환
#include"PostCalculator.h"		// 변환한 postfix를 계산

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);		// 문자열 공간 마련
	strcpy(expcpy, exp);		// exp를 expcpy에 복사

	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);

	free(expcpy);
	return ret;
}