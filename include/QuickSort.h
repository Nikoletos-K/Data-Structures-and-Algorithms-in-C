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

#include "./Comparators.h"		// we need Comparators

void quicksort(void ** array,int p,int r,int (*compare)(const void*,const void*));
int partition(void ** array,int p,int r,int (*compare)(const void*,const void*));