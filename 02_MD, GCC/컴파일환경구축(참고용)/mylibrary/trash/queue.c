#include "queue.h"
QUEUE* createQueue(void)
{
	//Local Definitions
	QUEUE* queue;
	//Statements
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	} // if
	return queue;
} // createQueue

bool enqueue(QUEUE* queue, void* itemPtr)
{
	//Local Definitions
	QUEUE_NODE* newPtr;
	//Statements
	if (!(newPtr =
		(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))))
		return false;
	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;
	if (queue->count == 0)
		// Inserting into null queue
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;
	(queue->count)++;
	queue->rear = newPtr;
	return true;
} // enqueue

bool dequeue(QUEUE* queue, void** itemPtr)
{
	//Local Definitions
	QUEUE_NODE* deleteLoc;
	//Statements
	if (!queue->count)
		return false;
	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;
	if (queue->count == 1)
		// Deleting only item in queue
		queue->rear = queue->front = NULL;
	else
		queue->front = queue->front->next;
	(queue->count)--;
	free(deleteLoc);
	return true;
} // dequeue

bool queueFront(QUEUE* queue, void** itemPtr)
{
	//Statements
	if (!queue->count)
		return false;
	else
	{
		*itemPtr = queue->front->dataPtr;
		return true;
	} // else
} // queueFront

bool queueRear(QUEUE* queue, void** itemPtr)
{
	//Statements
	if (!queue->count)
		return true;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return false;
	} // else
} // queueRear

bool emptyQueue(QUEUE* queue)
{
	//Statements
	return (queue->count == 0);
} // emptyQueue

bool fullQueue(QUEUE* queue)
{
	QUEUE_NODE* temp;
	//Statements
	temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));
	if (temp)
	{
		free(temp);
		return true;
	} // if
	// Heap full
	return false;
} // fullQueue

int queueCount(QUEUE* queue)
{
	//Statements
	return queue->count;
} // queueCount

QUEUE* destroyQueue(QUEUE* queue)
{
	//Local Definitions
	QUEUE_NODE* deletePtr;
	//Statements
	if (queue)
	{
		while (queue->front != NULL)
		{
			free(queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->next;
			free(deletePtr);
		} // while
		free(queue);
	} // if
	return NULL;
}
