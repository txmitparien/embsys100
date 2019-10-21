Week2 Assignment

1.)	a.) The value of the “counter” from the “Locals” window is **0x80000000 (-2147483648)**.

	 b.) The value of the “counter” in the “Register” window is 0x80000000 (-2147483648).
    
	 c.) Negative (N) flag and Overflow (V) flag are set in the APSR. These flags were set because when we
	incremented the "counter" variable which is a signed integer with a value of 0x7FFFFFFF(2147483647), we
	turned this variable into a negative number and in doing so, we have flag the Overflow condition as well since.
    
2.)	a.) The value of “counter” in the *“Locals”* window changed to **0x00000000 (0)**.

	  b.) The APSR set Zero Condition (Z) flag and Carry Condition (C) flag.  
    
3.)	a.) The value of “counter” in the **“Locals”** window changed to **0x80000000 (2147483648)**.

	b.) Negative (N) flag and Overflow (V) flag are set in the APSR. Even through, the value is unsigned and the 
	variable "counter" incremented into positive number but I think the APSR still treats it as the signed number still
	and it only tracks the bit condition of some of the bits. 
    
4.)	a.) The value of “counter” in the **“Locals”** window changed to **0x00000000 (0)**.

	  b.) The APSR set Zero Condition (Z) flag and Carry Condition (C) flag. The reason why ASPR set these flags 
    are because the value has become zero and there is a bit carry over beyond these 2 nipples.
    
5.)	a.) The scope of the variable “counter” is now a **global variable**.

	  b.) No, it’s not visible in the “Locals” view anymore.
    
	  c.) In this class, the variable “counter” can be viewed in **both Auto or Static window**. 
    The difference is that the Statics window will only show the changes to the “counter” 
    variable only inside “main” module but Auto window will show you the changes to the “counter” beyond “main”.
    
	  d.) The address of the “counter” variable in memory is 0x20000000.
    
6.)	a.) The value of the “counter” is **4** at the end of the program.

	  b.) The counter value has changed because the “counter” variable is a global variable which has 
    an address of 0x20000000. We then created a pointer variable “p_int” which would point to address of 
    the “counter” variable and incremented the dereference value of that address 3 times. Lastly, we incremented 
    the “counter” one more time.
    
7.)	a.) The “counter” variable is stored at **0x20000000**.

	  b.) The “counter” variable is stored in RAM.  
    
	  c.)  The value of the “counter” is 4 at the end of the program.
