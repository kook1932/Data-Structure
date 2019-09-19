#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Person.h"

int GetSSN(Person * p)
{
	return p->ssn;
}

void ShowPerInfo(Person * p)
{
	printf("�ֹε�Ϲ�ȣ : %d\n", p->ssn);
	printf("�̸� : %s \n", p->name);
	printf("�ּ� : %s \n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
	Person * person = (Person*)malloc(sizeof(Person));
	person->ssn = ssn;
	strcpy(person->name, name);
	strcpy(person->addr, addr);
	return person;
}

