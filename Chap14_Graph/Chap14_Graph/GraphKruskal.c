#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"GraphKruskal.h"
#include"ArrayBaseStack.h"
#include"DLinkedList.h"
#include"PriorityQueue.h"
#include"Heap.h"

int WhoIsPrecede(int data1, int data2);
void RemoveEdge(ALGraph * pg, int fromV, int toV);
void RemoveWayEdge(ALGraph * pg, int fromV, int toV);
void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight);
int IsConnVertex(ALGraph * pg, int v1, int v2);

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV);
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);

	// Priority Queue �ʱ�ȭ
	PQueueInit(&(pg->pqueue), PQWeightComp);
}

// �׷��� ���ҽ��� ����
void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// Edge�� �߰�
void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV,toV,weight };	// edge�� ����ġ ������ ����

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;

	// edge�� ����ġ ������ �켱���� ť�� ����
	PEnqueue(&(pg->pqueue), edge);
}

// Edge ���� ���
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ���� : ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

// �� ��° �Ű������� ���޵� �̸��� ������ �湮
int VisitVertex(ALGraph * pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		//printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

// DFS ������� ���ǵ� �Լ� : ������ ���� ���
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	// visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� while��
	while (LFirst(&(pg->adjList[visitV]), &nextV))
	{
		// visitV�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� ����
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)		// �湮�� �����ߴٸ�,
		{
			SPush(&stack, visitV);		// visitV�� ��� ������ ������ Push
			visitV = nextV;
			visitFlag = TRUE;
		}
		else		// �湮�� �������� ���ߴٸ�, ����� �ٸ� �������� ã�´�
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
				}
			}
		}

		// �߰��� �湮�� ������ ���ٸ�
		if (visitFlag == FALSE)
		{
			// ������ ��������� Ž���� ���������� �ǵ��� �� ��
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);		// ���� �ǵ��� ����
		}
	}
	// ������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

// ũ�罺Į �˰��� ��� MST�� ����
void ConKruskalMST(ALGraph * pg)
{
	Edge recvEdge[20];	// ������ ������ ���� ����
	Edge edge;
	int eidx = 0;
	int i;

	// MST�� ������ ������ while�� �ݺ�
	while (pg->numE + 1 > pg->numV)	// MST edge�� �� +1 == vertex�� ��
	{
		edge = PDequeue(&(pg->pqueue));		// �켱���� ť���� ����ġ�� ���� ���� ������ ������ ����
		RemoveEdge(pg, edge.v1, edge.v2);	// ���� ������ �׷������� ����

		if (!IsConnVertex(pg, edge.v1, edge.v2))			// ������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ��
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);	// ��ΰ� ���ٸ� ������ ������ ����
			recvEdge[eidx++] = edge;						// ������ ������ ������ ������ ����
		}
	}

	// �켱���� ť���� ������ ������ ������ ȸ��
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf(" (%c - %c), w : %d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge))
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge))
		{
			if (edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// ���ڷ� ���޵� �� ������ ����Ǿ� �ִٸ� TRUE, �׷��� �ʴٸ� FALSE ��ȯ
int IsConnVertex(ALGraph * pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		// vertex�� ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE�� ��ȯ�Ѵ�
		if (nextV == v2)
		{
			// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� �����Ѵ�
			memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
			return TRUE;
		}

		// ����� vertex�� �湮
		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				// ������ ���ƴٴ� ���߿� ��ǥ�� ã�´ٸ� TRUE�� ��ȯ�Ѵ�
				if (nextV == v2)
				{
					// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� �����Ѵ�
					memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, nextV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
	return FALSE;
}