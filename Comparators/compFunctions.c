#include <stdio.h>
#include <string.h>

#include "compFunctions.h"
#include "utils.h"

int compareStrings(void * str1,void * str2){

	return strcmp((char *) str1, (char*) str2);
} 

int compareIntegers(void * int1,void * int2){

	return (*(int *) int1 - *(int *) int2);
}


int compareLongs(void * long1,void * long2){

	return (*(long *) long1 - *(long *) long2);
}

int compareFloats(void * float1,void * float2){

	return (*(float *) float1 - *(float *) float2);
}

int compare(void * rec1,void * rec2,sortingColumn columnid){

	switch(columnid){
		case sortIds :
			return compareLongs( &(((Record*) rec1)->identityNumber), &(((Record*) rec2)->identityNumber));
		case sortFName:
			return compareStrings(((Record*) rec1)->firstName , ((Record*) rec2)->firstName );
		case sortLName:
			return compareStrings(((Record*) rec1)->lastName , ((Record*) rec2)->lastName );
		case sortStreet:
			return compareStrings(((Record*) rec1)->street , ((Record*) rec2)->street );
		case sortHouseId:
			return compareLongs( &(((Record*) rec1)->houseID), &(((Record*) rec2)->houseID));
		case sortCity:
			return compareStrings(((Record*) rec1)->city , ((Record*) rec2)->city );
		case sortPC:
			return compareStrings(((Record*) rec1)->postCode , ((Record*) rec2)->postCode);
		case sortAmount:
			return compareFloats(&(((Record*) rec1)->amount), &(((Record*) rec2)->amount));
		default:
			printf("Column %d doesn't fit to the 8 available\n", columnid );
			return -1;
	}

}

// Exchange is a swap function
void exchange(void ** array,int pos1,int pos2){

	void * temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;

}