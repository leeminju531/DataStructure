#include "BinarySearchTree.h"
#include "BinaryTree2.h"
#include <stdio.h>

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
		*pRoot = nNode;
	}
}
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{

}