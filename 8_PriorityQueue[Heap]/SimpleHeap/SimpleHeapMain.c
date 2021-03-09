#include "SimpleHeap.h"
#include <stdio.h>

int main(void)
{
	Heap heap;
	HeapInit(&heap);

	/*
		user assign priority each data-> generally bad case !
	*/


	HInsert(&heap,'A',1);
	HInsert(&heap,'B',2);
	HInsert(&heap,'C',3);
	printf("%c \n",HDelete(&heap));

	HInsert(&heap,'A',1);
	HInsert(&heap,'B',2);
	HInsert(&heap,'C',3);
	printf("%c \n",HDelete(&heap));

	while(!HIsEmpty(&heap))
		printf("%c \n",HDelete(&heap));

	return 0;



}