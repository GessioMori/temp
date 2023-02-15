#include <stdio.h>

int main()
{
  int var1 = 10;
  int *var2 = &var1;
  int **var3 = &var2;

  printf("Value of var1: %d\n", var1);
  printf("Address of var1: %p\n", var2);
  printf("Address of pointer of var1: %p\n", var3);
  printf("Get the value of var1 from pointer: %d\n", *var2);
  printf("Get the value of var1 from pointer of pointer: %d\n", **var3);
  printf("Get the value of var2 from pointer: %p\n", *var3);

  return 0;
}