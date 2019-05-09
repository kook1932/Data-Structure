#include<stdio.h>
#include"DLinkedList.h"

int WhoisPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void)
{
	// ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoisPrecede);		// ����Ʈ�� ���� ������ ��� -> ��������

	// 5���� ������ ����
	LInsert(&list, 11); LInsert(&list, 11); LInsert(&list, 22);
	LInsert(&list, 22); LInsert(&list, 33);

	// ����� �������� ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ����
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ���� �� �����ִ� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}