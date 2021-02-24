#include <stdio.h>
#include "dummyDLinkedList.h"

int main(void)
{
	List list;
	Data data;
	ListInit(&list);

	LInsert(&list,1);LInsert(&list,2);
	LInsert(&list,3);LInsert(&list,4);
	LInsert(&list,5);LInsert(&list,6);
	LInsert(&list,7);LInsert(&list,8);

	//printing
	if(LFirst(&list, &data))
	{
		printf("%d ",data);

		while(LNext(&list,&data))
			printf("%d ",data);
	}
	printf("\n\n");

	//delete multiple of 2
	if(LFirst(&list,&data))
	{
		if(data%2 == 0)
			LRemove(&list);
		while(LNext(&list,&data))
		{
			if(data%2 == 0)
				LRemove(&list);
		}
	}


	//printing
	if(LFirst(&list, &data))
	{
		printf("%d ",data);

		while(LNext(&list,&data))
			printf("%d ",data);
	}
	printf("\n\n");

}