#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../../include/HashFunctions.h"

unsigned int firstPrime(unsigned int min,unsigned int max){

	int flag;
	unsigned int div,n;
	for(n=min;n<max;n++){
		if(n%2==0) continue;
		if(n%3!=0){													 
			flag=1;
			div=5;														
			while(flag==1 && div*div<=n){									
				if(n%div==0 || n%(div+2)==0)	flag=0;			
				else	div=div+6;								  												
			}	
			if(flag)	break;									
		}	
	}
	return n;	
}


unsigned int StringHashFunction_RS(char * str){

	unsigned int length = strlen(str);
	unsigned int b    = 378551;
	unsigned int a    = 63689;
 	unsigned int hash = 0;
 	unsigned int i    = 0;
 
 	for (i = 0; i < length; ++str, ++i){

      hash = hash * a + (*str);
      a    = a * b;
      
	}

	return hash;
}


unsigned int StringHashFunction_BKDR(char * str){

	unsigned int length = strlen(str);
	unsigned int seed = 131; 
	unsigned int hash = 0;
	unsigned int i=0;

	for (i = 0; i < length; ++str, ++i){

		hash = (hash * seed) + (*str);
	}

   return hash;
}

unsigned int StringHashFunction_DEK(char * str){

	unsigned int length = strlen(str);
	unsigned int hash = 0;
	unsigned int i=0;

	for (i=0; i<length ; i++){
		hash=(hash << 5) | (hash >> 27);
		hash += (unsigned int) str[i];
	}

	return hash;

}

/*
 * Copyright notice: All rights reserved to:                                                      *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
*/