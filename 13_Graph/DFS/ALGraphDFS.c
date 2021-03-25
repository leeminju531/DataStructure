#include "ALGraphDFS.h"
#include <string.h>
#include "ArrayBaseStack.h"
#include <stdio.h>
#include "DLinkedList.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int WhoIsPrecede(int data1, int data2)
{
	if(data1 < data2)
		return 0;
	else
		return 1;
}

void GraphInit(ALGraph* pg,int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*) malloc(sizeof(List)*nv);
	for(int i=0;i<nv;i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]),WhoIsPrecede);
	}

	pg->visitInfo = (int*) malloc(sizeof(int) * nv);
	memset(pg->visitInfo,0,sizeof(int) * nv);
}

void GraphDestroy(ALGraph* pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg,int fromV, int toV)
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

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) // '0'represent visit x  
	{
		pg->visitInfo[visitV] = 1; // visit 
		printf("%c ", visitV + 65);
		return TRUE;
	}
	
	return FALSE;
}

// vertex info printer based on DFS
void DFShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	StackInit(&stack);

	int visitV = startV;
	int nextV;

	VisitVertex(pg, visitV);
	SPush(&stack,visitV);

	while(LFirst(&(pg->adjList[visitV]),&nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if(VisitVertex(pg,nextV) == TRUE)
		{
			SPush(&stack,visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while(LNext(&(pg->adjList[visitV]),&nextV) == TRUE)
			{
				if(VisitVertex(pg,nextV) == TRUE)
				{
					SPush(&stack,visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}

		}

		if(visitFlag == FALSE) 
		{
			if(SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0 , sizeof(int) * pg->numV);

}