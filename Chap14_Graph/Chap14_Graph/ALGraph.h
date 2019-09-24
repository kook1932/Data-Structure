#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include"DLinkedList.h"

// ������ �̸��� ���ȭ
enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
	int numV;		// Vertex�� ��
	int numE;		// Edge�� ��
	List * adjList;	// Edge�� ����
} ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg);

// Edge �߰�
void AddEdge(ALGraph * pg, int fromV, int toV);

// Edge ���� ���
void ShowGraphInfo(ALGraph * pg);

#endif // !__AL_GRAPH_H__
