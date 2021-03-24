#include "ALGraph.h"
#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int WhoIsPrecede(int data1, int data2);

// graph initialize
void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*) malloc (sizeof(List) * nv);

	for(int i=0;i<nv;i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]),WhoIsPrecede);
	}
}

// resource release
void GraphDestroy(ALGraph* pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);
}

// add edge
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	// not orientation graph 
	LInsert(&(pg->adjList[fromV]) , toV);
	LInsert(&(pg->adjList[toV]) , fromV);
	pg->numE += 1;
}
// edge printer
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx; // store vertex

	for(int i=0;i<pg->numV;i++)
	{
		printf("%c Linked Vertesx : ",i + 65);
		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ",vx + 65);
			while(LNext(&(pg->adjList[i]),&vx))
				printf("%c ",vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if(data1 < data2)
		return 0;
	else
		return 1;
}