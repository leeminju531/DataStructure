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


	Node* dummy = (Node*)malloc(sizeof(Node));
	dummy->next = NULL;
	head = dummy;
	tail = dummy;
	while(1)
	{
		printf("input : ");
		scanf("%d",&readData);
		if(readData<1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode-> next = NULL;

		newNode->next = head;
		head = newNode;

	}
	printf("\n");

	printf(" linked list printer !\n");
	if(head->next = NULL)
		printf("not exist\n");
	else
	{
		cur = head;
		printf("%d ",cur->data);
		while(cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ",cur->data);
		}

	}
	printf("\n\n");

	if(head->next == NULL)
	{
		free(head);
		return 0;
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		

	}
	return 0;


}