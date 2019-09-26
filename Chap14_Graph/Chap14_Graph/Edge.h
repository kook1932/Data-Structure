#ifndef __EDGE_H__
#define __EDGE_H__

typedef struct _edge
{
	int v1;		// edge가 연결하는 첫 번째 vertex
	int v2;		// edge가 연결하는 두 번째 vertex
	int weight;	// edge weight
} Edge;

#endif // !__EDGE_H__

