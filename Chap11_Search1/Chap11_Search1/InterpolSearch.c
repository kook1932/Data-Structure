#include<stdio.h>

int ISearch(int arr[], int first, int last, int target)
{
	int interIdx;

	// Å½»ö ½ÇÆĞ
	if (first > last)
		return -1;

	interIdx = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

	if (target == arr[interIdx])
		return interIdx;
	else if (target < arr[interIdx])
		return ISearch(arr, first, interIdx - 1, target);
	else
		return ISearch(arr, interIdx + 1, last, target);
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d \n", idx);

	return 0;
}