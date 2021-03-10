#include <stdio.h>

// Ascending Sort
void BubbleSort(int arr[],int length)
{
	for(int i=0;i<length -1	; i++)
	{
		for(int j=0;j<length-i-1;j++ )
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[4] = {3,2,4,1};

	BubbleSort(arr, sizeof(arr)/sizeof(int));

	for (int i=0; i<4 ; i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}