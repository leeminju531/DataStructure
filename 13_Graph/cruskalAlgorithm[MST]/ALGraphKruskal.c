#include "ALGraphKruskal.h"
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
int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
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


	PQueueInit(&(pg->pqueue),PQWeightComp);
}

void GraphDestroy(ALGraph* pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg,int fromV, int toV, int weight)
{
	// not orientation graph 
	LInsert(&(pg->adjList[fromV]) , toV);
	LInsert(&(pg->adjList[toV]) , fromV);
	pg->numE += 1;

	Edge edge = {fromV,toV,weight};
	PEnqueue(&(pg->pqueue),edge);
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
/*ConKruskalMST constructor function*/
void RemoveWayEdge(ALGraph* pg,int fromV,int toV)
{
	int edge;

	if(LFirst(&(pg->adjList[fromV]),&edge))
	{
		if(edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}
		while(LNext(&(pg->adjList[fromV]),&edge))
		{
			if(edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}


void RemoveEdge(ALGraph* pg, int fromV, int toV)
{
	RemoveWayEdge(pg,fromV,toV);
	RemoveWayEdge(pg,toV,fromV);
	(pg->numE)--;
}

void RecoverEdge(ALGraph* pg,int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]) , toV);
	LInsert(&(pg->adjList[toV]) , fromV);
	(pg->numE)++;
}

int IsConnVertex(ALGraph* pg, int v1,int v2)
{
	Stack stack;
	StackInit(&stack);

	int visitV = v1;
	VisitVertex(pg,visitV);
	SPush(&stack,visitV);

	int nextV;
	while(LFirst(&(pg->adjList[visitV]),&nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if(nextV == v2)
		{
			memset(pg->visitInfo, 0 , sizeof(int) * pg->numV);
			return TRUE;
		}

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
				if(nextV == v2)
				{
					memset(pg->visitInfo, 0 , sizeof(int) * pg->numV);
					return TRUE;
				}

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
			if(SIsEmpty(&stack))
				break;
			else
				visitV = SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0 , sizeof(int) * pg->numV);
	return FALSE;
}

void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20]; 
	Edge edge;
	int eidx = 0;

	while(pg->numE+1 > pg->numV) // MST Edge num + 1 = vertex num
	{
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg,edge.v1,edge.v2);

		if( !IsConnVertex(pg, edge.v1, edge.v2)) // check function whether two vertex connected or not
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}
	for(int i=0; i<eidx ; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while(!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf("(%c - %c), w: %d\n",edge.v1+65,edge.v2+65,edge.weight);
	}
}