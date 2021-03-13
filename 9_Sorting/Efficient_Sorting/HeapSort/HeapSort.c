#include <stdio.h>
#include "Heap.h"

int PriComp(int n1,int n2)
{
	return n2-n1; // ascending 
}

void HeapSort(int arr[],int length, PriorityComp pc)
{
	Heap heap;
	HeapInit(&heap,pc);

	for(int i=0;i<length;i++)
		HInsert(&heap,arr[i]);

	for(int i=0;i<length;i++)
		arr[i] = HDelete(&heap);
}



int main(void)
{
	int arr[] = {3,4,2,1};

	HeapSort(arr,sizeof(arr)/sizeof(arr[0]),PriComp);

	for(int i=0;i<4;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}