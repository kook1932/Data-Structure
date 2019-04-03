//Àç±ÍÀÇ È°¿ë

/*
Fibonacci Fucntion

#include<stdio.h>

int Fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main(void)
{
	for (int i = 0; i < 15; i++)
		printf("%d ", Fibo(i));
	return 0;
}
*/

//Recursive Binary Search
#include<stdio.h>

int Recursive_Bsearch(int arr[], int first, int last, int target)
{
	if (first > last)
		return -1;
	int mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return Recursive_Bsearch(arr, first, mid - 1, target);
	else
		return Recursive_Bsearch(arr, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx = Recursive_Bsearch(arr, 0, sizeof(arr) / sizeof(int), 9);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ \n");
	else
		printf("Å½»ö ÀÎµ¦½º : %d \n", idx);
	return 0;
}