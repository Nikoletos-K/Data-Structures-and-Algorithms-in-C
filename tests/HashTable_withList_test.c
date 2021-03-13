#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"
#include "./../include/HashTable_withList.h"

void test_HTConstruct(void){

	/* Checking pointers and initialization */
	int size=10;
	HashTable * ht = createHashTable(size);
	TEST_ASSERT(ht != NULL);
	TEST_ASSERT(ht->Table != NULL);

	destroyHashTable(ht);
}

void test_HTInsert(void){

	int size=20;
	HashTable * ht = createHashTable(size);

	/* Inserting an array of elements to hashtable */
	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size
    for(int i=0;i<sizeofArray;i++)
    	HashInsert(ht,(void*)string_exampleArray[i],(void *) &integer_exampleArray[i],compare_str);
    
    destroyHashTable(ht);
}

void test_HTSearch(void){

	int size=10;
	HashTable * ht = createHashTable(size);

	/* Inserting an array of elements to hashtable */
	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size
    for(int i=0;i<sizeofArray;i++)
    	HashInsert(ht,(void*)string_exampleArray[i],(void *) &integer_exampleArray[i],compare_str);
    

    /* Finding all inserted elements */
    for(int i=0;i<sizeofArray;i++){
    	char * data = (char *) getKey(findKeyNode(ht,(void*)string_exampleArray[i],compare_str)); 
    	TEST_ASSERT(compare_str(data,string_exampleArray[i])==0);
    }
    
    destroyHashTable(ht);
}



TEST_LIST = {
	{"HTConstruct - List implementation",test_HTConstruct},
	{"HTInsert - List implementation",test_HTInsert},
	{"HTSearch - List implementation",test_HTSearch},
	{ NULL, NULL }
};