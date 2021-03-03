#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../../include/HashTable.h"

unsigned int hashFunction(char * str,unsigned int length){

	unsigned int seed = 131; 
	unsigned int hash = 0;
	unsigned int i=0;

	for (i = 0; i < length; ++str, ++i){

		hash = (hash * seed) + (*str);
	}

   return hash;
}

/*---------------------------------Create_Functions-------------------------------------------*/

HashTable * HTConstruct(int size){

	HashTable * ht = malloc(sizeof(HashTable));
	ht->size = size;
	ht->Table = malloc(size*sizeof(HTNode *));

	for(int i=0;i<size;i++){

		ht->Table[i] = malloc(sizeof(HTNode));
		ht->Table[i]->rbtRoot = NULL;
	}

	return ht;	 	
}

/*-----------------------------------Insert_Functions-------------------------------------*/


void HTInsert(HashTable * ht,keyType key,void * data,int (*comparator)(valueType,valueType)){

	unsigned int index = hashFunction(key,strlen((char*)key))%ht->size;

	
	if(ht->Table[index]->rbtRoot == NULL)		/*If empty create new key and then insert the data */
		ht->Table[index]->rbtRoot = RBTConstruct();

	RBTInsert(&ht->Table[index]->rbtRoot,data,key,comparator);
}

/*-------------------------------------Search_function---------------------------------------*/

void * HTSearch(HashTable * ht,keyType key,int (*comparator)(valueType,valueType)){

	unsigned int index = hashFunction(key,strlen((char*)key))%ht->size;

	if(ht->Table[index]->rbtRoot != NULL){
		RBTNode * node = RBTFindNode(ht->Table[index]->rbtRoot,key,comparator);
		if(node==NULL)	return NULL;
		else return get_RBTData(node);


	}else
		return NULL;

}


/*-------------------------------------Destructor---------------------------------------*/

void HTDestroy(HashTable * ht){

	for(int i=0 ; i<(ht->size);i++){
		
		if(ht->Table[i]->rbtRoot!=NULL)
			RBTDestroyTree(ht->Table[i]->rbtRoot);
		free(ht->Table[i]);
	}
	free(ht->Table);
	free(ht);
}
