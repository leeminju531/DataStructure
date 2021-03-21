#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode* avlRoot;
	BTreeNode* clNode; // current left node
	BTreeNode* crNode; // current right node

	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot,1);BSTInsert(&avlRoot,2);BSTInsert(&avlRoot,3);
	BSTInsert(&avlRoot,4);BSTInsert(&avlRoot,5);BSTInsert(&avlRoot,6);
	BSTInsert(&avlRoot,7);BSTInsert(&avlRoot,8);BSTInsert(&avlRoot,9);

	printf("root node : %d\n",GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("left 1 : %d, right 1 : %d \n",GetData(clNode),GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("left 2 : %d, right 2 : %d \n",GetData(clNode),GetData(crNode));


	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("left 3 : %d, right 3 : %d \n",GetData(clNode),GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("left 4 : %d, right 4 : %d \n",GetData(clNode),GetData(crNode));




	return 0;
}