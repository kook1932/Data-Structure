/*
문제 5-1 : 직원의 정보를 저장하는 원형 연결 리스트 구현
- 직원 정보 : 사번(int), 이름(char)
- 리스트에는 구조체 변수의 주소 값을 저장
- 리스트 순서대로 당직을 선다
- 직원의 이름과 숫자를 인자로 전달하면 전달된 이름의 직원이 당직을 선 후,
  전달된 숫자에 해당하는 만큼의 날이 지나서 당직을 서게 되는 직원의 정보를 반환
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ECLinkedList.h"
#include"Employee.h"

int main(void)
{
	Employee * WhoIsNightDuty(List * plist, char * name, int day);
	void ShowEmployeeInfo(Employee * emp);

	int i;
	Employee * temp;

	// List의 생성 및 초기화
	List list;
	ListInit(&list);

	// 4명의 데이터 저장
	temp = (Employee*)malloc(sizeof(Employee));
	temp->empNum = 1111;
	strcpy(temp->name, "Terry");
	LInsert(&list, temp);

	temp = (Employee*)malloc(sizeof(Employee));
	temp->empNum = 2222;
	strcpy(temp->name, "Jery");
	LInsert(&list, temp);

	temp = (Employee*)malloc(sizeof(Employee));
	temp->empNum = 3333;
	strcpy(temp->name, "Hary");
	LInsert(&list, temp);

	temp = (Employee*)malloc(sizeof(Employee));
	temp->empNum = 4444;
	strcpy(temp->name, "Sunny");
	LInsert(&list, temp);

	// Terry 뒤로 3일 뒤 당직자는?
	temp = WhoIsNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(temp);

	// Sunny 뒤로 15일 뒤 당직자는?
	temp = WhoIsNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(temp);

	// 전체 출력
	if (LFirst(&list, &temp))
	{
		ShowEmployeeInfo(temp);

		for (i = 0; i < 7; i++)
		{
			if (LNext(&list, &temp))
				ShowEmployeeInfo(temp);
		}
	}

	// 할당된 메모리의 전체 소멸
	if (LFirst(&list, &temp))
	{
		free(temp);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &temp))
				free(temp);
		}
	}

	return 0;

}

Employee * WhoIsNightDuty(List * plist, char * name, int day)
{
	int i, num;
	Employee * ret;
	num = LCount(plist);

	// 이름 찾기
	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0)
	{
		for (i = 0; i < LCount(plist) - 1; i++)
		{
			LNext(plist, &ret);

			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}

	// 며칠 뒤
	for (i = 0; i < day; i++)
		LNext(plist, &ret);
	
	return ret;
}

void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee name : %s \n", emp->name);
	printf("Employee number : %d \n", emp->empNum);
}