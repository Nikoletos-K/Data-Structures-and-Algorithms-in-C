#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../../include/Comparators.h"

int compare_ints(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

int compare_str(const void * str1,const void * str2){
    return strcmp((char*) str1,(char*) str2);
}

int compare_longs(const void * long1,const void * long2){
	return (*(long *) long1 - *(long *) long2);
}

int compare_floats(const void * float1,const void * float2){
	return (*(float *) float1 - *(float *) float2);
}
