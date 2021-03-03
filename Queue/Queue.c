#include <stdio.h>
#include <stdlib.h>

#include "./../../include/Queue.h"



// constructors
Queue * createQueue(){

	Queue * tempQueue = malloc(sizeof(Queue));
	tempQueue->numOfNodes = 0;
	tempQueue->firstNode = NULL;
	tempQueue->lastNode = NULL;

	return tempQueue;

}


queueNode * create_queueNode(void * data){

	queueNode * node = malloc(sizeof(queueNode));
	node->data = data;
	node->nextNode = NULL;
	node->prevNode = NULL;
	return node;
}

// insertion function
int QueuePush(Queue * queue,void * data){

	queueNode * newNode = create_queueNode(data);

	if(queue->firstNode==NULL){
		queue->firstNode = newNode;
		queue->lastNode = newNode;
	}else{
		queue->lastNode->nextNode = newNode;
		newNode->prevNode = queue->lastNode;
		queue->lastNode = newNode;
	}

	queue->numOfNodes++;

	return NO_ERROR;
}

// geters
void * QueuePop(Queue * queue){

	queueNode * tempNode = queue->firstNode;

	if(queue->firstNode==NULL){
		return NULL;
	}else{

		queueNode * tempNode = queue->firstNode;
		queue->firstNode = tempNode->nextNode;
		if(queue->firstNode != NULL)
			queue->firstNode->prevNode = NULL;
	}

	queue->numOfNodes--;
	void * data = tempNode->data;
	free(tempNode);

	return data;
}

int emptyQueue(Queue * queue){
	return (queue->numOfNodes == 0 ? 1:0);
}


// destructors
int deleteQueue(Queue * queue){
	queueNode * tempNode = queue->firstNode,*rmNode;
	while(tempNode!=NULL){
		rmNode = tempNode;
		tempNode = tempNode->nextNode;
		free(rmNode);
	}
	free(queue);

	return NO_ERROR;
}