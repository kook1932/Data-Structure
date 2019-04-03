/*

<�ڷᱸ���� ���� �⺻���� ����>

- �ڷᱸ�� : �����͸� ȿ�������� �����ϴ� ���, �����͸� ǥ���ϰ� �����ϴ� ���
- �˰��� : ǥ�� �� ����� �����͸� ������� �ϴ� ���� �ذ� ���
- �ð� ���⵵ : �ӵ��� �ش��ϴ� �˰����� ����ð� �м����
- ���� ���⵵ : �޸� ��뷮�� ���� �м����
- �˰����� ������ �Ǵ��ϴµ� �־ �߿��� ���� �־��� ����̴�.
- ��� ǥ���
	- O(1) : �Է��� ũ�⿡ ������� ������ �˰���
	- O(logn) : �Է��� ũ�� �������� ���� '���� Ƚ���� ������'�� '�ξ�' ���� �˰���
	- O(n) : ���� ���, �Է��� ũ��� ����Ƚ���� ����ϴ� �˰���
	- O(nlogn) : �����α� ���, �Է��� ũ�Ⱑ �� ��� �� ��, ����Ƚ���� �ι踦 ���� �Ѱ� ����
	- O(n^k)
	- O(k^n)
	- O(n!)
*/

/*
<���� Ž��>

#include<stdio.h>

int Lsearch(int a[], int len, int target)
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		if (a[i] == target)
			return i;
	}
	return -1;
}

int main(void)
{
	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = Lsearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);

	return 0;
}
*/

//����Ž��

#include<stdio.h>

int Bsearch(int a[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == a[mid])
		{
			return mid;
		}

		else
		{
			if (target < mid)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = Bsearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž������");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);

	return 0;
}
