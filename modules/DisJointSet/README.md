# DisJoint Set
Disjoint-set data structure, also called a union–find data structure or merge–find set, is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets (replacing them by their union), and finding a representative member of a set. The last operation allows to find out efficiently if any two elements are in the same or different sets.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a3/UnionFindKruskalDemo.gif/250px-UnionFindKruskalDemo.gif)

## Complexity
For with n nodes requires total time O(mα(n)), where α(n) is the extremely slow-growing inverse Ackermann function 

| Algorithm	|	Average |	Worst case |
| --- | --- | --- |
| Space		  | O(n) |	O(n) |
| Search		| O(α(n)) |	O(α(n)) |
| Merge		  | O(α(n)) |	O(α(n)) |


## Structure
```
typedef struct DisJointSet {

	size_t size;
	int * rankArray;
	int * parentArray;
	void ** objectArray;

} DisJointSet;
```

## Main Functionality
```
DisJointSet * DJSConstruct(int set_size,void ** objectArray); /* Constructor */

/* Methods */
void DJSUnion(DisJointSet * dsjSet,int x,int y); 
void DJSConnect(DisJointSet * dsjSet,int x,int y);
int DJSFindParent(DisJointSet * dsjSet,int x);

/* Getters */
int DJSgetRank(DisJointSet * dsjSet,int x);
int DJSgetParent(DisJointSet * dsjSet,int x);

/* Setters */
void DJSsetParent(DisJointSet * dsjSet,int x,int newparent);
void DJSsetRank(DisJointSet * dsjSet,int x,int newrank);

void DJSDestructor(DisJointSet * dsjSet); /* Destructor */
```

## Reference
- [hackerearth](https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/)
