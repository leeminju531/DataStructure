#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*"; // postFix input

	BTreeNode* eTree = MakeExpTree(exp);

	printf("Prefix Notation : ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("Infix Notation : ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("Postfix Notation : ");
	ShowPostfixTypeExp(eTree); printf("\n");

	return 0;
}