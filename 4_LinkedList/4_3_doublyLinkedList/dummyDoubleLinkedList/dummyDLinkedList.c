#include "dummyDLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
	//Dummy node
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head; 

	plist->numOfData = 0;
}

void LInsert(List* plist,Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	newNode->next = plist->tail;
	plist->tail->prev->next = newNode;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

//printing start : head
int LFirst(List* plist, Data* pdata)
{
	if(plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	Data rdata = plist->cur->data;

	Node* rpos = plist->cur;
	plist->cur = plist->cur->prev;

	rpos->data = 0;
	rpos->prev = NULL;
	rpos->next = NULL;
	free(rpos);
	
	(plist->numOfData)--;

	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}