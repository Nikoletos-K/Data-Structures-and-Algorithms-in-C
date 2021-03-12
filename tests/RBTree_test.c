#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "./../include/RBTree.h"

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

void test_initializeDataStructures(void){
	initializeDataStructures();
	TEST_ASSERT(GUARD != NULL);
	destroyDataStructures();
}

void test_RBTConstruct(void){
	initializeDataStructures();
	RBTNode * root = RBTConstruct();
	TEST_ASSERT(root == GUARD);
	RBTDestroyTree(root);
	destroyDataStructures();
}

void test_RBTInitialiseKey(){
	initializeDataStructures();
	int data = 1;
	char * key = "abcdf";
	RBTNode * temp = RBTnewNode((void *) &data,(void*) key);
	TEST_ASSERT(temp->key != NULL);
	TEST_ASSERT(strcmp(temp->key,key) == 0);

	RBTDestroyNode(temp);
	destroyDataStructures();
}

void test_RBTnewNode(void){
	initializeDataStructures();
	int data = 1;
	char * key = "abcdf";
	RBTNode * tempNode = RBTnewNode((void *) &data,(void*) key);

	TEST_ASSERT(tempNode != NULL);
	TEST_ASSERT(tempNode->parent == GUARD);
	TEST_ASSERT(tempNode->right == GUARD);
	TEST_ASSERT(tempNode->left == GUARD);
	TEST_ASSERT(tempNode->data == &data);
	TEST_ASSERT(tempNode->color == RED);
	TEST_ASSERT(!strcmp(tempNode->key,key));
	TEST_MSG("Red black tree node checked");

	RBTDestroyNode(tempNode);
	destroyDataStructures();
}

void test_geters(void) {
	initializeDataStructures();
	int data = 1;
	char * key = "abcdf";
	RBTNode * temp = RBTnewNode((void *) &data,(void*) key);

	TEST_ASSERT(GetParent(temp) == GUARD);
	TEST_ASSERT(GetGrandParent(temp) == GUARD);
	TEST_ASSERT(GetColor(temp) == RED);
	TEST_ASSERT((get_RBTData(temp)) == &data);
	TEST_ASSERT(strcmp(GetKey(temp),key)==0);

	RBTDestroyNode(temp);
	destroyDataStructures();
}

void test_seters(void) {

	initializeDataStructures();
	int data = 1;
	char * key = "abcdf";
	RBTNode * temp = RBTnewNode((void *) &data,(void*) key);

	SetColor(temp,BLACK);
	TEST_ASSERT(GetColor(temp) == BLACK);
	TEST_ASSERT(GetGrandParent(temp) == GUARD);
	TEST_ASSERT(strcmp(GetKey(temp),key)==0);

	RBTDestroyNode(temp);
	destroyDataStructures();
}

void test_RBTInsert(void){

	initializeDataStructures();

	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size

	RBTNode * root = RBTConstruct();

	/* Inserting an array of elements to RBT */
    for(int i=0;i<sizeofArray;i++)
		RBTInsert(&root,(void *) &integer_exampleArray[i],(void*)string_exampleArray[i],compare_str);
    
	
	TEST_ASSERT(RBTempty(root)==0);

	RBTDestroyTree(root);
	destroyDataStructures();	
}

void test_RBTFindNode(void){
	initializeDataStructures();

	int integer_exampleArray[10] = {8,2,9,0,3,4,7,5,6,1};
    char * string_exampleArray[10] = {"i","a","c","d","b","f","g","e","h","j"};
    int sizeofArray = 10;  // array size

	RBTNode * root = RBTConstruct();

	/* Inserting an array of elements to RBT */
    for(int i=0;i<sizeofArray;i++)
		RBTInsert(&root,(void *) &integer_exampleArray[i],(void*)string_exampleArray[i],compare_str);
    
    /* Checking if all data are inserted */
	for(int i=0;i<sizeofArray;i++){
		RBTNode * temp = RBTFindNode(root,(void*)string_exampleArray[i],compare_str);
		char * found_key = (char*)GetKey(temp);
		TEST_ASSERT(strcmp(string_exampleArray[i],found_key) == 0);
	}

	TEST_ASSERT(RBTempty(root)==0);

	RBTDestroyTree(root);
	destroyDataStructures();	
}

void test_RBTempty(void){
	initializeDataStructures();
	RBTNode * root = RBTConstruct();

	/* initially must be empty */
	TEST_ASSERT(RBTempty(root)==1);

	int data = 1;
	char * key = "abcdf";
	RBTInsert(&root,(void *) &data,(void*)key,compare_str);
	/* not empty situation */
	TEST_ASSERT(RBTempty(root)==0);

	RBTDestroyTree(root);
	destroyDataStructures();	
}

TEST_LIST = {
	{"comparators",test_comparators},
	{"initializeDataStructures",test_initializeDataStructures},
	{"RBTConstruct",test_RBTConstruct},
	{"RBTInitialiseKey",test_RBTInitialiseKey},
	{"RBTnewNode",test_RBTnewNode},
	{"geters",test_geters},
	{"seters",test_seters},
	{"RBTInsert",test_RBTInsert},
	{"RBTFindNode",test_RBTFindNode},
	{"RBTempty",test_RBTempty},
	{ NULL, NULL }
};