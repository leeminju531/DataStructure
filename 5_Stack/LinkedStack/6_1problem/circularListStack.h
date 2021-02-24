#ifndef __CIRCLE_STACK_H__
#define __CIRCLE_STACK_H__

#include "CLinkedList.h"
typedef CList Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, Data data);

Data SPop(Stack* pstack);

Data SPeek(Stack* pstack);
#endif