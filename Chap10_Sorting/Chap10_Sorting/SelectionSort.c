#include<stdio.h>

// 가장 작은 값을 찾아서 순서대로 인덱스에 넣는다.
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
			if (arr[j] < arr[minIdx])		// 배열을 탐색하면서 가장 작은 값의 인덱스를 찾는다.
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