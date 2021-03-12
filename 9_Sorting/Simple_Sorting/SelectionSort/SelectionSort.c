#include <stdio.h>

void SelSort(int arr[],int length)
{
	// *********** my code ****************
	// for (int i=0;i<length;i++)
	// {
	// 	for(int j=i;j<length;j++)
	// 	{
	// 		if(arr[i] > arr[j] )
	// 		{
	// 			int temp = arr [j];
	// 			arr[j] = arr[i];
	// 			arr[i] = temp;
	// 		}

	// 	}
	// }


	for(int i=0; i<length-1; i++)
	{
		int maxIdx = i;
		for(int j= i+1;j<length;j++)
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		int temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}

}

int main(void)
{
	int arr[4] = {3,4,2,1};

	SelSort(arr,sizeof(arr)/sizeof(int));

	for(int i=0;i<4;i++)
		printf("%d ",arr[i]);

	printf("\n");
	return 0;
}