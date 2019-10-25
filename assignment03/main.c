//This program will flash LED "Thanit" in MORSE code.
//The delay in this code will not be in seconds or minutes but instead 1 unit
//will be equaled to while loop count of 0 to 999999.

void HWint(void);               //This function will initialize the LD2.
void DelayMo(unsigned int);     //Delay function 1 unit equals 0-999999 count.
void Dot(void);                 //Turn on LED for 1 unit and off for 1 unit.
void Dash(void);                //Turn on LED for 3 units and off for 1 unit.

//Below are macros to turn on and off LED.
#define GPIOA_BASE 0x40020000
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define LED_ON (GPIOA_ODR = 0x20);
#define LED_OFF (GPIOA_ODR = 0x00);
 

int main(){

  HWint();

  while(1){

                Dash();      //Letter T
                DelayMo(2);  //Space between letters (**Only 2 units of Delay
                             //because there is already built-in space in Dash()
                                                               
                Dot();       //Letter H
                Dot();
                Dot();
                Dot();
                DelayMo(2);
               
                Dot();      //Letter A
                Dash();
                DelayMo(2);

                Dash();     //Letter N
                Dot();
                DelayMo(2);              

                Dot();     //Letter I
                Dot();
                DelayMo(2);
               
                Dash();    //Letter T
                
                DelayMo(6);//Space between Words
  }

  return 0;
}

 

void HWint(void){

  *((unsigned int*) 0x40023830) = 0x01; // Enable Clock to GPIOA
  *((unsigned int*) 0x40020000) = 0xA8000400; //Set GPIA to output
}


void DelayMo(unsigned int counter){

  unsigned int temp = 0;
  while(temp < (counter * 1000000)){
    temp++;
  }

}

 
void Dot(void){
                LED_ON;
                DelayMo(1);
                LED_OFF;
                DelayMo(1);
}

 

void Dash(void){

                LED_ON;
                DelayMo(3);
                LED_OFF;
                DelayMo(1);
}