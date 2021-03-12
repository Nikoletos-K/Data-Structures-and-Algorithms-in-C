#include <stdio.h>
#include <stdlib.h>

#include "./../../include/List.h"

List * createList(){

	List * tempList = malloc(sizeof(List));
	tempList->numOfNodes = 0;
	tempList->firstNode = NULL;
	tempList->lastNode = NULL;

	return tempList;
}

listNode * create_listNode(void * data){

	listNode * node = malloc(sizeof(listNode));
	node->data = data;
	node->nextNode = NULL;
	node->prevNode = NULL;
	return node;
}

int insert_toList(List * list,void * data){		// insertion is done at the end of the list O(1)

	listNode * newNode = create_listNode(data);

	if(list->firstNode==NULL){
		list->firstNode = newNode;
		list->lastNode = newNode;
	}else{
		list->lastNode->nextNode = newNode;
		newNode->prevNode = list->lastNode;
		list->lastNode = newNode;

	}

	list->numOfNodes++;

	return NO_ERROR;
}

int deleteList(List * list){

	listNode * tempNode = list->firstNode,*rmNode;
	while(tempNode!=NULL){
		rmNode = tempNode;
		tempNode = tempNode->nextNode;
		if(rmNode!=NULL)	
			free(rmNode);
	}
	free(list);

	return NO_ERROR;
}

int get_numOfNodes(List * list){
	return list->numOfNodes;
}

void * getData_fromList(List * list,int index){		// returns the saved data from a list node at position "index"

	listNode * tempNode = list->firstNode;
	int i=0;
	while(tempNode!=NULL && (i++)<index)
		tempNode = tempNode->nextNode;

	return tempNode->data;
}

void * findValue(List * list,void * value,int (*comparator)(void*,void*)){	// searches the list until finding "value"

	listNode * tempNode = list->firstNode;
	while(tempNode!=NULL && !(*comparator)(tempNode->data,value))
		tempNode = tempNode->nextNode;

	return tempNode->data;
}


void printList(List * list,void (*printData)(void*)){

	listNode * tempNode = list->firstNode;

	while(tempNode!=NULL){
		printData(tempNode->data);
		tempNode = tempNode->nextNode;
	}
}

int oneNodeList(List * list){
	return (list->numOfNodes==1);
}

List * mergeLists(List * list1,List * list2){

	list1->lastNode->nextNode = list2->firstNode;
	list1->lastNode = list2->lastNode;
	list1->numOfNodes += list2->numOfNodes;
	list2 = NULL;

	return list1;
}

int get_listSize(List * list){ return list->numOfNodes;};
