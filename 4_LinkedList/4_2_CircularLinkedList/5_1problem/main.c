#include "CLinkedList.h"
#include "Employee.h"
#include <stdio.h>
int Search(List* plist,char* name,int Afterday);

int main(void)
{
	List list;
	ListInit(&list);
	
	LInsert(&list,EmployeeSetting("leeminju",2016007129));
	LInsert(&list,EmployeeSetting("choiwoojae",165132));
	LInsert(&list,EmployeeSetting("yoonminsick",56451320));
	LInsert(&list,EmployeeSetting("gangmin",5646132));


	// one cycle printing
	int count = LCount(&list);
	Data data;
	if(count != 0)
	{
		LFirst(&list,&data);
		EmployeePrint(data);
		for(int i=0;i<count-1;i++)
			if(LNext(&list,&data))
				EmployeePrint(data);
	}

	if(Search(&list,"leeminju",9) == -1)
		printf(" empty name in list\n");



	return 0;
}

int Search(List* plist,char* name,int Afterday)
{
	// Searching 
	int count = LCount(plist);
	Data data;
	if(count != 0)
	{
		LFirst(plist,&data);
		if(EmployeeEqaul(name,data) == TRUE)
		{
			for(int i=0 ; i< Afterday;i++)
				LNext(plist,&data);

			EmployeePrint(data);

			return 0;

		}else
		{
			for(int i=0;i<count-1;i++)
				if(LNext(plist,&data))
					if(EmployeeEqaul(name,data) == TRUE)
					{
						for(int i=0 ; i< Afterday;i++)
							LNext(plist,&data);

						EmployeePrint(data);

						return 0;
					}





		}
		
	}
	return -1;
}