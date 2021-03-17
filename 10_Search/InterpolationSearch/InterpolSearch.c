#include <stdio.h>

int ISearch(int arr[],int first,int last,int target)
{
	// if(first>last)
	// 	return -1;
	if(arr[first] > target || arr[last] < target)
		return -1;

	// defference point compare with BinarySearch
	int middle =( (double) (target-arr[first]) / (arr[last]-arr[first])*(last-first)) + first;
	
	if(arr[middle] == target)
		return middle;
	else if(arr[middle] > target)
		return ISearch(arr,first,middle-1,target);
	else 
		return ISearch(arr,middle+1,last,target);

}

int main(void)
{
	int arr[] = {1,3,4,7,9};
	int idx = ISearch(arr,0,4,7);

	if(idx == -1)
		printf("Searching Fail\n");
	else
		printf(" Target Index : %d\n",idx);

	idx = ISearch(arr,0,4,10);
	if(idx == -1)
		printf("Searching Fail\n");
	else
		printf(" Target Index : %d\n",idx);

	return 0;
}