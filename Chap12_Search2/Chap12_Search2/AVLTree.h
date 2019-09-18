#ifndef __BINARY_SEARCH_TREE3_H__
#define __BINARY_SEARCH_TREE3_H__

#include "BinaryTree3.h"

typedef BTData BSTData;

// BinarySearchTree�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// BST�� ������ ����
BTreeNode * BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST���� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// BST�� ����� ��� ����� ������ ���
void BSTShowAll(BTreeNode * bst);

#endif // !__BINARY_SEARCH_TREE2_H__

