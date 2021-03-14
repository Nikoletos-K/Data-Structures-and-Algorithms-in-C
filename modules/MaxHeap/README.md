# MaxHeap
Generic implementation of Max Heap


## Link with other modules
For using this module follow these steps:
1. Download this directory ```MaxHeap``` which contains file ```maxHeap.c```
2. Go to directory ```include``` and download also ```maxHeap.h```
3. __Repeat the same steps for ```Comparators```__
4. Fix the ```#include``` paths
5. Ready!


## Definition
A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node. Mapping the elements of a heap into an array is trivial: if a node is stored an index k, then its left child is stored at index 2k+1 and its right child at index 2k+2.

![](https://www.tutorialspoint.com/data_structures_algorithms/images/max_heap_animation.gif)

## Time Complexity 
For n items:
| | Complexity |
|--- | --- |
| Pop Max | O(1) |
| Extract Max | O(logn) |
| Insert | O(logn) |


## Structure
```
typedef struct  heapNode{

	heapNode * parent;
	heapNode * leftChild;
	heapNode * rightChild;
	void * value;

}heapNode;

typedef struct Heap{

	int size;
	heapNode * root;
	
}Heap;
```


## Main Functionality
```
Heap * heapConstruct();  // constructor
void insert_toHeap(Heap * heap,void * value,int (*comparator)(const void *,const void *)); // insertion function
void * extractMax_fromHeap(Heap * heap,int (*comparator)(const void *,const void *)); // extraction function
void destroyHeap(Heap * heap);  // destructor
```
