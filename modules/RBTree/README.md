# Red-Black tree
Generic implementation of a red-black tree, totally based on the book Introduction to Algorithms by Thomas H. Cormen.

![](https://cdn-images-1.medium.com/max/700/1*84jyh_SAj6keE5yKgqYDYQ.gif)


## Link with other modules
For using this module follow these steps:
1. Download this directory ```RBTree``` which contains file ```RBTree.c```
2. Go to directory ```include``` and download also ```RBTree.h```
3. __Repeat the same steps for ```Compartors```__
4. Fix the ```#include``` paths
5. Ready!


## Main functionality
1. __```initializeDataStructures(); ```:__ Initializes variables and creates GUARD node, call it only once despite the number of trees you'll create! 
2. __``` RBTNode * tree =  RBTConstruct(); ```__ : Constructor function, returns a pointer to the root.
3. __``` RBTInsert(RBTNode **treeRoot,void * data,valueType key,int (*comparator)(valueType,valueType));```__
      - ```RBTNode **treeRoot```: tree root to insert value
      - ```void * data```: generic type of data that will be stored in this node (e.g a pointer t struct)
      - ```valueType key```: valueType is void* and in this field you'll pass the key of the node
      - ```int (*comparator)(valueType,valueType)```: Type of comparator depending on the type of key
4. __```RBTNode * node =  RBTFindNode(RBTNode * node,valueType key,int (*comparator)(valueType,valueType));```__
      - ```RBTNode *node```: tree root to search value
      - ```valueType key```: valueType is void* and in this field you'll pass the key of the node that you want to search
      - ```int (*comparator)(valueType,valueType)```: Type of comparator depending on the type of key
5. __```RBTDestroyTree(RBTNode * treeRoot);```__: Tree destructor
6. __```destroyDataStructures(); ```__: Call it in the end, destroyes the GUARD node. Call it only once!!


## Definition
In computer science, a red–black tree is a kind of self-balancing binary search tree. Each node stores an extra bit representing "color" ("red" or "black"), used to ensure that the tree remains balanced during insertions and deletions.


## Time Complexity
For n nodes:

| Algorithm	|	Average |	Worst case |
| ---	  |  ---   | --- |
| Space		  |  O(n)   | O(n) |
|Search		|  O(log n) | O(log n) | 
|Insert		| O(log n) | O(log n) |
|Delete		| O(log n) | O(log n) | 

## Structure
```
extern RBTNode * GUARD;				/* Global pointer for guard */

typedef struct Node {

	RBTNode * parent,*left,*right;
	enum nodeColor color;
	valueType key;

	void * data;

} RBTNode;
```
