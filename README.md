[![run-tests](https://github.com/Nikoletos-K/Data-Stuctures-and-Algorithms-in-C/actions/workflows/run-tests.yml/badge.svg)](https://github.com/Nikoletos-K/Data-Stuctures-and-Algorithms-in-C/actions/workflows/run-tests.yml)

---

# Data Stuctures and Algorithms implemented in C 
Here you will find some data structures and algorithms implemented in C. These algorithms are mostly based on the book ___Introduction to Algorithms by Thomas H. Cormen___.

## Instructions
Every module consists of at least one header file (.h) and one source file that contains the code corpus (.c). In order to use one of these modules I suggest you to follow these steps:

 1. Find the data structure or algorithm you need from ```/modules```
 2. Download the module directory (e.g ```/modules/List```) that contains the source code .c file (e.g ```List.c```) 
 3. Go to ```/include/``` folder, find the header (.h) file that you want (e.g ```List.h```) and download it.
 4. ❕ Not finished yet ❕, now go and check the header file (.h) and download  what is included (Commands ```#include "foo.h"```). Most of the modules include for example ```HashFunctions``` or ```Comparators``` or even other data structures. Spot what is needed and download __all__ files.
 5. Fix the paths to the ```#include "foo.h"``` if you change the current folder structure.
 6. Everything is ready, hope it helped you!

## Compile and Execution
If you clone the whole folder you can run:
- ```make```: That compliles every module 
- ```make run-tests```: which compiles every module and executes all tests
- ```make valgind-tests```:  which compiles every module and executes all tests using valgrind

## Appendix

| Data structure | Definition |
| --- | --- |
| __Bloom filter__ | Bloom filter is a space-efficient probabilistic data structure, conceived by Burton Howard Bloom in 1970, that is used to test whether an element is a member of a set. False positive matches are possible, but false negatives are not – in other words, a query returns either "possibly in set" or "definitely not in set". Elements can be added to the set, but not removed (though this can be addressed with the counting Bloom filter variant); the more items added, the larger the probability of false positives. |
| __Red-black Tree__ | Red–black tree is a kind of self-balancing binary search tree. Each node stores an extra bit representing "color" ("red" or "black"), used to ensure that the tree remains balanced during insertions and deletions. When the tree is modified, the new tree is rearranged and "repainted" to restore the coloring properties that constrain how unbalanced the tree can become in the worst case. The properties are designed such that this rearranging and recoloring can be performed efficiently. The re-balancing is not perfect, but guarantees searching in __O(logn)__ time, where n is the number of nodes of the tree. The insertion and deletion operations, along with the tree rearrangement and recoloring, are also performed in __O(logn)__ time. |
| __Linked List__ | Linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. |
| __Queue__ | Priority queue is an abstract data type similar to a regular queue or stack data structure in which each element additionally has a "priority" associated with it. In a priority queue, an element with high priority is served before an element with low priority. |
| __Hashtable with list__ | Generic implementation of a very simple hashtable with keys and chains. No reconstruction provided. |
| __Hashtable with Red-black tree__ | Consisted of a table, in which every row has a pointer to a Red-Black tree This way we get the above best complexities and at the same time avoiding too many collisions. |
| __Hashtable with buckets to Red-black tree__ | HashTable consisted of Buckets of pointers to Red Black Trees |
| __MaxHeap__ | A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node. Mapping the elements of a heap into an array is trivial: if a node is stored an index k, then its left child is stored at index 2k+1 and its right child at index 2k+2. |
| __DisJointSet__ | Disjoint-set data structure, also called a union–find data structure or merge–find set, is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets (replacing them by their union), and finding a representative member of a set. The last operation allows to find out efficiently if any two elements are in the same or different sets. |
| __Job Scheduler with Threads__ | Multi-thread job scheduler using Unix pthreads. |

---

| Algorithm | Definition |
| --- | --- |
| __HeapSort__ | Heapsort is a comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort: like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. Unlike selection sort, heapsort does not waste time with a linear-time scan of the unsorted region; rather, heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step. |
| __QuickSort__ | Quicksort is an efficient sorting algorithm. Developed by British computer scientist Tony Hoare in 1959 and published in 1961, it is still a commonly used algorithm for sorting. When implemented well, it can be somewhat faster than merge sort and about two or three times faster than heapsort. |

---

| Utility | Definition |
| --- | --- |
| __Comparators__ | Functions that compare two values and return 0, \>0, <0 |
| __Hash functions__ | String hash functions |


## Unit-Testing
For the testing of the structures but also of the models that we have created, we used the library ```acutest.h```.


More information about the [acutest library](https://github.com/mity/acutest)

## Future work
Creating simple programs (main functions) as use examples for all the modules.


☑️ __Some modules have been made in collaboration with [Myrto Iglezou](https://github.com/Myrto-Iglezou)__.

---

© Konstantinos Nikoletos
