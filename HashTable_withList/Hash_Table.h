#define empty NULL

typedef unsigned int keyType;
typedef struct HashTableNode HashNode;
typedef char InfoType;
typedef struct Data DataNode;
typedef struct Key KeyNode;

typedef struct HashTable {
	unsigned int size;
	HashNode **Table;	
}HashTable;

typedef struct HashTableNode{
	KeyNode * keyList;
}HashNode;

typedef struct Key{
	keyType key;
	DataNode * dataList;		/*Pointer to voter list */
	KeyNode * next;				/*Next key ,if hash table collision */
}KeyNode;

typedef struct Data{
	InfoType * data;
	DataNode * next;
}DataNode;


/*---------Create_Functions-------------*/

HashTable * createHashTable(int size);
KeyNode * createKeyNode(keyType key);
DataNode * createDataNode(InfoType * newdata);


/*-------------Insert_Functions-----------------*/

void HashInsert(HashTable * ht,keyType key,InfoType * info);
KeyNode * insertNewKey(HashNode * hn , keyType key);
void insertData(KeyNode * key,InfoType * newdata);


/*------------Getters-----------------*/

keyType getKey(KeyNode * keyList);
unsigned int hashCode(HashTable * ht,keyType key);

/*--------------Search_function-------------------*/

KeyNode * findKeyNode(HashTable * ht,keyType key);

/*----------Remove_functions------------------*/

void RemoveDataFromHT(HashTable * ht,InfoType * rmData,keyType key);
void RemoveKeyFromHT(HashTable * ht , keyType key);


/*------------------Destructors----------------*/

void destroyDataList(DataNode * startOfList);
void destroyHashTable(HashTable * ht);
