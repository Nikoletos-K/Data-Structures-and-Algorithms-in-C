#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/acutest.h"
#include "./../include/Comparators.h"

/* ----- Comparator testing ------ */


void test_comparators(void){

	int small=1,big=2;
	TEST_ASSERT(compare_ints((void*)&small,(void*)&big)<0);

	char * a = "a";
	char * b = "b";
	TEST_ASSERT(compare_str((void*)a,(void*)b) == strcmp(a,b));
}


TEST_LIST = {
	{"comparators",test_comparators},
	{ NULL, NULL }
};