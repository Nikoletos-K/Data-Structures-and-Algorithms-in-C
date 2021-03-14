# Quick Sort
This implementation is based 100% to the algorithm provided in the book Introduction to Algorithms by Thomas H. Cormen.

## Link with other modules
For using this module follow these steps:
1. Download this directory ```QuickSort``` which contains file ```QuickSort.c```
2. Go to directory ```include``` and download also ```QuickSort.h```
3. __Repeat the same steps for ```Compartors```__
4. Fix the ```#include``` paths
5. Ready!

## Main functionality
```
void quicksort(void ** array,int p,int r,int (*compare)(const void*,const void*));
```
where:

- ```void ** array```: The array to be sorted
- ```int p``` : Start node
- ```int r``` : End node
- ```int (*compare)(const void*,const void*)```: Comparator function

## Definition
Quicksort is an efficient sorting algorithm. Developed by British computer scientist Tony Hoare in 1959 and published in 1961, it is still a commonly used algorithm for sorting. When implemented well, it can be somewhat faster than merge sort and about two or three times faster than heapsort.

Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. For this reason, it is sometimes called partition-exchange sort. The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting.

__Example:__

![](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6a/Sorting_quicksort_anim.gif/220px-Sorting_quicksort_anim.gif)


Quicksort is a comparison sort, meaning that it can sort items of any type for which a "less-than" relation (formally, a total order) is defined. Efficient implementations of Quicksort are not a stable sort, meaning that the relative order of equal sort items is not preserved.



## Complexity
For n items:
| | Complexity |
|--- | --- |
| Average | O(nlogn) |
| Worst-case | (n\*n) |


## Resources
[Wikipedia](https://en.wikipedia.org/wiki/Quicksort)

