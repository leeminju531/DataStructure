#include "CLinkedList.h"
#include "circularListStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack* pstack)
{
	ListInit(pstack);
}

int SIsEmpty(Stack* pstack)
{
	if(LCount(pstack) == 0)
		return TRUE;
	else 
		return FALSE;
}
void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack,data);
}

Data SPop(Stack* pstack)
{
	if(LCount(pstack) == 0)
	{
		printf("Stack Memory Error !");
		exit(-1);
	}
	Data rdata;
	LFirst(pstack,&rdata);
	LRemove(pstack);

	return rdata;
}

Data SPeek(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	Data rdata;
	LFirst(pstack,&rdata);
	return rdata;

}