#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			
#include "./../include/HeapSort.h"


void test_heapsort(void) {
	
	int N = 10;
	int** array = malloc(N * sizeof(int*));	

	for (int i = N,j=0; i > 0; i--,j++) {
		array[j] = malloc(sizeof(int));
		*array[j] = i; 
	}
	
	heapsort((void**)array,N,compare_ints);

	for (int i = 0; i < N; i++)
		TEST_ASSERT(*array[i] ==  i+1);

	for (int i = 0; i < N; i++)
		free(array[i]);
	free(array);
}


TEST_LIST = {
	{ "heapsort", test_heapsort },
	{ NULL, NULL } 
};