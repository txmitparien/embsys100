int counter = 0;

int main()
{
  //enabling the clock
  // RCC Base Address: 0x40023800
  //RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
  //Address offset: 0x30
  //Write: 0x1
  //1. Enable clock to Peripheral
  *((unsigned int*)0x40023830) = 0x1;
  
  //2.Set GPIO to Output
  *((unsigned int*)0x40020000) = 0xA8000400;
  
  //3.Write 1 or 0 to turn on/ off
  *((unsigned int*)0x40020014) = 0x20;
  
  return 0;
}



//GPIOA Base Address: 0x40020000
//GPIO port mode register (GPIOx_MODER) (x = A..E and H)
//Address offset: 0x00
//Write: 0x400



//GPIOA Base Address: 0x40020000
//GPIO port output data register (GPIOx_ODR) (x = A..E and H)
//Address offset: 0x14
//Reset value: 0x0000 0000
//write: 0x20



