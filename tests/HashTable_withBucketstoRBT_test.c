#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"
#include "./../include/HashTable_withBucketstoRBT.h"


void test_HTConstruct(void){

	/* Checking pointers and initialization */
	int size=10;
	HashTable * ht = create_HashTable(size,256);
	TEST_ASSERT(ht != NULL);
	TEST_ASSERT(ht->hashtableSize == size);

	destroyHashTable(ht);
}

void test_HTInsert(void){

	initializeDataStructures();
	int size=10;
	HashTable * ht = create_HashTable(size,256);

	/* Inserting an array of elements to hashtable */
	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size
    for(int i=0;i<sizeofArray;i++)
    	insert_toHashTable((void *) &integer_exampleArray[i],(void*)string_exampleArray[i],(void*)string_exampleArray[i],ht,compare_str);
    	
    TEST_ASSERT(ht->hashtableSize == size);

    destroyHashTable(ht);
    destroyDataStructures();
}

void test_HTSearch(void){

	initializeDataStructures();
	int size=10;
	HashTable * ht = create_HashTable(size,256);

	/* Inserting an array of elements to hashtable */
	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size
    for(int i=0;i<sizeofArray;i++)
    	insert_toHashTable((void *) &integer_exampleArray[i],(void*)string_exampleArray[i],(void*)string_exampleArray[i],ht,compare_str);

    TEST_ASSERT(ht->hashtableSize == size);
    
    destroyHashTable(ht);
    destroyDataStructures();
}



TEST_LIST = {
	{"HTConstruct - Buckets to RBT",test_HTConstruct},
	{"HTInsert - Buckets to RBT",test_HTInsert},
	{"HTSearch - Buckets to RBT",test_HTSearch},
	{ NULL, NULL }
};