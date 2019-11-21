//Thanit Mitparien
//This program will include swap() function which will swap two numbers and
//their addresses.

void swap(int **, int **);

void main()
{
  int x = 200;
  int y = 100;
  
  int *xPtr = &x;
  int *yPtr = &y;
  
  swap(&xPtr, &yPtr);
}

void swap(int ** xPtr, int ** yPtr){
  int temp;
  
  temp = **xPtr;			//Swap value of x and y
  **xPtr = **yPtr;
  **yPtr = temp;
  
  int * tempPtr = *xPtr;	//Swap pointer of x and y
  *xPtr = *yPtr;
  *yPtr = tempPtr;
  
}
