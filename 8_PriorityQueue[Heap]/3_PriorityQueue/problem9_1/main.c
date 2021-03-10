#include <stdio.h>
#include "PriorityQueue.h"
#include <string.h>

int DataPriorityComp(char* ch1,char* ch2)
{
	return strlen(ch2) - strlen(ch1);
}
int main(void)
{
	PQueue pq;
	PQueueInit(&pq,DataPriorityComp);

	PEnqueue(&pq,"asd");
	PEnqueue(&pq,"asde");
	PEnqueue(&pq,"asdqw");
	printf("%s \n",PDequeue(&pq));

	PEnqueue(&pq,"asd");
	PEnqueue(&pq,"asde");
	PEnqueue(&pq,"asdqw");
	printf("%s \n",PDequeue(&pq));

	while(!PQIsEmpty(&pq))
		printf("%s \n",PDequeue(&pq));

	return 0;

}