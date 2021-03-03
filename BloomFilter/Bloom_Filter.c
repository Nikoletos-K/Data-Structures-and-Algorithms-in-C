#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bloom_Filter.h"
#include "Hash_Functions.h"

unsigned int size_of_bitArray(unsigned int numOfVoters){

	unsigned int size = firstPrime(3*(numOfVoters),4*(numOfVoters));		/*first prime number after 3*numofVoters */
	return size;
}


BF * createBF(unsigned int numOfVoters){

	BF * tempBF = malloc(sizeof(BF));
	tempBF->size = size_of_bitArray(numOfVoters);								/* I need prime(3*numofvoters) bit , so I allocate this number/8+1 * 8 bit */
	tempBF->bitArray = calloc((tempBF->size/8+1),sizeof(char));					/* Because char is 1 byte = 8 bit */

	return tempBF;
}

void setBit(BF * bf,int hash){

	int i = hash / 8;								/* Find in which position of the array it is */
	int pos = hash % 8;								/* Find in which position of the char it is the specific bit */
	unsigned int flag=1;							/* flag = 00000...00001 */
	flag = flag << pos; 								/* Shift it until I find the position of the bit */
	bf->bitArray[i] = bf->bitArray[i] | flag;			/* OR betxeen them , because 0 OR 1 = 1 and 0 OR 0 = 0 */
}


int checkBit(BF * bf,unsigned int hash){				/* Same method as above */
	
	int bin=0;
	int i=hash/8;
	int pos=hash%8;

	unsigned int flag=1;
	flag=flag << pos;

	if(bf->bitArray[i] & flag)
		bin=1;

	return bin;
}


void insertBF(BF * bf,unsigned int length, char * identity){

		unsigned int hash1,hash2,hash3;

		hash1=hashFunction_1(identity,length)%bf->size;				/* Hash = hash1 % size , that gives me the position i xill enter the bit in the BF */
		setBit(bf,hash1);

		hash2=hashFunction_2(identity,length)%bf->size;				/* Same */
		setBit(bf,hash2);

		hash3=hashFunction_3(identity,length)%bf->size;			
		setBit(bf,hash3);

}


int checkBF(BF * bf,unsigned int length, char * identity){

	int flag=0;
	unsigned int hash1,hash2,hash3;
	hash1=hashFunction_1(identity,length)%bf->size;
	hash2=hashFunction_2(identity,length)%bf->size;
	hash3=hashFunction_3(identity,length)%bf->size;	

	if(checkBit(bf,hash1))								/* It has to be all equal to 1 */
		if(checkBit(bf,hash2))
			if(checkBit(bf,hash3))
				flag=1;
	

	return flag;	

}

void destroyBF(BF * bf){

	free(bf->bitArray);
	free(bf);
}
