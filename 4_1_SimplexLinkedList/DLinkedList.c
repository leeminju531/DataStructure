#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // dumy node 
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
	
}


void LInsert(List* plist,LData data)
{
	if(plist->comp == NULL)
		FInsert(plist,data);
	else
		SInsert(plist,data);
}
//insert node to starting point. (like to Stack data Structure)
void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

//insert node used to Sorting
void SInsert(List* plist, LData data)
{
	Node* newNode =(Node*)malloc(sizeof(Node));
	newNode->data = data;
	Node* pred = plist->head; // pred is pointing to dummy node

	//search new node position
	while(pred->next != NULL && plist->comp(data,pred->next->data) !=0 )
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;

}

int LFirst(List* plist, LData* pdata)
{
	if(plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head; // point to dummy node 
	plist->cur = plist->head->next; // point to start node

	*pdata = plist->cur->data;		// store data at start node LData
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if(plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
// 'pos' is predication, mean 'position'
// so 'rpos' -> remove position !! 
LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}

void SetSortRule(List* plist,int (*comp)(LData d1,LData d2))
{
	plist -> comp = comp; // initialize comp function in LinkedList struct.
}