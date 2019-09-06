#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);		// Tree Node 생성
BTData GetData(BTreeNode * bt);			// node의 data 반환
void SetData(BTreeNode * bt, BTData data);	// node의 data 설정

BTreeNode * GetLeftSubTree(BTreeNode * bt);		// 왼쪽 자식의 주소값 받음
BTreeNode * GetRightSubTree(BTreeNode * bt);		// 오른쪽 자식의 주소값 받음

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);		// 부모에 왼쪽 자식을 만듬
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);		// 부모에 오른쪽 자식을 만듬

#endif // !__BINARY_TREE_H__

