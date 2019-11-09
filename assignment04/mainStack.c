//Assignment04, Problem#3
//This code will test a stack data structure which is LIFO structure.
//Please see stack.h and stack.c for the stack structure implementation
//There are 5 test cases in this code. Please uncomment the test case, you're 
//wish to test and comment the rest of the test cases.

#include <assert.h>
#include "stack.h"

void main(void){
  int result;
  int num = -2;
  
  //Arrange;
  init();       //Initialize the pointer to point to the stack's address
  
  //Test case 1: Check for empty stack
  //Action
  result = pop(&num);
  //Assertion
  assert(num == -2);    //Expecting program to pass through
  assert(result == 0);  //Error out since pop() should return -1
  
//  //Test case 2: Full stack
//  //Action
//    result = push(1);     //push value into a stack
//    assert(result == 0);
//    result = push(2);
//    assert(result == 0);
//    result = push(3);
//    assert(result == 0);
//    result = push(4);
//    assert(result == 0);
//    result = push(5);
//    assert(result == 0);
//    result = push(6);
//    assert(result == 0);      //It should error out here since push() should
//                              //return -1;
//  
//  //Test case 3: push() to full stack and pop() the entire stack
//  //Action   
//    result = push(1);     //push value into a stack
//  //Assertion
//    assert(result == 0);
//    result = push(2);
//    assert(result == 0);
//    result = push(3);
//    assert(result == 0);
//    result = push(4);
//    assert(result == 0);
//    result = push(5);
//    assert(result == 0);
//    
//  //Action
//    result = pop(&num);   //pop value out of a stack
//  //Assertion
//    assert(result == 0);
//    assert(num == 5);
//    result = pop(&num);
//    assert(num == 4);
//    assert(result == 0);
//    result = pop(&num);
//    assert(num == 3);
//    assert(result == 0);
//    result = pop(&num);
//    assert(num == 2);
//    assert(result == 0);
//    result = pop(&num);
//    assert(num == 1);
//    assert(result == 0);
//    result = pop(&num);
//    assert(result == 0);      //It should be erroring out here
//    assert(num == 0);
  
//  //Test case 4: push() one, pop() one and check empty stack
//  //Action   
//    result = push(1);     //push value into a stack
//  //Assertion
//    assert(result == 0);
//  
//  //Action
//    result = pop(&num);   //pop value out of a stack
//  //Assertion
//    assert(result == 0);
//    assert(num == 1);
//    result = pop(&num);
//    assert(result == 0);  //It should be erroring out here.
  
//  //Test case 5: push() to full stack, pop() one, push() one and check
//  //for full stack
//  //Action   
//    result = push(1);     //push value into a stack
//  //Assertion
//    assert(result == 0);
//    result = push(2);
//    assert(result == 0);
//    result = push(3);
//    assert(result == 0);
//    result = push(4);
//    assert(result == 0);
//    result = push(5);
//    assert(result == 0);
//  
//  //Action
//    result = pop(&num);   //pop value out of a stack
//  //Assertion
//    assert(result == 0);
//    assert(num == 5);
//  
//  result = push(6);
//  assert(result == 0);
//  result = push(7);
//  assert(result == 0);        //It should be erroring out here.
}
