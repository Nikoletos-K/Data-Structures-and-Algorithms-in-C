/*
 **************************************************************************
 * Author: Konstantinos Nikoletos                                         *
 * URL: http://github.com/Nikoletos-K                                     *
 *                                                                        *
 * Copyright notice:   							  *
 * Free use this code is permitted under the guidelines 		  *
 * and in accordance with the MIT License. 				  * 
 *                                                                        *
 **************************************************************************
*/
#pragma once

#include "./HashFunctions.h"

typedef struct BloomFilter{

	char * bitArray;
	unsigned int size;

}BF;

// Get size
unsigned int size_of_bitArray(unsigned int numOfVoters);

// BloomFilter functions
BF * createBF(unsigned int size);
void insertBF(BF * bf, char * identity);
int checkBF(BF * bf, char * identity);
void destroyBF(BF * bf);

// Bit-Array functions
void setBit(BF * bf,int hash);
int checkBit(BF * bf,unsigned int hash);
