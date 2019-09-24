#ifndef __GRAPH_BFS_H__
#define __GRAPH_BFS_H__

#include "DLinkedList.h"

// ������ �̸��� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;		// Vertex�� ��
	int numE;		// Edge�� ��
	List * adjList;	// Edge�� ����
	int * visitInfo;	// Ž���� ����� ������ ������ ����(Linked List)
} ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg);

// Edge �߰�
void AddEdge(ALGraph * pg, int fromV, int toV);

// Edge ���� ���
void ShowGraphEdgeInfo(ALGraph * pg);

// BFS ��� �׷����� ���� ���� ���
void BFShowGraphVertex(ALGraph * pg, int startV);

#endif // !__GRAPH_BFS_H__

