#include <stdio.h>
#include <stdlib.h>

#include "./../../include/DisJointSet.h"



DisJointSet * DJSConstruct(int set_size,void ** objectArray){

	DisJointSet * dsjSet = malloc(sizeof(DisJointSet));
	dsjSet->size = set_size;
	dsjSet->rankArray = calloc(dsjSet->size ,sizeof(int));
	dsjSet->objectArray = objectArray;
	dsjSet->parentArray = malloc(dsjSet->size*sizeof(int));
	for(int i=0;i<set_size;i++)
		dsjSet->parentArray[i] = i;		// initialize the array with the same value as the index

	return dsjSet;
}

void DJSUnion(DisJointSet * dsjSet,int x,int y){

	DJSConnect(dsjSet,DJSFindParent(dsjSet,x),DJSFindParent(dsjSet,y));
}

void DJSConnect(DisJointSet * dsjSet,int x,int y){

	if(DJSgetRank(dsjSet,x) > DJSgetRank(dsjSet,y)) // the one with greater rank
			DJSsetParent(dsjSet,y,x);				// is parent of the other
	else{
		DJSsetParent(dsjSet,x,y);
		if(DJSgetRank(dsjSet,x) == DJSgetRank(dsjSet,y))
			DJSsetRank(dsjSet,y,DJSgetRank(dsjSet,y)+1);
	}
}

int DJSFindParent(DisJointSet * dsjSet,int x){

	if(x != DJSgetParent(dsjSet,x)) // find the root parent
		DJSsetParent(dsjSet,x,DJSFindParent(dsjSet,DJSgetParent(dsjSet,x)));

	return DJSgetParent(dsjSet,x);
}

int DJSgetRank(DisJointSet * dsjSet,int x){
	return dsjSet->rankArray[x];
}

int DJSgetParent(DisJointSet * dsjSet,int x){
	return dsjSet->parentArray[x];
}

void DJSsetRank(DisJointSet * dsjSet,int x,int newrank){
	dsjSet->rankArray[x] = newrank;
}

void DJSsetParent(DisJointSet * dsjSet,int x,int newparent){
	dsjSet->parentArray[x] = newparent;
}

void DJSDestructor(DisJointSet * dsjSet){

	free(dsjSet->rankArray);
	free(dsjSet->parentArray);
	free(dsjSet);

}