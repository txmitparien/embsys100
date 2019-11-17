//Thanit Mitparien
//This program will be used to determine which memory endianness of
//the microcontroller is using.

#include <assert.h>
int endianTest(void);

char testChar[5] = "tests";
void main(void)
{
  int testNum;
  testNum = endianTest();
  assert(testNum == -2);        //Big Endian (Expect to error out here)
  assert(testNum == -1);        //Little Endian (Expecte error out here)
}

//This function will not accept any input parameter but shall return
//the following values depending on the endianness of the system:
// -1 for Big Endian
// -2 for Little Endian
// 0 for undetermine
int endianTest(void){
    int *trackPtr = (int *) testChar;
    int numTemp = trackPtr[0] - trackPtr[4];
  
    if( numTemp > 0){       //Big Endian
      return -1;
    }else if ( numTemp < 0){        //Little Endian
      return -2;
    }else{
      return 0;
    }
  
}
