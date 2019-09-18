#ifndef __BINARY_SEARCH_TREE3_H__
#define __BINARY_SEARCH_TREE3_H__

#include "BinaryTree3.h"

typedef BTData BSTData;

// BinarySearchTree의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst);

// BST에 데이터 저장
BTreeNode * BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST에서 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// BST에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode * bst);

#endif // !__BINARY_SEARCH_TREE2_H__

