#include<stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data; int sum = 0;
	ListInit(&list);

	for (int i = 0; i < 9; i++)
		LInsert(&list, i + 1);
	
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("데이터들의 합 : %d \n", sum);
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if(data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");
}