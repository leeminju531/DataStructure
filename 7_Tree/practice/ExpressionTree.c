#include "ExpressionTree.h"
#include "BinaryTree.h"
#include <string.h>
#include <stdio.h>
#include "ListBaseStack2.h"
#include <ctype.h>

BTreeNode* MakeExpTree(char exp[])
{
	int explen = strlen(exp);
	Stack stack;
	StackInit(&stack);

	for (int i =0;i<explen;i++)
	{
		BTreeNode* bt = MakeBTreeNode();
	
		if(isdigit(exp[i]))
		{
			SetData(bt,exp[i]-'0');
		}
		else
		{
			MakeRightSubTree(bt,SPop(&stack));
			MakeLeftSubTree(bt,SPop(&stack));
			SetData(bt,exp[i]);
		}
		SPush(&stack,bt);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	return 0;
}
void ShowNodeData(BTreeNode* bt)
{
	int data = bt->data;
	if(data >=0 && data<=9)
		printf("%d ",data);
	else
		printf("%c ",data);
}
void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt,ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt,ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt,ShowNodeData);
}
