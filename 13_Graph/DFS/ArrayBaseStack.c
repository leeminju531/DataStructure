#include "ArrayBaseStack.h"
#include <stdlib.h>
#include <stdio.h>
void StackInit(Stack* pstack)
{
	pstack->topIndex = -1; // mean empty state
}

int SIsEmpty(Stack* pstack)
{
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}
 
void SPush(Stack* pstack,Data data)
{
	pstack->stackArr[++(pstack->topIndex)] = data;
}

Data SPop(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("stack Memory Error !");
		exit(-1); // exit function -> terminate process 
				  // and parameter - > can broadcast to parent process
	}
	int rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];

}

Data SPeek(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("stack Memory Error !");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}
