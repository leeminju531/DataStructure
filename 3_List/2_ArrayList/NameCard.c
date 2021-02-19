#include "NameCard.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* pNameCard = malloc(sizeof(NameCard));
	strcpy(pNameCard -> name ,name);
	strcpy(pNameCard -> phone , phone);
	// pNameCard -> name = name;
	// pNameCard -> phone = phone;

	return pNameCard;
}

void ShowNameCardInfo(NameCard* pcard)
{
	printf("name : %s \nPhone : %s \n",pcard -> name,pcard -> phone);
}

int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name , name);
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	// pcard->phone = phone;
	strcpy(pcard -> phone , phone);
}
