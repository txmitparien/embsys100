//Assignment04, Problem#3
//This code will test a stack data structure which is LIFO structure.
//Please see stack.h and stack.c for the stack structure implementation

#include <assert.h>
#include "stack.h"

void main(void){
  int result;
  int num = -2;
  
  init();       //Initialize the pointer to point to the stack's address
  
  result = push(1);     //push value into a stack
  assert(result == 0);
//  result = push(2);
//  assert(result == 0);
//  result = push(3);
//  assert(result == 0);
//  result = push(4);
//  assert(result == 0);
//  result = push(5);
//  assert(result == 0);
//  result = push(6);
//  assert(result == 0);

  result = pop(&num);   //pop value out of a stack
  assert(result == 0);
  assert(num == 1);
  result = pop(&num);
  assert(result == 0);
  result = pop(&num);
  assert(result == 0);
  result = pop(&num);
  assert(result == 0);
  result = pop(&num);
  assert(result == 0);
  result = pop(&num);
  assert(result == 0);
}
