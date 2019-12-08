//This delay function is a Millisecond delay function and it will take an 
//unsigned int as a parameter.

#include "stdint.h"

#ifndef _DELAY_H_
#define _DELAY_H_
void delay(uint32_t);
void sysTick_Init(void);
#endif