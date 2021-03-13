#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/HashTable_withBucketstoRBT.h"

/*--------------------------- Constructors ----------------------------*/

HashTable * create_HashTable(size_t hashtableSize,size_t bucketSize){


	if(bucketSize<sizeof(HTRecord)){
		printf("\tERROR: Very small bucketSize , hashtable didn't create! \n");
		return NULL;
	}

	HashTable * ht = malloc(sizeof(HashTable));
	ht->hashtableSize = hashtableSize;
	ht->bucketSize = bucketSize;
	ht->numOfRecords = 0;
	ht->buckets = malloc(hashtableSize*sizeof(Bucket*));
	for(int i=0;i<hashtableSize;i++)
		ht->buckets[i]=NULL;
	ht->records_perBucket = (ht->bucketSize)/sizeof(HTRecord);
	return ht;
}


Bucket * createBucket(size_t bucketSize){

	Bucket * temp = malloc(sizeof(Bucket));
	temp->records = 0;
	temp->bucketMemory = malloc(bucketSize);
	temp->next = NULL;
	return temp;
}

HTRecord * createHTRecord(char * key){

	HTRecord  * htr = malloc(sizeof(HTRecord));
	htr->key = key;
	htr->value = (void *) RBTConstruct();
	htr->counter = 0;

	return htr;
}

/* ------------------------------- Insertions ------------------------------*/

int insertRecord(void * htRecord,Bucket * bucket){		//inserts record to bucket

	int offset = bucket->records;
	memmove(bucket->bucketMemory+offset*sizeof(HTRecord),htRecord,sizeof(HTRecord));
	free(htRecord);
	bucket->records++;

	return NO_ERROR;
}


int insert_toHashTable(void * value,char * HTkey,char * treeKey,HashTable * ht,int (*comparator)(comparatorValue,comparatorValue)){
	
	unsigned int hash = StringHashFunction_RS(HTkey)%(ht->hashtableSize);

	if(ht->buckets[hash]==NULL){		/* when bucket hasn't been created */	

		ht->buckets[hash] = createBucket(ht->bucketSize);
		HTRecord * htrecord = createHTRecord(HTkey);
		increaseCounter(htrecord);
		RBTNode * root = (RBTNode *) getValue(htrecord);
		RBTInsert(&root,value,treeKey,comparator);
		htrecord->value = (void*)root;
		insertRecord(htrecord,ht->buckets[hash]);
		ht->numOfRecords++;

	}else{		/* case that bucket has been created */

		int loops = 0,found = 0;
		HTRecord * tempRecord;
		char * tempKey;
		Bucket * tempBucket = ht->buckets[hash],*wantedBucket;

		while(tempBucket!=NULL){	/* search the list of buckets */

			tempRecord = (HTRecord *) tempBucket->bucketMemory;
			tempKey = tempRecord->key;
			wantedBucket = tempBucket;

			while(loops<tempBucket->records){		/* search inside buckets */
					
				if(!comparator(HTkey,tempKey)){
					found=1;
					break;
				}

				if(loops < tempBucket->records-1){
					tempRecord++;
					tempKey = tempRecord->key;					
				}
				loops++;
			}

			if(found)
				break;

			wantedBucket = tempBucket;
			tempBucket = tempBucket->next;
			loops=0;
		}

		if(found){		/* if tree record found add to the tree */
		
			RBTNode * treeRoot = (RBTNode *) getValue(tempRecord);
			increaseCounter(tempRecord);
			RBTInsert(&treeRoot,value,treeKey,comparator);
			tempRecord->value = treeRoot;
			memmove(tempBucket->bucketMemory+loops*sizeof(HTRecord),tempRecord,sizeof(HTRecord));			

		}else{		/* in this case this record doesn't exist */

			HTRecord * newRecord = createHTRecord(HTkey);
			ht->numOfRecords++;

			if(wantedBucket->records<ht->records_perBucket-1){ /* if it fits in the current bucket */

				increaseCounter(newRecord);
				RBTNode * treeRoot = (RBTNode *) getValue(newRecord);
				RBTInsert(&treeRoot,value,treeKey,comparator);
				newRecord->value = treeRoot;
				insertRecord(newRecord,wantedBucket);
	
			}else{	/* case that new bucket must be created */

				increaseCounter(newRecord);
				Bucket * newBucket = createBucket(ht->bucketSize); 
				wantedBucket->next = newBucket;
				RBTNode * root = (RBTNode *) getValue(newRecord);
				RBTInsert(&root,value,treeKey,comparator);
				newRecord->value = root;
				insertRecord(newRecord,newBucket);
			}
		}
	}
	return NO_ERROR;	
}

void * getValue(HTRecord * record){ return record->value;}

int getCounter(HTRecord * record){ return record->counter;}

void increaseCounter(HTRecord * record){record->counter++;}

int getNumOfRecords(HashTable * ht){return ht->numOfRecords;}

void numOfRecordsBetweenKeys(HashTable * hashtable,char * date1,char * date2,int (*comparator)(comparatorValue,comparatorValue)){

	int loops = 0,totalNumber=0;

	for(int i=0;i<hashtable->hashtableSize;i++){	// searches all hashtable

		if(hashtable->buckets[i]==NULL)
			continue;

		HTRecord * tempRecord;
		Bucket * tempBucket = hashtable->buckets[i];

		while(tempBucket!=NULL){	/* search the list of buckets */

			tempRecord = (HTRecord *) tempBucket->bucketMemory;

			while(loops<tempBucket->records){	/* search inside buckets */

				if(date1==NULL && date2==NULL){		/* if dates are not a restriction */
				#ifdef WITH_UI
					printf("\t- %s: %d \n",tempRecord->key,tempRecord->counter);
				#else
					printf("%s %d\n",tempRecord->key,tempRecord->counter);
				#endif
					totalNumber += tempRecord->counter;
				}else{		/* else read tree between these dates */
					int counter = 0;
					RBTNode * treeRoot = (RBTNode *) getValue(tempRecord);
					RBTFindNodesBetweenKeys(treeRoot,&counter,(void *) date1,(void *) date2,NULL,comparator,NULL);
					#ifdef WITH_UI
						printf("\t%s: %d \n",tempRecord->key,counter);
					#else
						printf("%s %d\n",tempRecord->key,counter);
					#endif
					totalNumber += counter;					
				}

				if(loops < tempBucket->records-1){
					tempRecord++;
				}
				loops++;
			}
			tempBucket = tempBucket->next;
			loops=0;
		}
	}
	#ifdef WITH_UI
		printf("\n\tTotal: %d \n",totalNumber);
	#endif
	
}

int findKeyData(HashTable * hashtable,char * wantedKey,char * date1,char * date2,int (*comparator)(comparatorValue,comparatorValue),char * funValue,int (*function)(void*,char*)){

	int loops = 0;
	int hash = StringHashFunction_RS(wantedKey)%(hashtable->hashtableSize);

	if(hashtable->buckets[hash]==NULL)
		return -1;

	HTRecord * tempRecord;
	Bucket * tempBucket = hashtable->buckets[hash];


	while(tempBucket!=NULL){	/* search the list of buckets */

		tempRecord = (HTRecord *) tempBucket->bucketMemory;

		while(loops<tempBucket->records){	/* search inside buckets */

			if(comparator(wantedKey,tempRecord->key)==0){		/* find specific hashtable key */
				int counter = 0;
				RBTNode * treeRoot = (RBTNode *) getValue(tempRecord);
				RBTFindNodesBetweenKeys(treeRoot,&counter,(void *) date1,(void *) date2,funValue,comparator,function);
				return counter;	
			}

			if(loops < tempBucket->records-1){
				tempRecord++;
			}
			loops++;
		}

		tempBucket = tempBucket->next;
		loops=0;
	}
	return ERROR;
}


void destroyHashTable(HashTable * hashtable){	/* destroys all records,buckets and hashrable */

	int loops=0;
	for(int i=0;i<hashtable->hashtableSize;i++){

		if(hashtable->buckets[i]==NULL)
			continue;

		HTRecord * tempRecord;
		Bucket * tempBucket = hashtable->buckets[i],*delBucket;


		while(tempBucket!=NULL){	/* search the list of buckets */

			tempRecord = (HTRecord *) tempBucket->bucketMemory;

			while(loops<tempBucket->records){	/* search inside buckets */

				RBTNode * treeRoot = (RBTNode *) getValue(tempRecord);
				RBTDestroyAllNodes(treeRoot);
				if(loops < tempBucket->records-1)
					tempRecord++;
				
				loops++;
			}
			delBucket = tempBucket;
			free(tempBucket->bucketMemory);
			tempBucket = tempBucket->next;
			loops=0;
			free(delBucket);
		}
	}
	free(hashtable->buckets);
	free(hashtable);
}