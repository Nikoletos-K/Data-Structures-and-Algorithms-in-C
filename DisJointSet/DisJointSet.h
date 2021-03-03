/*  Based on book Introduction to Algorithms ,Thomas H. Cormen (p. 566 - Greek edition)*/
#pragma once
#include <stdio.h>

typedef struct DisJointSet {

	size_t size;
	int * rankArray;
	int * parentArray;
	void ** objectArray;

} DisJointSet;

/* Constructor */
DisJointSet * DJSConstruct(int set_size,void ** objectArray);

/* Methods */
void DJSUnion(DisJointSet * dsjSet,int x,int y);
void DJSConnect(DisJointSet * dsjSet,int x,int y);
int DJSFindParent(DisJointSet * dsjSet,int x);

/* Getters */
int DJSgetRank(DisJointSet * dsjSet,int x);
int DJSgetParent(DisJointSet * dsjSet,int x);

/* Setters */
void DJSsetParent(DisJointSet * dsjSet,int x,int newparent);
void DJSsetRank(DisJointSet * dsjSet,int x,int newrank);

/* Destructor */
void DJSDestructor(DisJointSet * dsjSet);