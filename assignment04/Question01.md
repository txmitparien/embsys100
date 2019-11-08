1. Using bit-band region for peripherals:

	a. Please see the mainBitBand.c
	 
	b.
  
    ![image](https://user-images.githubusercontent.com/56284484/68453941-dd2d7280-01ab-11ea-88a1-d4dd1b280106.png)

  
	c. 
  
      Turn-on
      
        0x8000062: 0x6005	STR	R5, [R0] 	 
      
      Turn-Off
      
	    0x8000074: 0x2301	MOVS	R3, #1
      
	    0x8000076: 0x6003	STR	R3, [R0]
