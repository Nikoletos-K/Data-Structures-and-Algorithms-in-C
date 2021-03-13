#include <stdio.h>

#include "./../../include/QuickSort.h"


/*---- Recursive - Generic implementation of quicksort ---------------*/

// Exchange is a swap function
void exchange(void ** array,int pos1,int pos2){

	void * temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;

}

void quicksort(void ** array,int p,int r,int (*compare)(const void*,const void*)){

	if(p<r){
		int q = partition(array,p,r,compare);	/* pivot */
		quicksort(array,p,q-1,compare);
		quicksort(array,q+1,r,compare);
	}
}

int partition(void ** array,int p,int r,int (*compare)(const void*,const void*)){

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
