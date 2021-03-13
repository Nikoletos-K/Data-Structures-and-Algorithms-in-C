#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./../../include/maxHeap.h"

/* -------------- Constructors ----------------*/

Heap * heapConstruct(){

	Heap * heap = malloc(sizeof(Heap));
	heap->size = 0;
	heap->root = NULL;	
	
	return heap;

}

heapNode * create_heapNode(void * value){

	heapNode * newhn = malloc(sizeof(heapNode));
	newhn->value = value;
	newhn->leftChild = NULL;
	newhn->rightChild = NULL;
	newhn->parent = NULL;

	return newhn;
}

/*-------------- Heap utlilities -----------------------*/

void swap(heapNode * hn1,heapNode * hn2){

	void * tempValue = hn1->value;
	hn1->value = hn2->value;
	hn2->value = tempValue;

}
heapNode * getParent(heapNode * hn){ return hn->parent; }

void heapifyUp(Heap * heap,heapNode * hn,int (*comparator)(const void *,const void *)){		/* function that changes nodes from down to top of the tree in order to maintain max heap conditions*/
	
	if(hn->parent == NULL){		/* base case : when node is root */
		heap->root = hn;		/* inform root */
		return;
	}

	if((*comparator)(getParent(hn)->value,hn->value)<0){	/* if child value is greater that parents,swap nodes and recurcively fix the tree */
		swap(getParent(hn),hn);
		heapifyUp(heap,getParent(hn),comparator);
	}	
}

void heapifyDown(Heap * heap,heapNode * hn,int depth,int (*comparator)(const void *,const void *)){

	if(depth == (int)log2(heap->size))	/* base case: when depth reach leafs */
		return;
	
	/* first compare and find biger child */
	heapNode * bigerChild;
	if(hn->leftChild==NULL && hn->rightChild!=NULL)
		bigerChild = hn->rightChild;
	else if(hn->leftChild!=NULL && hn->rightChild==NULL)
		bigerChild = hn->leftChild;
	else if(hn->leftChild==NULL && hn->rightChild==NULL){
		return;
	}else if((*comparator)(hn->leftChild->value,hn->rightChild->value)>0)
		bigerChild = hn->leftChild;
	else
		bigerChild = hn->rightChild;

	/* and the compare choosen child with parent value */
	if((*comparator)(bigerChild->value,getParent(bigerChild)->value)>0){	// if greater -> swap
		swap(bigerChild,getParent(bigerChild));
		heapifyDown(heap,bigerChild,depth+1,comparator);		// recurcively
	}
}

void insert_toHeap(Heap * heap,void * value,int (*comparator)(const void *,const void *)){

	if(heap->size==0){		// if heap is empty - first insertion
		heap->root = create_heapNode(value);
		heap->size++;
		return;
	}

	heapNode * posHN = heap->root;
	heapNode *newhn= create_heapNode(value),* tempHn;
	heap->size++;
	int size=heap->size;
	unsigned int height = log2(size);	// tree height: log2(treeSize)
	unsigned int guide = size;

	while(height>0){		/* finding path by taking current_heapSize+1 number into binary and reading it*/ 

		guide = size;
		guide = guide >> (height-1);	// shift right to isolate #height least significant bit
		guide = guide << 31;			// bringing it back
		guide = guide >> 31;			// and isolate this bit to the "0" binary position
		
		tempHn = posHN;
		if(guide == RIGHT)		// if bit is 1 -> go right
			posHN = posHN->rightChild;
		else	// if bit is 0 -> go left
			posHN = posHN->leftChild;

		height--;	// loop until reaching leafs
	}	
	
	if(guide == RIGHT)	// link parent with new node
		tempHn->rightChild = newhn;
	else
		tempHn->leftChild = newhn;
	
	newhn->parent = tempHn;

	heapifyUp(heap,newhn,comparator);	// maintain heap coditions until root
}

void * extractMax_fromHeap(Heap * heap,int (*comparator)(const void *,const void *)){

	if(heap==NULL)
		return NULL;

	if(heap->size==1){		// if extracting the last node
		heap->size--;
		void * temp = heap->root->value ;
		free(heap->root);
		return temp;
	}

	void * returnedValue = heap->root->value;
	unsigned int guide;
	int size=heap->size;
	heapNode * posHN = heap->root;	
	unsigned int height = log2(size);

	guide = size;

	// same as insertion 
	while(height>0){

		guide = size;
		guide = guide >> (height-1);
		guide = guide << 31;
		guide = guide >> 31;
		
		if(guide == RIGHT)
			posHN = posHN->rightChild;
		else
			posHN = posHN->leftChild;
		
		height--;
	}	

	swap(heap->root,posHN);	// swap tha last elements value with root,because root will be extracted
	destroyNode(posHN,guide,heap);
	heapifyDown(heap,heap->root,0,comparator);	// fix any violations until leaf nodes

	return returnedValue;
}

/*------------------------ Destructors ----------------------------------*/

void destroyNode(heapNode * rmNode,int leftORright,Heap * heap){

	leftORright==LEFT ? (getParent(rmNode)->leftChild = NULL) : (getParent(rmNode)->rightChild = NULL); 
	free(rmNode);
	heap->size--;
}

void destroyHeap(Heap * heap){ 
	if(heap!=NULL) free(heap);	
	heap = NULL;
}