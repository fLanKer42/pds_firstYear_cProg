#include <stdio.h>
int main()
{
  float C,F;// C is temperature in celsius, F is temperature in fahrenheit
  printf(" enter value of temperature in fahrenheit:  ");
  scanf("%f",&F);
  C = ((F-32.0)*(5.0/9.0));
  printf("\n the temperature in celsius is %f \n",C);
  return 0;
}
