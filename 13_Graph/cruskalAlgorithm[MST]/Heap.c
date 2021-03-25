#include "Heap.h"

void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
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

int GetHiPriChildIDX(Heap* ph,int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if(ph->comp( ph->heapArr[GetLChildIDX(idx)] ,
		 ph->heapArr[GetRChildIDX(idx)]) < 0 )
			return GetRChildIDX(idx);
		else 
			return GetLChildIDX(idx);
	}

}



void HInsert(Heap* ph,HData data)
{
	int idx = ph->numOfData+1;

	int childIdx = idx;
	while(childIdx != 1)
	{	
		if(ph->comp(ph->heapArr[GetParentIDX(childIdx)],
			data ) < 0 )
		{
			ph->heapArr[childIdx] = ph->heapArr[GetParentIDX(childIdx)];
			childIdx = GetParentIDX(childIdx);
		}
		else
		{
			break;
		}
	}
	
	ph->heapArr[childIdx] = data;
	ph->numOfData += 1;

}

HData HDelete(Heap* ph)
{
	HData retData = ph->heapArr[1];
	HData lastData = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;
	while(childIdx = GetHiPriChildIDX(ph,parentIdx))
	{
		if(ph->comp(lastData,ph->heapArr[childIdx]) < 0)
		{
			ph->heapArr[parentIdx] = ph->heapArr[childIdx];
			parentIdx = childIdx;
		}
		else
		{
			break;
		}	
	}

	ph->heapArr[parentIdx] = lastData;
	ph->numOfData -= 1;

	return retData;
		
}
