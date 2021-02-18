#include "ArrayList.h"
#include "stdlib.h"
int main(void)
{
	List list;
	ListInit(&list);


	LInsert(&list,MakeNameCard("leeminju","010-3132-7536"));
	LInsert(&list,MakeNameCard("choiwoojae","010-6229-6536"));
	LInsert(&list,MakeNameCard("yoonminsick","010-8640-1843"));

	NameCard* card;
	if(LFirst(&list,&card))
	{
		ShowNameCardInfo(card);
		while(LNext(&list,&card))	ShowNameCardInfo(card);
	}

	if(LFirst(&list,&card))
	{
		if(NameCompare(card,"yoonminsick") == 0)
			ChangePhoneNum(card,"010-1234-5678");
		while(LNext(&list,&card))
			if(NameCompare(card,"yoonminsick") == 0)
				ChangePhoneNum(card,"010-1234-5678");
	}	



	if(LFirst(&list,&card))
	{
		if(NameCompare(card,"choiwoojae") == 0)
		{
			card = LRemove(&list);
			free(card);
		}
		while(LNext(&list,&card))
			if(NameCompare(card,"choiwoojae") == 0)
			{
				card = LRemove(&list);
				free(card);
			}


	}

	if(LFirst(&list,&card))
	{
		ShowNameCardInfo(card);
		while(LNext(&list,&card))	ShowNameCardInfo(card);
	}


}