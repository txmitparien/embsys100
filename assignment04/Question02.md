2.) 

a.) The calling function passes the values to the called function by save these values in the general-purpose registers.

b.) There is not extra code that compiler has generated.

c.) The extra code the compiler generated inside the called function with the multiple list of arguments was PUSH.W {R4-R8, LR}.
	This was done to save the original values of these registers.

d.) There is a need to pop out all the used registers after the operates were donoe. This is to clear the registers up and get it ready for the next arithmetic. 
