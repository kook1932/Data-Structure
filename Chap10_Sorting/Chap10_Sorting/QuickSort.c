#include<stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

/*
내가 구현한 left,mid,right에서 중간값을 찾는 함수
but, 오류가 계속남

int selPivot(int arr[], int left, int mid, int right)
{
	int maxArr[3] = { left,mid,right };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2-i; j++)
		{
			if (arr[maxArr[j]] > arr[maxArr[j + 1]])
				Swap(maxArr, j, j + 1);
		}
	}
	return maxArr[1];	
}
*/

// 교재에 나온 중간값의 pivot을 고르는 함수
int MedianOfThree(int arr[], int left, int right)
{
	int samples[3] = { left,(left + right) / 2, right };
	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);
	if (arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);
	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	return samples[1];
}

int Partition(int arr[], int left, int right)
{
	int pIdx = MedianOfThree(arr, left, right);
	int pivot = arr[pIdx];
	int low = left + 1;
	int high = right;
	
	Swap(arr, left, pIdx);
	printf("피벗 : %d \n", pivot);

	while (low <= high)
	{
		// 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low<=right)
			low++;

		// 피벗보다 작은 값을 찾는 과정
		while (pivot <= arr[high] == high>=(left+1))
			high--;

		// 교차되지 않은 상태라면 Swap
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivIdx = Partition(arr, left, right);
		QuickSort(arr, left, pivIdx - 1);
		QuickSort(arr, pivIdx + 1, right);
	}
}

int main(void)
{
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	//int arr[3] = { 3,3,3 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, len-1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}