#include "ArrayList.h"

int main(void)
{
	List list;
	int data;

	ListInit(&list);
	for(data=1;data<10;data++)
		LInsert(&list,data);

	int sum = 0;
	if(LFirst(&list,&data))
	{
		sum += data;
		while(LNext(&list,&data))	sum += data;
	}
	printf("sum : %d\n",sum);


	if(LFirst(&list,&data))
	{
		if(data %2 == 0 || data % 3 == 0) LRemove(&list);

		while(LNext(&list,&data))
			if(data %2 == 0 || data % 3 == 0) 
				LRemove(&list);

	}

	if(LFirst(&list,&data))
	{
		printf("%d ",data);
		while(LNext(&list,&data))	printf("%d ",data);
	}
	printf("\n");

	return 0;

}