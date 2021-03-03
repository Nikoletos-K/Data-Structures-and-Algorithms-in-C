#include "compFunctions.h"

/*----------------- Quicksort functions -----------------*/
void quicksort(void ** array,int p,int r,sortingColumn columnId);
int partition(void ** array,int p,int r,sortingColumn columnId);

/*----------------- Heapsort functions ------------------*/
int getLeft(int i);
int getRight(int i);
int getParent(int i);
void maxHeapify(void ** array,int heapSize,int i,sortingColumn column );
void heapsort(void ** array,int heapSize,sortingColumn column);