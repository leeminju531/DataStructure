#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J}; // vertex name

typedef struct _ual
{
	int numV; // vertex number
	int numE; // edge number
	List* adjList;
} ALGraph;

// graph initialize
void GraphInit(ALGraph* pg, int nv);

// resource release
void GraphDestroy(ALGraph* pg);

// add edge
void AddEdge(ALGraph* pg, int fromV, int toV);

// edge printer
void ShowGraphEdgeInfo(ALGraph* pg);
#endif
