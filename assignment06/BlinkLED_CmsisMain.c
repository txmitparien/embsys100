#include "stm32f401xe.h"
#include "system_stm32f4xx.h"

//#define RCC_BASE 0x40023800
//#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))
//
//#define GPIOA_BASE 0x40020000
//#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
//#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
//
//#define GPIOA (1<<5)

volatile int counter=0;

void main(void)
{
    
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB1ENR |= 0x1;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    //GPIOA_MODER |= 0x400;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
    counter=0;

    while (counter < 1000000)
    {
      counter++;
    }
    //GPIOA_ODR |= GPIOA;
    GPIOA->ODR |= GPIO_ODR_OD5;
        
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    //GPIOA_ODR &= ~GPIOA;
    GPIOA->ODR &= ~GPIO_ODR_OD5;
    }
}
