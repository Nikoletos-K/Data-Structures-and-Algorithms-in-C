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

void exchange(void ** array,int pos1,int pos2);

/* Getters */
int getLeft(int i);
int getRight(int i);
int getParent(int i);

/* Heap main utility */
void buildMaxHeap(void ** array,int heapSize,int (*compare)(const void*,const void*));
void maxHeapify(void ** array,int heapSize,int i,int (*compare)(const void*,const void*));
void heapsort(void ** array,int heapSize,int (*compare)(const void*,const void*));