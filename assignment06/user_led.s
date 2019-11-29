/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
Modified by     : Thanit Mitparien
*******************************************************************************/   

    EXTERN delay  // delay() is defined outside this file.

    PUBLIC control_user_led         // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led
Description     : - Uses Peripheral registers at base 0x4000.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

control_user_led
    
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    LDR R2, =0x40023830 //Set R2 = RCC Base Address
    MOV R3, #0x1        //Set R3 = 0x1
    STR R3, [R2]        //Store value found in R3 to address found in R2
    
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    LDR R2, =0x40020000 //Set R2 = GPIOA_MODER
    MOV R3, #0x400      //Set R3 = 0x400
    STR R3, [R2]        //Store value found in R3 to address found in R2
    
    CMP R0, #1          //Compare the state parameter
    BEQ OnState         //If it's equal to 1, then branch to On-State logic.
                        //Else, it will proceed to Off-State logic below.
OffState:               //Label(Off-state)
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
    LDR R2, =0x40020014 //Set R2 = GPIOA_ODR
    MOV R3, #0x00       //Set R3 = 0
    STR R3, [R2]        //Store value found in R3 to address found in R2
    
    MOV R0, R1          //Set R0 = duration parameter
    PUSH {LR}           //Save the input arguments as needed and LR
    BL delay            //Branch to delay function
    POP {LR}            //Restore Risgters and LR
    BX LR               //Return   
    
OnState:                //Label(On-State)
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    LDR R2, =0x40020014 //Set R2 = GPIOA_ODR
    MOV R3, #0x20       //Set R3 = 0
    STR R3, [R2]        //Store value found in R3 to address found in R2

    MOV R0, R1          //Set R0 = duration parameter
    PUSH {LR}           //Save the input arguments as needed and LR
    BL delay            //Branch to delay function
    POP {LR}            //Restore Risgters and LR
    BX LR               //Return  
    END
