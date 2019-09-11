#include<stdio.h>

// ���� ���� ���� ã�Ƽ� ������� �ε����� �ִ´�.
void SelSort(int arr[], int n)
{
	int i, j;
	int minIdx;
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		minIdx = i;

		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIdx])		// �迭�� Ž���ϸ鼭 ���� ���� ���� �ε����� ã�´�.
				minIdx = j;
		}

		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

int main(void)
{
	int arr[4] = { 3,4,2,1 };
	int i;

	SelSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}