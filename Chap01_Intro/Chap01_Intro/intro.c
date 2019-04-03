/*

<자료구조에 대한 기본적인 이해>

- 자료구조 : 데이터를 효율적으로 관리하는 기법, 데이터를 표현하고 저장하는 방법
- 알고리즘 : 표현 및 저장된 데이터를 대상으로 하는 문제 해결 방법
- 시간 복잡도 : 속도에 해당하는 알고리즘의 수행시간 분석결과
- 공간 복잡도 : 메모리 사용량에 대한 분석결과
- 알고리즘의 성능을 판단하는데 있어서 중요한 것은 최악의 경우이다.
- 빅오 표기법
	- O(1) : 입력의 크기에 상관없이 일정한 알고리즘
	- O(logn) : 입력의 크기 증가율에 비해 '연산 횟수의 증가율'이 '훨씬' 낮은 알고리즘
	- O(n) : 선형 빅오, 입력의 크기와 연산횟수가 비례하는 알고리즘
	- O(nlogn) : 선형로그 빅오, 입력의 크기가 두 배로 늘 때, 연산횟수는 두배를 조금 넘게 증가
	- O(n^k)
	- O(k^n)
	- O(n!)
*/

/*
<순차 탐색>

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
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	return 0;
}
*/

//이진탐색

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
		printf("탐색실패");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	return 0;
}
