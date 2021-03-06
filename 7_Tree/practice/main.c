#include <stdio.h>
#include "InfixToPostfix.h"

#define INPUT_LEN 100

int main(void)
{
	char input[INPUT_LEN];
	printf("Input Infix Notation : ");
	scanf("%s",input);

	ConvToRPNExp(input); // chang infix input-> postfix
	printf(" postfix Notation : %s",input);

	return 0;
}

