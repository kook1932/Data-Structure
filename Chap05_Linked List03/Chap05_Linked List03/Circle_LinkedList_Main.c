#include<stdio.h>
#include"CLinkedList.h"

int main(void)
{
	// Circle Linked list�� ���� �� �ʱ�ȭ
	List list;
	int data;
	int nodeNum;
	ListInit(&list);

	// list�� 5���� �����͸� ����
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// list�� ����� �����͸� ���� 3ȸ ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 2�� ����� ã�Ƽ� ��� ����
	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (int i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// ��ü ������ 1ȸ ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	return 0;
}