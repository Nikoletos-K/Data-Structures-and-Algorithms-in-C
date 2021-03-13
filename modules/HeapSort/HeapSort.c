#include <stdio.h>

#include "./../../include/HeapSort.h"

/* Recurcive - Generic implementation of heapsort */

// Exchange is a swap function
void exchange(void ** array,int pos1,int pos2){

	void * temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;

}

int getLeft(int i){ return 2*i;}

int getRight(int i){return 2*i+1;}

int getParent(int i){return i/2;}

void maxHeapify(void ** array,int heapSize,int i,int (*compare)(const void*,const void*)){	
	
	// Maintaining the heap property,while inserting a new element 

	int left = getLeft(i);
	int right = getRight(i);
	int largest;

	if(left<=heapSize && compare(array[left],array[i])>0) 
		largest = left;
	else
		largest = i;

	if(right <= heapSize && compare(array[right],array[largest])>0) 	// Largest must be the most right
		largest = right;

	if(largest!=i){
		exchange(array,i,largest);		// Swap pointers into array
		maxHeapify(array,heapSize,largest,compare);	// Recurcive call of this function
	}
}

void buildMaxHeap(void ** array,int heapSize,int (*compare)(const void*,const void*)){		

	int length = --heapSize;	// heapSize - 1 , because of array : 0,...,size-1
	for(int i = length/2; i>=0 ;i--){	// for every element in the heap -> length/2
		maxHeapify(array,heapSize,i,compare);
	}
}

void heapsort(void ** array,int heapSize,int (*compare)(const void*,const void*)){

	buildMaxHeap(array,heapSize,compare);
	int temp = heapSize-1;
	for(int i = heapSize-1;i>=1;i--){	// For every element of the array
		exchange(array,0,i);	// Swap it with the first 
		temp--;		// Decrease heap size
		maxHeapify(array,temp,0,compare);	//Rec-call to maintain properties 
	}
}