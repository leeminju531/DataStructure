#include "SimpleHeap.h"

void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
}
int HIsEmpty(Heap* ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}
int GetParentIDX(int idx)
{
	return idx/2;
}
int GetLChildIDX(int idx)
{
	return idx*2;
}
int GetRChildIDX(int idx)
{
	return idx*2+1;
}
// return high priority child index of two child
// note : i set low priority pr value mean high priority
int GetHiPriChildIDX(Heap* ph,int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) 
			
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}

}


void HInsert(Heap* ph,HData data,Priority pr)
{

}