#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__


#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char* HData;
/*
ADT : 
if the d1 priority higher than d2, return value more than 0
if the d1 priority lower thatn d2, return value less than 0
if the d1 priority eqaul to d2, return 0 
*/
typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);


#endif
