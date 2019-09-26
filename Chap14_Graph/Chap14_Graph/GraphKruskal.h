#ifndef __GRAPH_KRUSKAL_H__
#define __GRAPH_KRUSKAL_H__

#include"DLinkedList.h"
#include"PriorityQueue.h"
#include"Edge.h"

// 정점의 이름을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;		// Vertex의 수
	int numE;		// Edge의 수
	List * adjList;	// Edge의 정보
	int * visitInfo;	// 탐색이 진행된 정점의 정보를 담음(Linked List)
	PQueue pqueue;		// edge의 weight 정보를 저장
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// Edge 추가
void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

// Edge 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// Vertex의 정보 출력 : DFS 기반
void DFShowGraphVertex(ALGraph * pg, int startV);

// 최소 신장 트리의 구성
void ConKruskalMST(ALGraph * pg);

// 가중치 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

#endif // !__GRAPH_KRUSKAL_H__

