#pragma once

#include "./RBTree.h"
#define empty NULL
#define HASHTABLE_SIZE 1751

typedef char * keyType;

typedef struct HTNode{
	RBTNode * rbtRoot;
}HTNode;

typedef struct HashTable {
	unsigned int size;
	HTNode **Table;	
}HashTable;



/*---------Create_Functions-------------*/

HashTable * HTConstruct(int size);

/*-------------Insert_Functions-----------------*/

void HTInsert(HashTable * ht,keyType key,void * data,int (*comparator)(valueType,valueType));

/*------------Getters-----------------*/

unsigned int hashCode(HashTable * ht,keyType key);
unsigned int hashFunction(char * str,unsigned int length);

/*--------------Search_function-------------------*/

void * HTSearch(HashTable * ht,keyType key,int (*comparator)(valueType,valueType));

/*------------------Destructors----------------*/

void HTDestroy(HashTable * ht);
