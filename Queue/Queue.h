#pragma once

#include <stdio.h>

#define NO_ERROR 1
#define ERROR -1

typedef struct queueNode queueNode;

typedef struct queueNode{
	
	void * data;
	queueNode * nextNode;
	queueNode * prevNode;
		
}queueNode;

typedef struct Queue{

	queueNode * firstNode;
	queueNode * lastNode;
	int numOfNodes;

} Queue;

/*----------- List utilities --------------*/

// constructors
Queue * createQueue();
queueNode * create_queueNode(void * data);

// insertion functions
int QueuePush(Queue * queue,void * data);

// geters
void * QueuePop(Queue * queue);

int emptyQueue(Queue * queue);

// destructors
int deleteQueue(Queue * queue);

