// LSD(Least Significant Digit 방식의 RadixSort 구현

#include<stdio.h>
#include"ListBaseQueue.h"

#define BUCKET_NUM	10

void RadixSort(int arr[], int num, int maxLen)
{
	// 매개변수 maxLen에는 정렬 대상 중 가장 긴 데이터의 길이 정보 전달
	Queue bucket[BUCKET_NUM];
	int bucIdx;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 총 10개의 버킷 초기화
	for (bucIdx = 0; bucIdx < BUCKET_NUM; bucIdx++)
		QueueInit(&bucket[bucIdx]);

	// 가장 긴 데이터의 길이만큼 반복
	for (pos = 0; pos < maxLen; pos++)
	{
		// 정렬대상의 수만큼 반복
		for (di = 0; di < num; di++)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[di] / divfac) % 10;

			// 추출한 숫자를 근거로 버킷에 저장
			Enqueue(&bucket[radix], arr[di]);
		}

		// 버킷 수만큼 반복
		for (bucIdx = 0, di = 0; bucIdx < BUCKET_NUM; bucIdx++)
		{
			// 버킷에 저장된 순서대로 다 꺼내서 다시 arr에 저장
			while (!QIsEmpty(&bucket[bucIdx]))
				arr[di++] = Dequeue(&bucket[bucIdx]);
		}

		divfac *= 10;
	}
}

int main(void)
{
	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int i;
	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}