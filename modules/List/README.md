# Linked List
Double linked list with pointers to start and end of it. Generic implementation.

## Definition
Linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.

## Complexity
For n items:
| | Insertion | Search |
|--- | --- | --- |
| Best-case | O(1) | O(1) |
| Worst-case | O(1) | O(n\*n) |

## Nodes preview
```
typedef struct listNode{
	
	void * data;
	listNode * nextNode;
	listNode * prevNode;
		
}listNode;

typedef struct List{

	listNode * firstNode;
	listNode * lastNode;
	int numOfNodes;

}List;
```

## Main Functionality
```
List * createList(); // constructor

int insert_toList(List * list,void * data); // insertion function

void * getData_fromList(List * list,int index); // geters

void * findValue(List * list,void * value,int (*comparator)(void*,void*)); // search function

void printList(List * list,void (*printData)(void*)); // print function

int get_listSize(List * list); // size

List * mergeLists(List * list1,List * list2); // merge lists

int deleteList(List * list); // destructor
```
