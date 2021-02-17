#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <stdio.h>
#include "Point.h"
#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

//typedef int LData; // nevertheless 'int', by doing typedef design 'LData' 
				   // easy to notify class structure !! 


typedef Point* LData;
typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;

}ArrayList;

typedef ArrayList List;

void ListInit(List* plist); // initial
void LInsert(List* plist, LData data); // data store

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist); // delete referenced data 
int LCount(List* plist); // return data count



#endif
