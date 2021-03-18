#include "BinarySearchTree.h"
#include "BinaryTree3.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL; // parent Node
	BTreeNode* cNode = *pRoot; //current Node
	

	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return; // key's unique value

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	BTreeNode* newNode = MakeBTreeNode();
	SetData(newNode,data);

	if(pNode != NULL)
	{
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode,newNode);
		else
			MakeRightSubTree(pNode,newNode);
	}
	else
	{
		*pRoot = newNode;
	}
}
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst; // curent node
	BSTData cd; // current data 

	while(cNode != NULL)
	{
		cd = GetData(cNode);
		if(target == cd)
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else 
			cNode = GetRightSubTree(cNode);
	}
	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode(); // virtual root node
	BTreeNode* pNode = pVRoot; // parent node;
	BTreeNode* cNode = *pRoot; // current node;
	BTreeNode* dNode; // delete node;

	ChangeRightSubTree(pVRoot,*pRoot);

	// searching target node
	while(cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);

	}
	if(cNode == NULL) // target data not exist in BST 
		return NULL;

	dNode = cNode;

	// case 1 : delete node is terminal node.
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if(GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	// case 2 : delete node has one child node.
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // pointer child node of (target Node will be deleted)

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode,dcNode);
		else
			ChangeRightSubTree(pNode,dcNode);
	}
	// case 3 : delete node has two child node.
	// -> can replace most larget value of left subtree of delNode 
	//    or most small value of right subtree of delNode.
	// let's use second choice.(regardless of first case)
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); //  node
		BTreeNode* mpNode = dNode; 
		int delData;

		// search replacing node
		while(GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode,GetData(mNode));

		if(GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode,GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mNode,GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode,delData);
	}

	// deleted node is root node case -> 
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);


	free(pVRoot); // virtual root free
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ",data);
}
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst,ShowIntData);
}