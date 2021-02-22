#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int data;
	struct _node* next;
}Node;

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	// this is dummy node !!
	head = (Node*)malloc(sizeof(Node));
	tail = head;

	while(1)
	{
		printf("input : ");
		scanf("%d",&readData);
		if(readData<1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode-> next = NULL;
		/*
		if(head == NULL)
		{
			tail = newNode;
			head = newNode;
		}else
		{
			newNode->next = head;
			head = newNode;
		}
		*/
		tail->next = newNode;
		tail = newNode;
		

	}
	printf("\n");

	printf(" linked list printer !\n");
	
	if(head == tail)
		printf("not exist\n");
	else
	{
		cur = head;
		// printf("%d ",cur->data);
		while(cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ",cur->data);
		}

	}
	printf("\n\n");

	if(head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;


		// printf("%d deleted \n",head->data);
		// free(delNode);
		while(delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNode->next;

			printf("%d deleted\n",delNode->data);
			free(delNode);
		}
	}
	return 0;
}