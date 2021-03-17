#include <stdio.h>

int BSearchRecur(int arr[],int first,int last,int target)
{
	if(first>last)
		return -1;
	int middle = (first+last)/2;
	
	if(arr[middle] == target)
		return middle;
	else if(arr[middle] > target)
		return BSearchRecur(arr,first,middle-1,target);
	else 
		return BSearchRecur(arr,middle+1,last,target);

}

int main(void)
{
	int arr[] = {1,3,4,7,9};
	int idx = BSearchRecur(arr,0,4,7);

	if(idx == -1)
		printf("Searching Fail\n");
	else
		printf(" Target Index : %d\n",idx);

	idx = BSearchRecur(arr,0,4,10);
	if(idx == -1)
		printf("Searching Fail\n");
	else
		printf(" Target Index : %d\n",idx);

	return 0;
}