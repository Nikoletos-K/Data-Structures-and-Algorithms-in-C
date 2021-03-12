#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"
#include "./../include/HashTable.h"

/* ----- Comparator testing ------ */
int compare_ints(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

int compare_str(const void * str1,const void * str2){
    return strcmp((char*) str1,(char*) str2);
}

void test_comparators(void){

	int small=1,big=2;
	TEST_ASSERT(compare_ints((void*)&small,(void*)&big)<0);

	char * a = "a";
	char * b = "b";
	TEST_ASSERT(compare_str((void*)a,(void*)b) == strcmp(a,b));
}

void test_HTConstruct(void){

	/* Checking pointers and initialization */
	int size=10;
	HashTable * ht = HTConstruct(size);
	TEST_ASSERT(ht != NULL);
	TEST_ASSERT(ht->size == size);
	TEST_ASSERT(ht->Table != NULL);

	HTDestroy(ht);
}

void test_HTInsert(void){

	initializeDataStructures();
	int size=10;
	HashTable * ht = HTConstruct(size);

	/* Inserting an array of elements to hashtable */
	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size
    for(int i=0;i<sizeofArray;i++)
    	HTInsert(ht,(void*)string_exampleArray[i],(void *) &integer_exampleArray[i],compare_str);
    
    TEST_ASSERT(ht->size == size);

    HTDestroy(ht);
    destroyDataStructures();
}

void test_HTSearch(void){

	initializeDataStructures();
	int size=10;
	HashTable * ht = HTConstruct(size);

	/* Inserting an array of elements to hashtable */
	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size
    for(int i=0;i<sizeofArray;i++)
    	HTInsert(ht,(void*)string_exampleArray[i],(void *) &integer_exampleArray[i],compare_str);
    

    /* Finding all inserted elements */
    for(int i=0;i<sizeofArray;i++){
    	int * data = (int *)HTSearch(ht,(void*)string_exampleArray[i],compare_str); 
    	TEST_ASSERT(*data == integer_exampleArray[i]);
    }

    TEST_ASSERT(ht->size == size);
    
    HTDestroy(ht);
    destroyDataStructures();
}



TEST_LIST = {
	{"comparators",test_comparators},
	{"HTConstruct",test_HTConstruct},
	{"HTInsert",test_HTInsert},
	{"HTSearch",test_HTSearch},
	{ NULL, NULL }
};