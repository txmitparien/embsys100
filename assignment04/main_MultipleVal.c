
int average(void);
int sum(int, int, int, int, int);
int addTwo(int);

void main(void)
{
  int varNum = 0;
  //varNum = average();
  varNum = sum(5, 5, 5, 5, 6);
  //varNum = addTwo(5);
  (void)varNum;
}

int average(void){
  int aveNum = sum(5, 5, 5, 5, 6) / 5;
  return aveNum;
}

int sum(int var0, int var1, int var2, int var3, int var4){
  int lvar0;
  int lvar1;
  int lvar2;
  int lvar3;
  int lvar4;
  
  int sum;
  
  lvar0 = var0;
  lvar1 = var1;
  lvar2 = var2;
  lvar3 = var3;
  lvar4 = var4;
  
  sum = lvar0 + lvar1 + lvar2 + lvar3 + lvar4;
  
  return sum;
}

int addTwo(int vl){
  int add;
  add = vl + 2;
  return add;
}
