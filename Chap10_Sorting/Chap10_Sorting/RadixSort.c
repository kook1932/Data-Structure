// LSD(Least Significant Digit ����� RadixSort ����

#include<stdio.h>
#include"ListBaseQueue.h"

#define BUCKET_NUM	10

void RadixSort(int arr[], int num, int maxLen)
{
	// �Ű����� maxLen���� ���� ��� �� ���� �� �������� ���� ���� ����
	Queue bucket[BUCKET_NUM];
	int bucIdx;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// �� 10���� ��Ŷ �ʱ�ȭ
	for (bucIdx = 0; bucIdx < BUCKET_NUM; bucIdx++)
		QueueInit(&bucket[bucIdx]);

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (pos = 0; pos < maxLen; pos++)
	{
		// ���Ĵ���� ����ŭ �ݺ�
		for (di = 0; di < num; di++)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[di] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ����
			Enqueue(&bucket[radix], arr[di]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for (bucIdx = 0, di = 0; bucIdx < BUCKET_NUM; bucIdx++)
		{
			// ��Ŷ�� ����� ������� �� ������ �ٽ� arr�� ����
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