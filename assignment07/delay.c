#include "stdint.h"
#include "delay.h"
#include "stm32f401xe.h"
#include "system_stm32f4xx.h"

extern uint32_t timeDelay;

#define SYS_CLOCK_HZ (1600000u/1000u)   //Clock frequency which equals to 1 ms.

void delay(uint32_t timeMS){
    sysTick_Init();                     //Initialize the sysTick Interrupt
    timeDelay = timeMS;                 //Set a global variable to user input
    while(timeDelay != 0);              //Busy wait until the specified dalay
                                        //time length is met.
}

void sysTick_Init(void){
    SysTick->LOAD = SYS_CLOCK_HZ - 1;                   //Counts to 0.
    SysTick->VAL = 0x0;                                 //Clears initial value
    SysTick->CTRL = 0x7;                                //Enable interrupts
  
}