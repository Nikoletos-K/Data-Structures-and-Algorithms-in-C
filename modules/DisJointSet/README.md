# DisJoint Set
The Disjoint set data structure was used to create clicks. It is essentially an array of integers, where each position represents a spec and the value of this position stores the "father" of the spec, ie elements with the same "father" belong and in the same clique. After reading the Dataset W, any positive correlation implies that the two elements belong to the same clique. Then the table is updated.

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
