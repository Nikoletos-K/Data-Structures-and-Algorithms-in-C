#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"			
#include "./../include/HashFunctions.h"


void prime_test(void){
	
	unsigned int min = 10;
	unsigned int max = 50;
	unsigned int prime = firstPrime(min,max);

	TEST_ASSERT(prime == 11);
}

void HashFunctions_test(void){
	
	char* str = "abcdefghijklmnopqrstuvwxyz1234567890";

	unsigned int hash =  StringHashFunction_RS(str);
	TEST_ASSERT(hash > 0);
	hash =  StringHashFunction_BKDR(str);
	TEST_ASSERT(hash > 0);
	hash =  StringHashFunction_DEK(str);
	TEST_ASSERT(hash > 0);
}

TEST_LIST = {
	{ "prime_test", prime_test },
	{ "HashFunctions_test", HashFunctions_test },
	{ NULL, NULL } 
};