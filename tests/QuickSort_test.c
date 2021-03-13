#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			
#include "./../include/QuickSort.h"


void test_quicksort(void) {
	
	int N = 10;
	int** array = malloc(N * sizeof(int*));	

	for (int i = N,j=0; i > 0; i--,j++) {
		array[j] = malloc(sizeof(int));
		*array[j] = i; 
	}
	
	quicksort((void**)array,0,N-1,compare_ints);

	for (int i = 0; i < N; i++)
		TEST_ASSERT(*array[i] ==  i+1);

	for (int i = 0; i < N; i++)
		free(array[i]);
	free(array);
}


TEST_LIST = {
	{ "quicksort", test_quicksort },
	{ NULL, NULL } 
};