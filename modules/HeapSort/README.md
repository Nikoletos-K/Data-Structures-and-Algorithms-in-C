# Heap sort
This implementation is based 100% to the algorithm provided in the book Introduction to Algorithms by Thomas H. Cormen.

## Link with other modules
For using this module follow these steps:
1. Download this directory ```HeapSort``` which contains file ```HeapSort.c```
2. Go to directory ```include``` and download also ```HeapSort.h```
3. __Repeat the same steps for ```Compartors```__
4. Fix the ```#include``` paths
5. Ready!

## Main functionality
```
void heapsort(void ** array,int heapSize,int (*compare)(const void*,const void*));
```
where:

- ```void ** array```: The array to be sorted
- ```int heapSize``` : Number of nodes in heap
- ```int (*compare)(const void*,const void*)```: Comparator function

## Definition
In computer science, heapsort is a comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort: 
like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. 
Unlike selection sort, heapsort does not waste time with a linear-time scan of the unsorted region; rather, 
heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step.

__Example:__

![](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif)

Although somewhat slower in practice on most machines than a well-implemented quicksort, it has the advantage of a more favorable worst-case O(n log n) runtime. Heapsort is an in-place algorithm, but it is not a stable sort.


Heapsort was invented by J. W. J. Williams in 1964. This was also the birth of the heap, presented already by Williams as a useful data structure in its own right. In the same year, R. W. Floyd published an improved version that could sort an array in-place, continuing his earlier research into the treesort algorithm.

## Complexity
Overall time complexity of Heap Sort is O(nLogn)

## Resources
[Wikipedia](https://en.wikipedia.org/wiki/Heapsort)




