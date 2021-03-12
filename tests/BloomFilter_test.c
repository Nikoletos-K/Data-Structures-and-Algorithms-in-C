#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			
#include "./../include/BloomFilter.h"


void test_create_bitArray(void) {
	
	int size = 10;
	BF* bitArray = createBF(size);

	TEST_ASSERT(bitArray != NULL);
	TEST_ASSERT(bitArray->size != 0);
	
	destroyBF(bitArray);
}

void check_and_set_bitArray(void) {

	int size = 10;
	BF* bitArray = createBF(size);
	int hash = 5;

	setBit(bitArray,hash);
	int bin = checkBit(bitArray, hash);
	TEST_ASSERT(bin == 1);

	destroyBF(bitArray);
}


void set_and_check_BloomFilter(void) {

	int size = 10;
	BF* bloomFilter = createBF(size);
	TEST_ASSERT(bloomFilter != NULL);

	char * input_str = "abcde";
	char * no_input_str = "12345";


	insertBF(bloomFilter, input_str);

	int inside =  checkBF(bloomFilter, input_str);
	TEST_ASSERT(inside == 1); 	// this may fail as it's a probabilistic structure

	int not_inside =  checkBF(bloomFilter, no_input_str);
	TEST_ASSERT(not_inside == 0); 	// this must not fail

	destroyBF(bloomFilter);
}

TEST_LIST = {
	{ "createBF", test_create_bitArray },
	{ "checkBit and setBit to bitArray", check_and_set_bitArray },
	{ "insert and check - BloomFilter", set_and_check_BloomFilter },
	{ NULL, NULL } 
};