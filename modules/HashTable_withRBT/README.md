# HashTable with Red-Black trees

Consisted of a table, in which every row has a pointer to a Red-Black tree
This way we get the above best complexities and at the same time avoiding too many collisions.

| | Insertion | Search |
| --- | --- | --- |
| Best-case | O(1) | O(1) |
| Worst-case | O(logn) | O(logn) |


## Links with other modules
Download and connect this structure with:

- ```RBTree ```
- ```HashFunctions ```
- ``` Comparators```


## Main Functionality
```
HashTable * HTConstruct(int size);
void HTInsert(HashTable * ht,keyType key,void * data,int (*comparator)(valueType,valueType))
void * HTSearch(HashTable * ht,keyType key,int (*comparator)(valueType,valueType));  //  Searches the key by using the approptiate type of comparator
void HTDestroy(HashTable * ht); // Destroys the structure
```
