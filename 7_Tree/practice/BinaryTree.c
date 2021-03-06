#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newTree = (BTreeNode*)malloc(sizeof(BTreeNode));
	newTree->left = NULL;
	newTree->right = NULL;
	return newTree;
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
void MakeLeftSubTree(BTreeNode* main,BTreeNode* sub){
	DeleteTree(main->left);
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main,BTreeNode* sub)
{	
	DeleteTree(main->right);
	main->right = sub;
}
void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	action(bt);
	PreorderTraverse(bt->left,action);
	PreorderTraverse(bt->right,action);
}
void InorderTraverse(BTreeNode* bt,VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left,action);
	action(bt);
	InorderTraverse(bt->right,action);

}
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	PostorderTraverse(bt->left,action);
	PostorderTraverse(bt->right,action);
	action(bt);
}
void deleteNode(BTreeNode* delNode)
{
	printf("del tree data : %d\n",delNode->data);
	delNode->data = 0;
	delNode->left = NULL;
	delNode->right = NULL;
	
	free(delNode);
}
void DeleteTree(BTreeNode* bt)
{
	PostorderTraverse(bt,deleteNode);
}
