#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			
#include "./../include/maxHeap.h"

void test_create(void) {

	Heap * heap = heapConstruct();

	TEST_ASSERT(heap != NULL);
	TEST_ASSERT(heap->root == NULL);
	TEST_ASSERT(heap->size == 0);
	
	destroyHeap(heap);
}

void test_createNode(void) {

	int data = 10; 
	heapNode * node = create_heapNode((void*) &data);

	TEST_ASSERT(node != NULL);
	TEST_ASSERT(node->parent == NULL);
	TEST_ASSERT(node->leftChild == NULL);
	TEST_ASSERT(node->rightChild == NULL);
	
	TEST_ASSERT(compare_ints((void*) node->value , (void*) &data) == 0);

	free(node);
}

void test_insert(void) {
	
	Heap * heap = heapConstruct();
	
	int N = 10;
	int** array = malloc(N * sizeof(int*));	


	for (int i = N,j=0; i > 0; i--,j++) {
		array[j] = malloc(sizeof(int));
		*array[j] = i; 
		insert_toHeap(heap,(void*) array[j],compare_ints);
	}
	
	
	int * value;
	for (int i = 0; i < N; i++){

		value = (int *) extractMax_fromHeap(heap,compare_ints);
		TEST_ASSERT(*value == N-i);
	}


	for (int i = 0; i < N; i++)
		free(array[i]);
	free(array);

	destroyHeap(heap);
}

TEST_LIST = {
	{ "create Heap", test_create },
	{ "insert_toHeap", test_insert },
	{ NULL, NULL } 
};