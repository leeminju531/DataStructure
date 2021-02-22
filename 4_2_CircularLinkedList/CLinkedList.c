#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	// if Init Node,
	if(plist -> tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
	

	}
	(plist->numOfData)++
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	// if Init Node,
	if(plist -> tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{

	}
	(plist->numOfData)++
}