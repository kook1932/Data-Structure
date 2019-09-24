#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"GraphDFS.h"
#include"ArrayBaseStack.h"
#include"DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
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
}

// 그래프 리소스의 해제
void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// Edge의 추가
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}

// Edge 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점 : ", i + 65);

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

// 두 번째 매개변수로 전달된 이름의 정점에 방문
int VisitVertex(ALGraph * pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

// DFS 기반으로 정의된 함수 : 정점의 정보 출력
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	while (LFirst(&(pg->adjList[visitV]), &nextV))
	{
		// visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)		// 방문에 성공했다면,
		{
			SPush(&stack, visitV);		// visitV에 담긴 정점의 정보를 Push
			visitV = nextV;
			visitFlag = TRUE;
		}
		else		// 방문에 성공하지 못했다면, 연결된 다른 정점들을 찾는다
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

		// 추가로 방문한 정점이 없다면
		if (visitFlag == FALSE)
		{
			// 스택이 비어있으면 탐색의 시작점으로 되돌아 온 것
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);		// 길을 되돌아 간다
		}
	}
	// 이후의 탐색을 위해서 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}