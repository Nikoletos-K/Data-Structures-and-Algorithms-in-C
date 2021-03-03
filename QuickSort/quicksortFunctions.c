#include <stdio.h>

#include "QuickSort.h"

int (*compare)(void*,void*);
compare = compareIntegers;

/*---- Recursive - Generic implementation of quicksort ---------------*/

// Exchange is a swap function
void exchange(void ** array,int pos1,int pos2){

	void * temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;

}

void quicksort(void ** array,int p,int r){

	if(p<r){
		int q = partition(array,p,r);	/* pivot */
		quicksort(array,p,q-1);
		quicksort(array,q+1,r);
	}
}

int partition(void ** array,int p,int r){

	void * value = array[r];	// pivot element
	int i = p-1;

	for(int j=p;j<r;j++){		// with this loop ,values seperated into 2 partitions ,those bigger and smaller from the pivot
		if(compare(array[j],value)<=0){
			i = i+1;
			exchange(array,i,j);	// change positions of the elements before and after the sorted element
		}
	}
	exchange(array,i+1,r);		// move starting element to it's final position

	return i+1;
}


int compareStrings(void * str1,void * str2){

	return strcmp((char *) str1, (char*) str2);
} 

int compareIntegers(void * int1,void * int2){

	return (*(int *) int1 - *(int *) int2);
}


int compareLongs(void * long1,void * long2){

	return (*(long *) long1 - *(long *) long2);
}

int compareFloats(void * float1,void * float2){

	return (*(float *) float1 - *(float *) float2);
}

