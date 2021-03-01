#include "PostCalculator.h"
#include "ListBaseStack.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int EvalRPNExp( char exp[])
{
	Stack stack;
	StackInit(&stack);

	int expLen = strlen(exp);

	for (int i=0;i<expLen;i++)
	{
		char tok = exp[i];
		if(isdigit(tok))
		{//✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶
		 // for calulate 'char' type, minus '0'	
			SPush(&stack,tok - '0'); 
			continue;
		}
		else
		{
			char op2 = SPop(&stack);
			char op1 = SPop(&stack);
			switch(exp[i])
			{
				case '+':
					SPush(&stack,op1+op2);

					break;
				case '-':
					SPush(&stack,op1-op2);
					break;
				case '*':
					SPush(&stack,op1*op2);
					break;
				case '/':
					SPush(&stack,op1/op2);
					break;
			}
		}
	}
	return (SPop(&stack));
}
