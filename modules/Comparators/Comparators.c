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


// Date format: dd-mm-yyyy
int compare_dates(const  void * date1,const void * date2){

	char * d1 = (char*) date1;
	char * d2 = (char*) date2;

	if(!strcmp(date2,"--"))
		return 0;

	char *token;
	int d[2],m[2],y[2];

	for(int i=0;i<2;i++){
		int t=0;
		char buffer[20];
		if(i==0) strcpy(buffer,d1);
		else     strcpy(buffer,d2);

		token = strtok(buffer,"-");
		while(token!=NULL){
			if(t==0)		d[i] = atoi(token);
			else if(t==1)	m[i] = atoi(token);
			else if(t==2)	y[i] = atoi(token);
			token = strtok(NULL,"-");
			t++;
		}
	}

	if(y[0]>y[1])
		return 1;
	else if(y[0]<y[1])
		return -1;
	else{
		if(m[0]>m[1])
			return 1;
		else if(m[0]<m[1])
			return -1;
		else{
			if(d[0]>d[1])
				return 1;
			else if(d[0]<d[1])
				return -1;
			else
				return 0;
		}
	}
}
