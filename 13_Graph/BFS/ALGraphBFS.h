#ifndef __AL_GRAPH_BFS__
#define __AL_GRAPH_BFS__

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J}; // vertex name

typedef struct _ual
{
	int numV;
	int numE;
	List* adjList;
	int* visitInfo; // for store searching vertex 
} ALGraph;

void GraphInit(ALGraph* pg,int nv);

void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg,int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph* pg);

// vertex info printer based on BFS
void BFShowGraphVertex(ALGraph* pg, int startV);



#endif
