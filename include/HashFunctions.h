/*
 **************************************************************************
 * Author: Konstantinos Nikoletos                                         *
 * URL: http://github.com/Nikoletos-K                                     *
 *                                                                        *
 * Copyright notice:   													  *
 * Free use this code is permitted under the guidelines 				  *
 * and in accordance with the MIT License. 						  	      * 
 *                                                                        *
 **************************************************************************
*/
#pragma once


/* Function for finding the first prime number inside [min,max] */
unsigned int firstPrime(unsigned int min,unsigned int max);

/* String hashing */
unsigned int StringHashFunction_RS(char * str);
unsigned int StringHashFunction_BKDR(char * str);
unsigned int StringHashFunction_DEK(char * str);

