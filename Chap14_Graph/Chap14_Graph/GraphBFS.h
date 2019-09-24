#ifndef __GRAPH_BFS_H__
#define __GRAPH_BFS_H__

#include "DLinkedList.h"

// 정점의 이름을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;		// Vertex의 수
	int numE;		// Edge의 수
	List * adjList;	// Edge의 정보
	int * visitInfo;	// 탐색이 진행된 정점의 정보를 담음(Linked List)
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// Edge 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// Edge 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// BFS 기반 그래프의 정점 정보 출력
void BFShowGraphVertex(ALGraph * pg, int startV);

#endif // !__GRAPH_BFS_H__

