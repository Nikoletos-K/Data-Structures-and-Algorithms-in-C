#include <stdio.h>
#include <stdlib.h>

#include "./../../include/HashTable_withList.h"


/*---------------------------------Create_Functions-------------------------------------------*/

HashTable * createHashTable(int size){

	int newSize = firstPrime(size/20,size);			/* Size  of hash table = First prime number after numofvoters/20 */
	HashTable * ht = malloc(sizeof(HashTable));
	ht->size = newSize;
	ht->Table = malloc(newSize*sizeof(HashNode *));

	for(int i=0;i<newSize;i++){

		ht->Table[i] = malloc(sizeof(HashNode));
		ht->Table[i]->keyList = empty;
	}

	return ht;	 	
}

KeyNode * createKeyNode(keyType key){

	KeyNode * temp = malloc(sizeof(KeyNode));
	temp->key = key;
	temp->dataList = NULL;
	temp->next = NULL;

	return temp;


}

DataNode * createDataNode(InfoType * newdata){

	DataNode * d = malloc(sizeof(DataNode));
	d->data = newdata;
	d->next = NULL;

	return d;

}

/*-------------------------------------Getters-------------------------------------------*/

unsigned int hashCode(HashTable * ht,keyType key) {return StringHashFunction_RS(key) % (ht->size);}

keyType getKey(KeyNode * keyList){ return keyList->key; }


/*-----------------------------------Insert_Functions-------------------------------------*/

KeyNode * insertNewKey(HashNode * hn , keyType key){

	KeyNode * k = createKeyNode(key);

	KeyNode * prev=NULL,*temp=NULL;

	if(hn->keyList == empty)			/* If empty insert it at the beggining */
		hn->keyList = k;	
	else{
		
		prev = hn->keyList;				/* Else enter at end of the list */
		temp = hn->keyList->next;
		while(temp != NULL){
			prev = temp;
			temp = temp->next;
		}

		prev->next = k;
	}	

	return k;
}

void insertData(KeyNode * key,InfoType * newdata){

	DataNode * d = createDataNode(newdata);

	if( key->dataList == NULL)
		key->dataList = d;
	else{
		d->next = key->dataList;		/* Insert at the beggining */
		key->dataList = d;
	}		
}


void HashInsert(HashTable * ht,keyType key,InfoType * data,int (*compare)(const void*,const void*)){

	unsigned int index = hashCode(ht,key);

	
	if(ht->Table[index]->keyList == empty){			/*If empty create new key and then insert the data */

		insertNewKey(ht->Table[index],key);
		insertData(ht->Table[index]->keyList,data);

	}else{

		keyType foundKey  = getKey(ht->Table[index]->keyList);

		if(compare(foundKey,key) == 0){								/* We have the same key , just enter the data */

			insertData(ht->Table[index]->keyList,data);

		}else {				/* If  we have a collision of two same hashes create new key and insert it in the hash table*/


			KeyNode * kn = findKeyNode(ht,key,compare);
			
			if(kn==NULL)
				kn = insertNewKey(ht->Table[index],key);
			

			insertData(kn,data);
			
		
		}
	} 
}

/*-------------------------------------Search_function---------------------------------------*/


KeyNode * findKeyNode(HashTable * ht,keyType key,int (*compare)(const void*,const void*)){

	unsigned int index = hashCode(ht,key);
	
	KeyNode * kn = ht->Table[index]->keyList;
	KeyNode * temp = kn;


	while(temp!=NULL && compare(temp->key,key)!=0){
		temp = temp->next;
	}

	return temp;

}


/*------------------------------------Remove_functions----------------------------------------*/

void RemoveDataFromHT(HashTable * ht,InfoType * rmData,keyType key,int (*compare)(const void*,const void*)){

	int counter = 0;													/*I use counter to see if list will be empty*/
	KeyNode * kn = findKeyNode(ht,key,compare);

	DataNode * temp = kn->dataList, * prev = NULL , * next = NULL;

	prev=temp;

	while(rmData != temp->data ){						/*Run until finding the voter that needs to be removed */
		counter++;
		prev = temp;
		temp = temp->next;
	}
	next = temp->next;

	if(prev == temp)
		kn->dataList = next;
	else
		prev->next = next;


	prev=NULL;

	if(counter == 0 && kn->dataList==temp && temp->next==NULL)			/*If Datalist is empty ,initialize hashtable as empty for this key */
		kn->dataList = NULL;
	

	free(temp);
	temp=NULL;

	if(kn->dataList == NULL)
		RemoveKeyFromHT( ht , kn->key, compare);						/*Finally , if key is empty remove it*/
}

void RemoveKeyFromHT(HashTable * ht , keyType key,int (*compare)(const void*,const void*)){

	unsigned int index = hashCode(ht,key);
	int counter = 0;
	KeyNode * kn = ht->Table[index]->keyList;
	KeyNode * temp = kn , *prev , *next;

	prev = temp;
	while(temp!=NULL && compare(temp->key,key) != 0){				/*Find specific key that needs removal */
		counter++;
		prev = temp;
		temp = temp->next;
	}
	next = temp->next ;
	prev->next = next;

	free(temp);
	temp = NULL;

	if(counter == 0){							/*If list is empty mark this key in table as empty */
		ht->Table[index]->keyList = NULL;
	}
}


/*---------------------------------Destructors----------------------------------*/

void destroyDataList(DataNode * startOfList){

	DataNode * temp = startOfList;
	while(startOfList!=NULL){
		temp = startOfList;
		startOfList = startOfList->next;
		free(temp);
	}

}


void destroyHashTable(HashTable * ht){

	for(int i=0 ; i<(ht->size);i++){
		
		KeyNode * kn = ht->Table[i]->keyList ,*temp ;

		while(kn!=NULL){
			destroyDataList(kn->dataList);
			temp = kn;
			kn = kn->next;
			free(temp);
		}

		free(ht->Table[i]);
	}
	free(ht->Table);
	free(ht);
}