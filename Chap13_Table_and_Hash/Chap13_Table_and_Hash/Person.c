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
	printf("주민등록번호 : %d\n", p->ssn);
	printf("이름 : %s \n", p->name);
	printf("주소 : %s \n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
	Person * person = (Person*)malloc(sizeof(Person));
	person->ssn = ssn;
	strcpy(person->name, name);
	strcpy(person->addr, addr);
	return person;
}

