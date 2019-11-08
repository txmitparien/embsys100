//Function Definition for a stack data structure.
//This stack can only 5 elements.

#include "stack.h"

#define SIZE 5

int array[SIZE];
int *arrayPtr;

void init(void){
	arrayPtr = &array[0];

} 

int push(int val){
	if(arrayPtr == &array[SIZE]){
		return -1;
	}else{
		*arrayPtr = val;
		arrayPtr++;
	}
        return 0;
}


int pop(int *val){
	//int valTemp = 0;
	if(arrayPtr == &array[0]){
		return -1;
	}else{
		arrayPtr--;
                *val = *arrayPtr;
		*arrayPtr = 0;
	}
	return 0;
}