#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode* bstRoot;
	BTreeNode* sNode; // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot,9);
	BSTInsert(&bstRoot,1);
	BSTInsert(&bstRoot,6);
	BSTInsert(&bstRoot,2);
	BSTInsert(&bstRoot,8);
	BSTInsert(&bstRoot,3);
	BSTInsert(&bstRoot,5);

	BSTShowAll(bstRoot);printf("\n");
	sNode = BSTRemove(&bstRoot,3);
	free(sNode);

	BSTShowAll(bstRoot);printf("\n");
	sNode = BSTRemove(&bstRoot,1);
	free(sNode);

	BSTShowAll(bstRoot);printf("\n");
	// sNode = BSTSearch(bstRoot,1);
	// if(sNode == NULL)
	// 	printf("searching fail\n");
	// else
	// 	printf("key value : %d\n",BSTGetNodeData(sNode));

	// sNode = BSTSearch(bstRoot,4);
	// if(sNode == NULL)
	// 	printf("searching fail\n");
	// else
	// 	printf("key value : %d\n",BSTGetNodeData(sNode));	

	// sNode = BSTSearch(bstRoot,6);
	// if(sNode == NULL)
	// 	printf("searching fail\n");
	// else
	// 	printf("key value : %d\n",BSTGetNodeData(sNode));

	// sNode = BSTSearch(bstRoot,7);
	// if(sNode == NULL)
	// 	printf("searching fail\n");
	// else
	// 	printf("key value : %d\n",BSTGetNodeData(sNode));

	return 0;
}