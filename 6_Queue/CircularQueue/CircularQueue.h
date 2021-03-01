#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
	int front; // mean F
 	int rear;  // mean R
 	Data queArr[QUE_LEN];
} CQueue;


typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);
int QIsFull(Queue* pq);

void Enqueue(Queue* pq,Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);


#endif
