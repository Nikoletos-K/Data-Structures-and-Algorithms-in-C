# Priority Queue
Double linked list with pointers to start and end of it. Generic implementation.

## Definition
Priority queue is an abstract data type similar to a regular queue or stack data structure in which each element additionally has a "priority" associated with it. In a priority queue, an element with high priority is served before an element with low priority.

## Complexity
For n items:
| | Push | Pop | Search |
|--- | --- | --- | ---  |
| Best-case | O(1) | O(1) | O(1) |
| Worst-case | O(1) | O(1) | O(n\*n) |

## Nodes preview
```
typedef struct queueNode{
	
	void * data;
	queueNode * nextNode;
	queueNode * prevNode;
		
}queueNode;

typedef struct Queue{

	queueNode * firstNode;
	queueNode * lastNode;
	int numOfNodes;

} Queue;
```

## Main Functionality
```
Queue * createQueue(); // constructor
int QueuePush(Queue * queue,void * data);  // insertion function
void * QueuePop(Queue * queue); // Pop
int emptyQueue(Queue * queue); // If empty returns true
int deleteQueue(Queue * queue); // destructor

```
