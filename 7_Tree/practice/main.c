#include <stdio.h>
#include "InfixToPostfix.h"
#include "BinaryTree.h"
#include "ExpressionTree.h"

#define INPUT_LEN 100

int main(void)
{
	char input[INPUT_LEN];
	printf("Input Infix Notation : ");
	scanf("%s",input);

	ConvToRPNExp(input); // chang infix input-> postfix
	BTreeNode* eTree = MakeExpTree(input);

	ShowPrefixTypeExp(eTree);printf("\n");
	ShowInfixTypeExp(eTree);printf("\n");
	ShowPostfixTypeExp(eTree);printf("\n");


	return 0;
}

