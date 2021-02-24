#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1,int d2)
{
	if(d1<d2)
		return 0;
	else
		return 1;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list,WhoIsPrecede);

	LInsert(&list,11);LInsert(&list,11);
	LInsert(&list,22);LInsert(&list,22);
	LInsert(&list,33);

	printf("data count : %d \n",LCount(&list));
	// list data print
	if(LFirst(&list,&data))
	{
		printf("%d ",data);

		while(LNext(&list,&data))
			printf("%d ",data);
	}
	printf("\n\n");

	// search 22 val and delete
	if(LFirst(&list,&data))
	{
		if(data == 22)
			LRemove(&list);

		while(LNext(&list,&data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	printf("data count : %d \n",LCount(&list));

	// list data print
	if(LFirst(&list,&data))
	{
		printf("%d ",data);

		while(LNext(&list,&data))
			printf("%d ",data);
	}
	printf("\n\n");


	return 0;

}