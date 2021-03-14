# HashTable consisted of a table with chains
Generic implementation of a very simple hashtable with keys and chains. No reconstruction provided.


__Links with other modules:__
```
#include "./Comparators.h"		// we need Comparators
#include "./HashFunctions.h"		// we need HashFunctions
```

## Instructions
For using this generic hashtable follow these steps:

1. Download this directory ```HashTable_withList``` which contains file ```HashTable_withList.c```
2. Go to directory ```include``` and download also ```HashTable_withList.h```
3. __Repeat the same steps for ```HashFunctions``` and ```Comparators```__ 
4. Fix the ```#include``` paths
5. Ready!

## Main Functionality
```
HashTable * createHashTable(int size);
void HashInsert(HashTable * ht,keyType key,InfoType * info,int (*compare)(const void*,const void*));
keyType getKey(KeyNode * keyList);
KeyNode * findKeyNode(HashTable * ht,keyType key,int (*compare)(const void*,const void*));
void RemoveDataFromHT(HashTable * ht,InfoType * rmData,keyType key,int (*compare)(const void*,const void*));
void RemoveKeyFromHT(HashTable * ht , keyType key,int (*compare)(const void*,const void*));
void destroyDataList(DataNode * startOfList);
void destroyHashTable(HashTable * ht);
```




