#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);		// Tree Node ����
BTData GetData(BTreeNode * bt);			// node�� data ��ȯ
void SetData(BTreeNode * bt, BTData data);	// node�� data ����

BTreeNode * GetLeftSubTree(BTreeNode * bt);		// ���� �ڽ��� �ּҰ� ����
BTreeNode * GetRightSubTree(BTreeNode * bt);		// ������ �ڽ��� �ּҰ� ����

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);		// �θ� ���� �ڽ��� ����
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);		// �θ� ������ �ڽ��� ����

#endif // !__BINARY_TREE_H__

