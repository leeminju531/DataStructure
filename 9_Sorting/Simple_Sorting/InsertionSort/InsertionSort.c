#include <stdio.h>

void InsertionSort(int arr[],int length)
{

	for(int i=1;i<length;i++)
	{
		int insData = arr[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(arr[j] > insData)
				arr[j+1]=arr[j];
			else 
				break;

		}
		arr[j+1]=insData;

	}

}

int main(void)
{
	int arr[5] = {5,3,2,4,1};

	InsertionSort(arr,sizeof(arr)/sizeof(arr[0]));

	for(int i=0;i<5;i++)
		printf("%d ",arr[i]);

	printf("\n");
	return 0;
}