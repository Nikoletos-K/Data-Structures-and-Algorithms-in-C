/*
 **************************************************************************
 * Author: Konstantinos Nikoletos                                         *
 * URL: http://github.com/Nikoletos-K                                     *
 *                                                                        *
 * Copyright notice:   													                          *
 * Free use this code is permitted under the guidelines 				          *
 * and in accordance with the MIT License. 						  	                * 
 *                                                                        *
 **************************************************************************
*/
#pragma once

#define empty NULL


int compare_ints(const void * a, const void * b);
int compare_str(const void * str1,const void * str2);
int compare_longs(const void * long1,const void * long2);
int compare_floats(const void * float1,const void * float2);
int compare_dates(const  void * date1,const void * date2);  // dd-mm-yyyy
