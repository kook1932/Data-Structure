#include<stdio.h>
#include<stdlib.h>
#include"CircularQueue.h"

void QueueInit(Queue * pq)		// 큐가 텅 빈 경우 front와 rear은 동일 위치 가르킴
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)		// front와 rear를 한칸 앞으로 위치, 큐가 꽉 찼을때를 말해줌
{
	if (pos == QUE_LEN - 1)	// 배열의 마지막 요소의 인덱스 값이라면
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue * pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}