#ifndef __GRAPH_KRUSKAL_H__
#define __GRAPH_KRUSKAL_H__

#include"DLinkedList.h"
#include"PriorityQueue.h"
#include"Edge.h"

// ������ �̸��� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;		// Vertex�� ��
	int numE;		// Edge�� ��
	List * adjList;	// Edge�� ����
	int * visitInfo;	// Ž���� ����� ������ ������ ����(Linked List)
	PQueue pqueue;		// edge�� weight ������ ����
} ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg);

// Edge �߰�
void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

// Edge ���� ���
void ShowGraphEdgeInfo(ALGraph * pg);

// Vertex�� ���� ��� : DFS ���
void DFShowGraphVertex(ALGraph * pg, int startV);

// �ּ� ���� Ʈ���� ����
void ConKruskalMST(ALGraph * pg);

// ����ġ ���� ���
void ShowGraphEdgeInfo(ALGraph * pg);

#endif // !__GRAPH_KRUSKAL_H__

