#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"
#include "./../include/Queue.h"

void test_create(void) {

	Queue* queue= createQueue();

	TEST_ASSERT(queue!= NULL);
	TEST_ASSERT(queue->firstNode == NULL);
	TEST_ASSERT(queue->lastNode == NULL);
	TEST_ASSERT(queue->numOfNodes == 0);
	
	deleteQueue(queue);
}

void test_createNode(void) {

	int data = 10; 
	queueNode * node = create_queueNode((void*) &data);

	TEST_ASSERT(node != NULL);

	free(node);
}

void test_insert(void) {
	
	Queue* queue= createQueue();
	
	int N = 10;
	int* array = malloc(N * sizeof(*array));	

	/* inserting elements to queue*/
	for (int i = 0; i < N; i++) {

		QueuePush(queue, (void *)  &array[i]);

		/* checking if couner informs */
		TEST_ASSERT(queue->numOfNodes == (i + 1));	
	}

	queueNode* node = queue->firstNode;

	for (int i = 0; i < N; i++) {

		/* checking if data are stored succesfully into queue*/
		TEST_ASSERT(node->data == (void*)  &array[i]);	
		node = node->nextNode;
	}

	deleteQueue(queue);
	free(array);
}

TEST_LIST = {
	{ "createQueue", test_create },
	{ "createNode", test_createNode },
	{ "QueuePush", test_insert },
	{ NULL, NULL } 
};