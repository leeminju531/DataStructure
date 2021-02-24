#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	Stack stack;
	StackInit(&stack);
	//SPop(&stack); -> process terminate bcuz exit func
	SPush(&stack,1);SPush(&stack,2);
	SPush(&stack,3);SPush(&stack,4);
	SPush(&stack,5);

	while(!SIsEmpty(&stack))
		printf("%d ",SPop(&stack));

	printf("\ndd\n");
	return 0;
}