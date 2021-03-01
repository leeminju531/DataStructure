#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}
int DQIsEmpty(Deque* pdeq)
{
	if(pdeq->head == NULL)
		return TRUE;
	else 
		return FALSE;
}
void DQAddFirst(Deque* pdeq,Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(DQIsEmpty(pdeq))
	{	
		pdeq->head = newNode;
		pdeq->tail = newNode;
		// printf("1");

	}else
	{
		newNode->next = pdeq->head;
		pdeq->head->prev = newNode;
		pdeq->head = newNode;
		// printf("2");
	}
}

void DQAddLast(Deque* pdeq,Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(DQIsEmpty(pdeq))
	{	
		pdeq->head = newNode;
		pdeq->tail = newNode;

	}
	else
	{
		newNode->prev = pdeq->tail;
		pdeq->tail->next = newNode;
		pdeq->tail = newNode;

	}
}

Data DQRemoveFirst(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	Node* delNode = pdeq->head;
	Data rdata = delNode->data;

	pdeq->head = pdeq->head->next;
	
	// NOTE : 
	/*----------------------
	pdeq->head->prev = NULL  << my case
	------------------------*/
	
	if(pdeq->head == NULL)
		pdeq->tail = NULL;
	else 
		pdeq->head->prev = NULL;
	// << Right Answer

	// if pdeq->head == NULL then, cause segmentation fault( before my case )

	delNode->data = 0;
	delNode->next = NULL;
	delNode->prev = NULL;
	free(delNode);
	return rdata;
}

Data DQRemoveLast(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	Node* delNode = pdeq->tail;
	Data rdata = pdeq->tail->data;

	pdeq->tail = pdeq->tail->prev;
	

	// pdeq->tail->next = NULL;
	if(pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;


	delNode->data = 0;
	delNode->next = NULL;
	delNode->prev = NULL;
	free(delNode);
	return rdata;
}
Data DQGetFirst(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	return pdeq->head->data;
}
Data DQGetLast(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	return pdeq->tail->data;
}