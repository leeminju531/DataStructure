#include <stdio.h>
#include "BinaryTree3.h"


int GetHeight(BTreeNode* bst)
{
	int leftH;
	int rightH;

	if(bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode* bst)
{
	int lsh; // left subtree height
	int rsh; // right subtree height

	if(bst == NULL)
		return 0;
	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
}

BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode; // parent node
	BTreeNode* cNode; // child node

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// implementation LL Rotation
	ChangeLeftSubTree(pNode,GetRightSubTree(cNode));
	ChangeRightSubTree(cNode,pNode);
	// LL Rotation -> changed root node
	return cNode;
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode; // parent node
	BTreeNode* cNode; // child node

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(pNode, pNode);

	return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode,RotateRR(cNode));

	return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode,RotateLL(cNode));

	return RotateRR(pNode);
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if(hDiff > 1) // LL or LR State
	{
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}
	if(hDiff < -1) // RR or RL state
	{
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	return *pRoot;
}