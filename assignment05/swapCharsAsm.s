//Thanit Mitparien
//This assembly code shall swap two different characters and returns 0 if those characters 
//are the same without swap operation. If two characters are the different, the code shall
//proceed with swap operation and returns 1 to the main program.

    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
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


swapCharsAsm 
        MOV R2, R0      //Move address store in R0 to R2
        LDRB R3, [R2]   //Load a byte worth of data found in R2 into register R3
        LDRB R4, [R1]   //Load a byte worth of data found in R1 into register R4
        
        CMP R3, R4      //Compare data between R3, R4
        BEQ eq          //If R3 = R4 then branch to eq label. If not, proceed on
        
        STR R3, [R1]    //Store data found in R3 into address found in R1
        STR R4, [R2]    //Store data found in R4 into address found in R2
        MOV R0, #1      //Set R0 = 1
        BX LR           //Branch back to the main function
        
eq                      //Label 
        MOV R0, #0      //Set R0 = 0
        BX LR           //Branch back to the main function
        
        END
        