#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../../include/RBTree.h"

RBTNode * GUARD;
/*---------------------------------Create_Functions-------------------------------------------*/
void initializeDataStructures(){
	GUARD = createGuard();
}


RBTNode * createGuard(){

	RBTNode * temp = malloc(sizeof(RBTNode));
	temp -> parent = temp;
	temp -> left = temp;
	temp -> right = temp;			/* Guard:GLOBAL POINTER with color istead of NULL */
	temp->data = NULL;
	temp->key = NULL;
	temp->color = BLACK ;
	return temp;

}


RBTNode * RBTConstruct(){ 
	return GUARD;
}

RBTNode * RBTnewNode(void * data,valueType key){

	RBTNode * tempNode = malloc(sizeof(RBTNode));
	tempNode->parent=GUARD;
	tempNode->right=GUARD;
	tempNode->left=GUARD;
	tempNode->data = data;
	tempNode->color = RED;
	RBTInitialiseKey(tempNode,key);

	return tempNode;	
}

void RBTInitialiseKey(RBTNode * n,valueType key){

	n->key = strdup((char*)key);
}

/*------------------------------------- Getters -------------------------------------------*/


RBTNode * GetParent(RBTNode * n) {  return n -> parent; }

RBTNode * GetGrandParent(RBTNode * n) { return GetParent(n)->parent;}

nodeColor GetColor(RBTNode * n){ return n->color ; }

valueType GetKey(RBTNode * n){	return n->key; }

void SetColor(RBTNode * n,nodeColor color){ n->color=color; }

int RBTempty(RBTNode * root){ return (root == GUARD ); }

void * get_RBTData(RBTNode * node){	return (node==NULL ? NULL:node->data); }

/*----------------------Search_function---------------------------*/

RBTNode * RBTFindNode(RBTNode * node,valueType key,int (*comparator)(valueType,valueType)){

	if(node==GUARD || !(*comparator)(GetKey(node),key)){
		if(node==GUARD)
			return NULL;
		return node;
	}

	if((*comparator)(key,GetKey(node))<0)
		return RBTFindNode(node->left,key,comparator);
	else
		return RBTFindNode(node->right,key,comparator);

}

void RBTPrintTreeOnCondition(RBTNode * node,void (*printData)(void * data),int (*condition)(void*,char*)){

	if(node==GUARD)
		return;

	RBTPrintTreeOnCondition(node->left,printData,condition);
	if((*condition)(node->data,NULL))
		printData(node->data);
	RBTPrintTreeOnCondition(node->right,printData,condition);
}

void RBTPrintTree(RBTNode * node,void (*printData)(void * data)){

	if(node==GUARD)
		return;

	RBTPrintTree(node->left,printData);
	printData(node->data);
	RBTPrintTree(node->right,printData);

}

void RBTFindNodesBetweenKeys(RBTNode * node,int * counter,valueType key1,valueType key2,char * funValue,int (*comparator)(valueType,valueType),int (*function)(void*,char*)){
	
	if(node==GUARD)
		return;

	if(key1==NULL && key2==NULL){		// if keys are NULL

		RBTFindNodesBetweenKeys(node->left,counter,NULL,NULL,funValue,comparator,function);
		if((*function)(node->data,funValue))	// isolate and count specific tree nodes
			(*counter)++;			
		RBTFindNodesBetweenKeys(node->right,counter,NULL,NULL,funValue,comparator,function);
	
	}else{

		if((*comparator)((void*)key1,(void*)GetKey(node))>0)	// if key1 is greater that key of node => do CUTOFF and go right	

			RBTFindNodesBetweenKeys(node->right,counter,key1,key2,funValue,comparator,function);
		
		else if((*comparator)((void*)key2,(void*)GetKey(node))<0)		// if key2 is less that key of node => do CUTOFF and go left
		
			RBTFindNodesBetweenKeys(node->left,counter,key1,key2,funValue,comparator,function);
		
		else if((*comparator)((void*)key1,(void*)GetKey(node))<=0 || (*comparator)((void*)key2,(void*)GetKey(node))<=0){	// else if nodes key is between these values count it
		
			RBTFindNodesBetweenKeys(node->left,counter,key1,key2,funValue,comparator,function);
		
			if(funValue!=NULL){		// if there's and another constrain
				if(function(node->data,funValue))
					(*counter)++;	
			}else	// if there's no other constrain count all
				(*counter)++;
			
			RBTFindNodesBetweenKeys(node->right,counter,key1,key2,funValue,comparator,function);
		}
	}
}



/*--------------------------- Rotations -----------------------------*/

void RotateLeft(RBTNode **treeRoot,RBTNode * x){

	RBTNode * y = x->right;				
	x->right = y->left;

	if(y->left != GUARD)
		y->left->parent = x;

	y->parent = GetParent(x);

	if(GetParent(x) == GUARD)
		*treeRoot = y;
	else if(x == GetParent(x)->left)
		x->parent->left = y;
	else 
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void RotateRight(RBTNode **treeRoot,RBTNode * x){

	RBTNode * y = x->left;
	x->left = y->right;

	if(y->right != GUARD)
		y->right->parent = x;

	y->parent = GetParent(x);

	if(GetParent(x) == GUARD)
		*treeRoot = y;
	else if( x ==GetParent(x)->right )
		x->parent->right = y;
	else
		x->parent->left = y;


	y->right = x;
	x-> parent = y;
}


/*-----------------------------------Insert_Function-------------------------------------*/


void RBTInsert(RBTNode **treeRoot,void * data,valueType key,int (*comparator)(valueType,valueType)){

	RBTNode * z = RBTnewNode(data,key);
	RBTNode * y = GUARD;
	RBTNode * x = *treeRoot;

	while(x!=GUARD){
		y  = x;
		if((*comparator)(GetKey(z),GetKey(x))<=0 )				/*For alphabetical tree :(*comparator)*/
			x = x->left;
		else if((*comparator)(GetKey(z),GetKey(x))>0 )
			x = x->right;
	}

	z->parent = y; 
	if(y==GUARD)
		*treeRoot  = z;
	else if((*comparator)(GetKey(z),GetKey(y))<=0)
		y->left  = z;
	else if((*comparator)(GetKey(z),GetKey(y))>0)
		y->right = z;

	RBTInsertFixUP(treeRoot,z);								/*Fix any possible violation of colors and balance the tree */

}

void RBTInsertFixUP(RBTNode **treeRoot,RBTNode * z){

	RBTNode * y;
	while(GetColor(GetParent(z)) == RED){					/*iterate z's parent color is red*/

		if(GetParent(z) == GetGrandParent(z)->left){

			y = GetGrandParent(z)->right;					/*Find uncle and store it in y */

			if(GetColor(y) == RED){							/*Case 1: Uncle is red ->RECOLOR*/				

				SetColor(GetParent(z),BLACK);				//Change color of parent and uncle as BLACK
				SetColor(y,BLACK);
				SetColor(GetGrandParent(z),RED);			//Change color of grandparent as RED
				z = GetGrandParent(z);						//Move z to grandparent

			}else{											/*Case 2:Uncle is black*/

				if(z == GetParent(z)->right){				//If z is on the right 
					z = GetParent(z);						//Move z to his parent
					RotateLeft(treeRoot,z);					//Left rotate z
				}
															/*Case 2:Uncle is black and z is on the left ->RECOLOR */
				SetColor(GetParent(z),BLACK);				//Make parent black
				SetColor(GetGrandParent(z),RED);			//Make gparent Red
				RotateRight(treeRoot,GetGrandParent(z));	//Right Rotate
				
			} 
				
		}else{												/*As above , but changed left with right because there are symmetrical */

			y = GetGrandParent(z)->left;

			if(GetColor(y) == RED){

				SetColor(GetParent(z),BLACK);
				SetColor(y,BLACK);
				SetColor(GetGrandParent(z),RED);
				z = GetGrandParent(z);

			}else{
				if(z == GetParent(z)->left){
					z = GetParent(z);
					RotateRight(treeRoot,z);
				}

				SetColor(GetParent(z),BLACK);
				SetColor(GetGrandParent(z),RED);
				RotateLeft(treeRoot,GetGrandParent(z));
				
			} 
				

		}
	}
	SetColor(*treeRoot,BLACK);							/* Make root always BLACK !!!! */
}


/*-----------------------------------Delete_function-------------------------------------*/


void RBTReplaceNode(RBTNode **treeRoot,RBTNode * u,RBTNode * v){			/*Changing pointers*/

	if(GetParent(u)==GUARD)
		(*treeRoot) = v;
	else if( u == GetParent(u)->left)
		GetParent(u)->left = v;
	else
		GetParent(u)->right = v;


	v->parent = GetParent(u);
}

void RBTRemoveNode(RBTNode **treeRoot , RBTNode * z){

	RBTNode  * y = z ,* x ;

	nodeColor color = GetColor(y);			

	if(z->left == GUARD){					/* If node is a leaf just remove him and fix the pointers */
		
		x =z->right;
		RBTReplaceNode(treeRoot,z,z->right);

	}else if(z->right == GUARD){			/*As above */

		x = z->left;
		RBTReplaceNode(treeRoot,z,z->left);
	
	}else{

		y = z->right;					/* Go to the right and find the minimum node - as in as simple bst removal */
		while(y->left !=GUARD)
			y = y->left;

		color = GetColor(y);

		x = y->right;					/* Exchange with x */

		if(GetParent(y) == z)			/* If y is the child of z just replace them */
			x->parent = y;
		else{									
			RBTReplaceNode(treeRoot,y,y->right);		/* if no then fix the pointers and set data of the correct node */
			y->right = z->right;
			y->right->parent = y;
		}

		RBTReplaceNode(treeRoot,z,y);


		y->left = z->left;
		y->left->parent = y;
		SetColor(y,GetColor(z));			/* y is in the correct position initialize it's values from z */

	}

	RBTDestroyNode(z);				/* Delete the node that we wanted to delete */
	if(color == BLACK)
		RBTDeletionFixUP(treeRoot,x);		/* Fix Violations */

}

void RBTDeletionFixUP(RBTNode **treeRoot,RBTNode * x){

	while(x != *treeRoot && GetColor(x)==BLACK){

		if(x == GetParent(x)->left){

			RBTNode * w = GetParent(x)->right;
		
			if(GetColor(w)==RED){			/*Case 1: if sibling is red just recolor w and it's parent and do a rotation */

				SetColor(w,BLACK);
				SetColor(GetParent(x),RED);
				RotateLeft(treeRoot,GetParent(x));
				w = GetParent(x)->right;

			}

			if(GetColor(w->left)==BLACK 			/*Case 2: if sibling of x is black and both of w children are black*/
				&& GetColor(w->right)==BLACK){

				SetColor(w,RED);					//Recolor w
				x = GetParent(x);					//Change x

			}else {

				
				if(GetColor(w->right)==BLACK){		/*Case 3: if sibling of x is red and right child of w is black and left child is red*/

					SetColor(w->left,BLACK);
					SetColor(w,RED);
					RotateRight(treeRoot,w);
					w = GetParent(x)->right;
				}

				SetColor(w,GetColor(GetParent(x)));		/* Case 4 : if sibling of x is red and right child of w is black */
				SetColor(GetParent(x),BLACK);
				SetColor(w->right,BLACK);
				RotateLeft(treeRoot,GetParent(x));
				x = *treeRoot;
			}

		}else{											/* As above  because cases are symmetrical */

			if(x == GetParent(x)->right){

				RBTNode * w = GetParent(x)->left;
			
				if(GetColor(w)==RED){
					
					SetColor(w,BLACK);
					SetColor(GetParent(x),RED);
					RotateRight(treeRoot,GetParent(x));
					w = GetParent(x)->left;
				}

				if( GetColor(w->right)==BLACK && GetColor(w->left)==BLACK){

					SetColor(w,RED);
					x = GetParent(x);

				}else {

					if(GetColor(w->left)==BLACK){

						SetColor(w->right,BLACK);
						SetColor(w,RED);
						RotateLeft(treeRoot,w);
						w = GetParent(x)->left;
					}

					SetColor(w,GetColor(GetParent(x)));
					SetColor(GetParent(x),BLACK);
					SetColor(w->left,BLACK);
					RotateRight(treeRoot,GetParent(x));
					x = *treeRoot;
				}

			}

		
		}	
	}
	SetColor(x,BLACK);				/* Always set x as black , because if loop stop , it may x be the root an root must always be black */
}



/*---------------------------------Destructors----------------------------------*/


void RBTDestroyNode(RBTNode * node){
	free((void*)node->key);
	free(node);
}


void destroyGuard(){
	free(GUARD);
	GUARD=NULL;
}


void RBTDestroyTree(RBTNode * treeRoot){
	
	RBTDestroyAllNodes(treeRoot);
}

void RBTDestroyAllNodes(RBTNode * treeRoot){

	if(treeRoot == GUARD)
		return;

	RBTDestroyAllNodes(treeRoot->left);
	RBTDestroyAllNodes(treeRoot->right);

	RBTDestroyNode(treeRoot);
}

void destroyDataStructures(){
	destroyGuard();
}

void RBTDestroyTreeAndData(RBTNode * treeRoot,void (*destructor)(void * data)){

	if(treeRoot == GUARD)
		return;

	RBTDestroyTreeAndData(treeRoot->left,destructor);
	RBTDestroyTreeAndData(treeRoot->right,destructor);

	(*destructor)(treeRoot->data);
	RBTDestroyNode(treeRoot);

}