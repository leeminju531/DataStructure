#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10 // << Decimical Num

// Radix Sort -> developer have to know detailng data info

void RadixSort(int arr[], int num,int maxLen)
{
	Queue buckets[BUCKET_NUM];

	int divfac = 1;

	for(int i=0;i<BUCKET_NUM;i++)
		QueueInit(&buckets[i]);

	for(int pos=0;pos<maxLen;pos++)
	{
		for(int di=0;di<num;di++)
		{
			// number of N position
			int radix = (arr[di] / divfac) % 10;
			Enqueue(&buckets[radix],arr[di]);
		}
		divfac *= 10;
		
		for(int bi=0,idx=0 ;bi<BUCKET_NUM;bi++)
		{
			while(!QIsEmpty(&buckets[bi]))
				arr[idx++] = Dequeue(&buckets[bi]);
		}
	}
	
}

int main(void)
{
	int arr[] = {13,212,14,7141,10987,6,15};

	int len = sizeof(arr)/sizeof(arr[0]);
	RadixSort(arr,len,5);

	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}