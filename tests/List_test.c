#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			
#include "./../include/List.h"


int compare_ints(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

void test_create(void) {

	List *list = createList();

	TEST_ASSERT(list != NULL);
	TEST_ASSERT(list->firstNode == NULL);
	TEST_ASSERT(list->lastNode == NULL);
	TEST_ASSERT(list->numOfNodes == 0);
	
	deleteList(list);
}

void test_createNode(void) {

	int data = 10; 
	listNode * node = create_listNode((void*) &data);

	TEST_ASSERT(node != NULL);
	TEST_ASSERT(compare_ints((void*) node->data , (void*) &data) == 0);

	free(node);
}

void test_insert(void) {
	
	List *list = createList();
	
	int N = 10;
	int* array = malloc(N * sizeof(*array));	

	/* inserting elements to list */
	for (int i = 0; i < N; i++) {

		insert_toList(list, (void *)  &array[i]);

		/* checking if couner informs */
		TEST_ASSERT(list->numOfNodes == (i + 1));	
	}

	listNode* node = list->firstNode;

	for (int i = 0; i < N; i++) {

		/* checking if data are stored succesfully into list */
		TEST_ASSERT(node->data == (void*)  &array[i]);	
		node = node->nextNode;
	}

	deleteList(list);
	free(array);
}

void test_one_node_list(void){
	List *list = createList();

	int data = 10;
	insert_toList(list,(void*) &data);
	TEST_ASSERT(list->numOfNodes==1);
	TEST_ASSERT(oneNodeList(list) == 1);

	int data2 = 12;
	insert_toList(list,(void*) &data2);
	TEST_ASSERT(oneNodeList(list) != 1);

	deleteList(list);
}

TEST_LIST = {
	{ "createList", test_create },
	{ "insert_toList", test_insert },
	{ "oneNodeList",test_one_node_list},
	{ NULL, NULL } 
};