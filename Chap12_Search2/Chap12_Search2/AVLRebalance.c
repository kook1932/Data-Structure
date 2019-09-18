#include<stdio.h>
#include"BinaryTree3.h"

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode * bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)		// �ܸ� ��带 ������ ���� �� 0�� ����
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	// ū ���� ���̸� ��ȯ
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// �� ���� Ʈ���� ���� �μ�(���� ��)�� ��ȯ
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;	// left sub tree height
	int rsh;	// right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));		// ���� ���� Ʈ���� ����
	rsh = GetHeight(GetRightSubTree(bst));		// ������ ���� Ʈ���� ����
	return lsh - rsh;	// �����μ�
}

// LLȸ���� ����ϴ� �Լ�
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	// pNode�� cNode�� LLȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LLȸ���� ����ϴ� �� ���� ����
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LLȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� �� ��ȯ
	return cNode;
}

// RRȸ���� ����ϴ� �Լ�
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode�� cNode�� RRȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// ���� RRȸ���� ����ϴ� �� ���� ����
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	// RRȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� �� ��ȯ
	return cNode;
}

// LRȸ���� ����ϴ� �Լ�
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LRȸ���� ����ϴ� �� ���� ����
	ChangeLeftSubTree(pNode, RotateRR(cNode));	// �κ��� RRȸ��
	return RotateLL(pNode);
}

// RLȸ���� ����ϴ� �Լ�
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// ���� RLȸ���� ����ϴ� �� ���� ����
	ChangeRightSubTree(pNode, RotateLL(cNode));	// �κ��� LLȸ��
	return RotateRR(pNode);
}

// Ʈ���� ������ ����
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);	// ���� �μ� ���

	// ���� �μ��� +2 �̻��̸� LL���� �Ǵ� LR �����̴�
	if (hDiff > 1)		// ���� ���� Ʈ�� �������� ���̰� 2�̻� ũ�ٸ�
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	// ���� �μ��� -2 �����̸� RR���� �Ǵ� RL�����̴�
	if (hDiff < -1)
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}