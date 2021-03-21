#include "BinaryTree3.h"
#include <stdio.h>
#include <stdlib.h>

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
BTData GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}
void MakeLeftSubTree(BTreeNode* main,BTreeNode* sub)
{
	/*
		travelsal delete left tree
	*/
	DeleteTree(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main,BTreeNode* sub)
{
	/*
		travelsal delete right tree
	*/
	DeleteTree(main->right);

	main->right = sub;
}
void ChangeLeftSubTree(BTreeNode* main,BTreeNode* sub)
{
	main->left = sub;
}
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}
BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* delNode;
	if(bt != NULL)
	{
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}
BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* delNode;
	if(bt != NULL)
	{
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}


void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left,action);
	PreorderTraverse(bt->right,action);
}
void InorderTraverse(BTreeNode* bt,VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left,action);
	action(bt->data);
	InorderTraverse(bt->right,action);
}

void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	PostorderTraverse(bt->left,action);
	PostorderTraverse(bt->right,action);
	action(bt->data);
}


/**********************************************
Delete Tree -> have to always Select PostOrderTraverse ! 
***********************************************/
void DeleteTree(BTreeNode* bt)
{
	if(bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del tree data :%d\n",bt->data);
	bt->data = 0;
	bt->left = NULL;
	bt -> right = NULL;
	free(bt);

}
