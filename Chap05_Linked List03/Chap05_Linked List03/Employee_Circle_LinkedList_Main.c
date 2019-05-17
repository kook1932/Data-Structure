/*
���� 5-1 : ������ ������ �����ϴ� ���� ���� ����Ʈ ����
- ���� ���� : ���(int), �̸�(char)
- ����Ʈ���� ����ü ������ �ּ� ���� ����
- ����Ʈ ������� ������ ����
- ������ �̸��� ���ڸ� ���ڷ� �����ϸ� ���޵� �̸��� ������ ������ �� ��,
  ���޵� ���ڿ� �ش��ϴ� ��ŭ�� ���� ������ ������ ���� �Ǵ� ������ ������ ��ȯ
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

	// List�� ���� �� �ʱ�ȭ
	List list;
	ListInit(&list);

	// 4���� ������ ����
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

	// Terry �ڷ� 3�� �� �����ڴ�?
	temp = WhoIsNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(temp);

	// Sunny �ڷ� 15�� �� �����ڴ�?
	temp = WhoIsNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(temp);

	// ��ü ���
	if (LFirst(&list, &temp))
	{
		ShowEmployeeInfo(temp);

		for (i = 0; i < 7; i++)
		{
			if (LNext(&list, &temp))
				ShowEmployeeInfo(temp);
		}
	}

	// �Ҵ�� �޸��� ��ü �Ҹ�
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

	// �̸� ã��
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

	// ��ĥ ��
	for (i = 0; i < day; i++)
		LNext(plist, &ret);
	
	return ret;
}

void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee name : %s \n", emp->name);
	printf("Employee number : %d \n", emp->empNum);
}